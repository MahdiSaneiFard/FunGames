#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QStandardPaths>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

#include "player.h"
#include "SmtpMime"
#include <random>
#include <QProgressDialog>
#include <QTimer>

#include <QIcon>


#include <QCryptographicHash>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{

    this->generatedCode = 0;
    ui->setupUi(this);

    setWindowIcon(QIcon(":/icons/resources/icons/icon.png"));
    setWindowTitle("Fun Game");


    ui->Validation_label->hide();
    ui->Validation_line->hide();
    ui->Validation_btn->hide();
    ui->tabWidget->removeTab(2);


    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir;
    if(!dir.exists(path))
        dir.mkpath(path);

    QString dbFile = path + "/users.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);

    if(!db.open()) {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "username TEXT UNIQUE,"
               "name TEXT,"
               "email TEXT UNIQUE,"
               "phone TEXT,"
               "password TEXT)");

    if(ui->passwordLineEditLogin) {
        ui->passwordLineEditLogin->setEchoMode(QLineEdit::Password);
        ui->passwordLineEditLogin->setStyleSheet("QLineEdit { lineedit-password-character: 42; }");
    }

    if(ui->passwordLineEditSignup) {
        ui->passwordLineEditSignup->setEchoMode(QLineEdit::Password);
        ui->passwordLineEditSignup->setStyleSheet("QLineEdit { lineedit-password-character: 42; }");
    }

    connect(ui->userNameLineEditLogin, &QLineEdit::returnPressed, ui->loginButton, &QPushButton::click);
    connect(ui->passwordLineEditLogin, &QLineEdit::returnPressed, ui->loginButton, &QPushButton::click);

    connect(ui->nameLineEditSignup, &QLineEdit::returnPressed, ui->signupButton, &QPushButton::click);
    connect(ui->userNameLineEditSignup, &QLineEdit::returnPressed, ui->signupButton, &QPushButton::click);
    connect(ui->passwordLineEditSignup, &QLineEdit::returnPressed, ui->signupButton, &QPushButton::click);
    connect(ui->emailLineEditSignup, &QLineEdit::returnPressed, ui->signupButton, &QPushButton::click);
    connect(ui->PhoneNumberLineEditSignup, &QLineEdit::returnPressed, ui->signupButton, &QPushButton::click);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index){
        if(index == 0) { // Login Tab
            ui->loginButton->setDefault(true);
            ui->signupButton->setDefault(false);
        } else { // Sign up Tab
            ui->signupButton->setDefault(true);
            ui->loginButton->setDefault(false);
        }
    });
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

QString LoginWindow::hashPassword(const QString &password)
{
    QByteArray hash = QCryptographicHash::hash(
        password.toUtf8(),
        QCryptographicHash::Sha256
        );
    return hash.toHex();
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->userNameLineEditLogin->text().trimmed();
    QString password = ui->passwordLineEditLogin->text().trimmed();
    QString hashedPassword = hashPassword(password);
    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "Username or Password missing!");
        return;
    }

    if(ui->userNameLineEditLogin->text().trimmed().isEmpty())
        QMessageBox::warning(this, "ERROR" , "you did not enter the UserName !");
    if(ui->passwordLineEditLogin->text().trimmed().isEmpty())
        QMessageBox::warning(this, "ERROR" , "you did not enter the password !");
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username=? AND password=?");
    query.addBindValue(username);
    query.addBindValue(hashedPassword);
    query.exec();

    if(query.next()) {
        QString name = query.value("name").toString();
        QString email = query.value("email").toString();
        QString phone = query.value("phone").toString();

        std::unique_ptr<Player> player = std::make_unique<Player>(name, username, email, phone, hashedPassword);

        MainWindow *menu = new MainWindow();
        menu->setPlayer(std::move(player));
        menu->show();

        this->close();
    } else {
        QMessageBox::warning(this, "ERROR", "Invalid credentials!");
    }

}


void LoginWindow::sendVerificationEmail(QString userEmail)
{
    QProgressDialog progress("Please wait...\nSending verification email", "", 0, 0, this);

    progress.setWindowModality(Qt::WindowModal);
    progress.setCancelButton(nullptr);

    progress.setWindowFlags(
        Qt::Dialog
        | Qt::CustomizeWindowHint
        | Qt::WindowTitleHint
        );

    progress.show();
    QApplication::processEvents();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100000, 999999);
    int code = dis(gen);

    // taeen host va port
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    MimeMessage message;
    // tanzim ferestandeh va girandeh
    EmailAddress sender("amidkhodaie84@gmail.com", "Fun_Games");
    message.setSender(sender);

    EmailAddress receiver(userEmail);
    message.addRecipient(receiver);

    message.setSubject("Verification Code");

    MimeText text;
    text.setText("Your 6-digit verification code is: " + QString::number(code));
    message.addPart(&text);

    // vasl shodan
    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";
        return;
    }

    // baraye login cardan az email man
    smtp.login("amidkhodaie84@gmail.com", "amwi uvdc tsyc sujx");
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "Failed to authenticate!";
        return;
    }

    // send email
    smtp.sendMail(message);
    if (smtp.waitForMailSent()) {
        qDebug() << "Email sent successfully! Code:" << code;
        this->generatedCode = code;
        QMessageBox::information(this, "Verification", "A code has been sent to your email.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to send verification email.");
    }

    smtp.quit();
}

void LoginWindow::on_signupButton_clicked()
{
    QString username = ui->userNameLineEditSignup->text().trimmed();
    QString password = ui->passwordLineEditSignup->text().trimmed();
    QString email = ui->emailLineEditSignup->text().trimmed();
    QString phoneNumber = ui->PhoneNumberLineEditSignup->text().trimmed();
    QString name = ui->nameLineEditSignup->text().trimmed();
    QString hashedPassword = hashPassword(password);

    if(username.isEmpty() || password.isEmpty() || email.isEmpty() || phoneNumber.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "All fields must be filled!");
        return;
    }

    if(username.isEmpty())
    {
        QMessageBox::warning(this, "ERROR" , "You did not enter the Username!");
        return;
    }


    if(password.isEmpty())
    {
        QMessageBox::warning(this, "ERROR" , "You did not enter the Password!");
        return;
    }

    if(email.isEmpty())
    {
        QMessageBox::warning(this, "ERROR" , "You did not enter the Email!");
        return;
    }


    QRegularExpression emailRegex("^[\\w\\.]+@[\\w]+\\.[\\w]+$");
    QRegularExpressionMatch match = emailRegex.match(ui->emailLineEditSignup->text().trimmed());

    if(!match.hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "Email is invalid!");
        return;
    }


    QString phone = ui->PhoneNumberLineEditSignup->text().trimmed();
    if(phone.isEmpty())
    {
        QMessageBox::warning(this, "ERROR" , "You did not enter the Phone Number!");
        return;
    }

    QRegularExpression phoneRegex("^\\d+$");
    QRegularExpressionMatch _match = phoneRegex.match(phone);

    if(!_match.hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "Phone Number must be numeric!");
        return;
    }

    sendVerificationEmail(email);

    ui->Validation_line->show();
    ui->Validation_label->show();
    ui->Validation_btn->show();

    //every things are valid brother hala :
}


void LoginWindow::on_Validation_btn_clicked()
{
    QString email_validation = ui->Validation_line->text();
    if (email_validation != std::to_string(this->generatedCode))
    {
        QMessageBox::warning(this, "ERROR", "Your email code is wrong");
        return;
    }
    else
    {
        QString username = ui->userNameLineEditSignup->text().trimmed();
        QString password = ui->passwordLineEditSignup->text().trimmed();
        QString email = ui->emailLineEditSignup->text().trimmed();
        QString phoneNumber = ui->PhoneNumberLineEditSignup->text().trimmed();
        QString name = ui->nameLineEditSignup->text().trimmed();
        QString hashedPassword = hashPassword(password);

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM users WHERE username=? OR email=? OR phone=?");
        checkQuery.addBindValue(username);
        checkQuery.addBindValue(email);
        checkQuery.addBindValue(phoneNumber);

        if(!checkQuery.exec()) {
            QMessageBox::warning(this, "DB Error", checkQuery.lastError().text());
            return;
        }

        if(checkQuery.next()) {
            QString existingField;
            if(checkQuery.value("username").toString() == username)
                existingField = "Username";
            else if(checkQuery.value("email").toString() == email)
                existingField = "Email";
            else if(checkQuery.value("phone").toString() == phoneNumber)
                existingField = "Phone Number";

            QMessageBox::warning(this, "ERROR", existingField + " already exists!");
            return;
        }
        //hala insert age balaha okay boodan :
        QSqlQuery query;
        query.prepare("INSERT INTO users (username, name, email, phone, password) VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(username);
        query.addBindValue(name);
        query.addBindValue(email);
        query.addBindValue(phoneNumber);
        query.addBindValue(hashedPassword);

        if(!query.exec()) {
            QMessageBox::warning(this, "ERROR", "DB error!");
            return;
        }

        QMessageBox::information(this, "Success", "User registered successfully!");
        ui->userNameLineEditSignup->clear();
        ui->passwordLineEditSignup->clear();
        ui->emailLineEditSignup->clear();
        ui->PhoneNumberLineEditSignup->clear();
        ui->nameLineEditSignup->clear();
        ui->tabWidget->removeTab(1);
        //ui->tabWidget->setCornerWidget(ui->LoginTab);
    }
}


void LoginWindow::on_Forgot_pass_btn_clicked()
{
    ui->tabWidget->insertTab(2, ui->tab, "Recover Password");

    ui->Forgot_code_line->hide();
    ui->Forgot_code_label->hide();
    ui->Change_pass_btn->hide();

    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
}


void LoginWindow::on_Recover_btn_clicked()
{
    QString username = ui->username_line->text();
    QString email = ui->email_line->text();
    QString pass = ui->New_pass_line->text();

    if(username.isEmpty() || pass.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "All fields must be filled!");
        return;
    }

    QRegularExpression emailRegex("^[\\w\\.]+@[\\w]+\\.[\\w]+$");
    QRegularExpressionMatch match = emailRegex.match(ui->email_line->text().trimmed());

    if(!match.hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "Email is invalid!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT email FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec()) {
        if (query.next()) {
            QString dbEmail = query.value(0).toString();
            if (dbEmail != email) {
                QMessageBox::warning(this, "ERROR", "The email entered does not match the email registered for this username!");
                return ;
            }
        } else {
            QMessageBox::warning(this, "ERROR", "Username not found!");
            return ;
        }
    } else {
        qDebug() << "Database Error: " << query.lastError().text();
    }

    sendVerificationEmail(email);

    ui->Forgot_code_line->show();
    ui->Forgot_code_label->show();
    ui->Change_pass_btn->show();
}


void LoginWindow::on_Change_pass_btn_clicked()
{
    QString email_validation = ui->Forgot_code_line->text();
    if (email_validation != std::to_string(this->generatedCode))
    {
        QMessageBox::warning(this, "ERROR", "Your email code is wrong");
        return;
    }

    QString username = ui->username_line->text();
    QString pass = ui->New_pass_line->text();

    QString hashedPassword = hashPassword(pass);

    QSqlQuery query;
    query.prepare("UPDATE users SET password = ? WHERE username = ?");
    query.addBindValue(hashedPassword);
    query.addBindValue(username);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "Success", "Password updated successfully!");

            ui->tabWidget->setCurrentIndex(0);

            ui->New_pass_line->clear();
            ui->Forgot_code_line->clear();
            ui->username_line->clear();
            ui->email_line->clear();

            ui->tabWidget->insertTab(0, ui->LoginTab, "Login");
            ui->tabWidget->insertTab(1, ui->SignUpTab, "Sign Up");
            ui->tabWidget->removeTab(2);
            ui->tabWidget->setCurrentIndex(0);
        } else {
            QMessageBox::warning(this, "Error", "User not found!");
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}


void LoginWindow::on_backToLoginButton_clicked()
{
    ui->email_line->clear();
    ui->New_pass_line->clear();
    ui->username_line->clear();
    ui->Forgot_code_line->clear();
    ui->tabWidget->insertTab(0, ui->LoginTab, "Login");
    ui->tabWidget->insertTab(1, ui->SignUpTab, "Sign Up");
    ui->tabWidget->removeTab(2);
    ui->tabWidget->setCurrentIndex(0);
}
