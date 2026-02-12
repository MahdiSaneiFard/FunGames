#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "SmtpMime"
#include <random>
#include <QProgressDialog>
#include <QTimer>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include "loginwindow.h"
#include "GameClient.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->HostRadioButton, &QRadioButton::toggled, this, &MainWindow::onRoleChanged);
    connect(ui->guestRadioButton, &QRadioButton::toggled, this, &MainWindow::onRoleChanged);



    ui->createdGamesTableWidget->setColumnCount(3);
    ui->createdGamesTableWidget->setHorizontalHeaderLabels({"Game ID", "Color", "Time Limit"});
    ui->createdGamesTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->createdGamesTableWidget->verticalHeader()->setVisible(false);
    ui->createdGamesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->createdGamesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->createdGamesTableWidget->setStyleSheet("QTableWidget { font: 14px; }");



}

void MainWindow::onRoleChanged(bool checked)
{
    // فقط وقتی انتخاب شده است
    if (!checked) return;

    ui->stackedWidget->setEnabled(true);

    if (ui->HostRadioButton->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(0); // HostPanel
        ui->guestRadioButton->setEnabled(false);
        ui->stackedWidget->setEnabled(true);
    }
    else if (ui->guestRadioButton->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(1); // ClientPanel
        ui->HostRadioButton->setEnabled(false);
        ui->stackedWidget->setEnabled(true);
    }
}

MainWindow::~MainWindow()
{
    delete client;
    delete ui;
}
void MainWindow::setPlayer(std::unique_ptr<Player> p)
{
    currentPlayer = std::move(p);
    ui->Profile_name_line->setText(currentPlayer->getName());
    ui->Profile_username_line->setText(currentPlayer->getUserName());
    ui->Profile_Email_line->setText(currentPlayer->getEmail());
    ui->Profile_phone_line->setText(currentPlayer->getPhoneNumber());

    ui->Old_Pass_label->hide();
    ui->Old_pass_line->hide();
    ui->Code_email_line->hide();
    ui->email_code_label->hide();
    ui->Aply_btn->hide();
}

void MainWindow::sendVerificationEmail(QString userEmail)
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

void MainWindow::on_Change_btn_clicked()
{
    QString name = ui->Profile_name_line->text().trimmed();
    QString username = ui->Profile_username_line->text().trimmed();
    QString email = ui->Profile_Email_line->text().trimmed();
    QString Phone = ui->Profile_phone_line->text().trimmed();
    QString newPass = ui->Profile_pass_line->text().trimmed();

    if(username.isEmpty() || name.isEmpty() || email.isEmpty() || Phone.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "All fields must be filled!");
        return;
    }

    QRegularExpression emailRegex("^[\\w\\.]+@[\\w]+\\.[\\w]+$");
    QRegularExpressionMatch match = emailRegex.match(ui->Profile_Email_line->text().trimmed());

    if(!match.hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "Email is invalid!");
        return;
    }

    QRegularExpression phoneRegex("^\\d+$");
    QRegularExpressionMatch _match = phoneRegex.match(Phone);

    if(!_match.hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "Phone Number must be numeric!");
        return;
    }

    QSqlQuery checkQuery;
    if (username != currentPlayer->getUserName())
    {
        checkQuery.prepare("SELECT * FROM users WHERE username=?");
        checkQuery.addBindValue(username);

        if(!checkQuery.exec()) {
            QMessageBox::warning(this, "DB Error", checkQuery.lastError().text());
            return;
        }

        if(checkQuery.next()) {
            QString existingField = "Username";
            QMessageBox::warning(this, "ERROR", existingField + " already exists!");
            return;
        }
    }

    if (Phone != currentPlayer->getPhoneNumber())
    {
        checkQuery.prepare("SELECT * FROM users WHERE phone=?");
        checkQuery.addBindValue(Phone);

        if(!checkQuery.exec()) {
            QMessageBox::warning(this, "DB Error", checkQuery.lastError().text());
            return;
        }

        if(checkQuery.next()) {
            QString existingField = "Phone";
            QMessageBox::warning(this, "ERROR", existingField + " already exists!");
            return;
        }
    }

    if (email != currentPlayer->getEmail())
    {
        checkQuery.prepare("SELECT * FROM users WHERE email=?");
        checkQuery.addBindValue(email);

        if(!checkQuery.exec()) {
            QMessageBox::warning(this, "DB Error", checkQuery.lastError().text());
            return;
        }

        if(checkQuery.next()) {
            QString existingField = "email";
            QMessageBox::warning(this, "ERROR", existingField + " already exists!");
            return;
        }
    }

    if (username == currentPlayer->getUserName() && Phone == currentPlayer->getPhoneNumber() && email == currentPlayer->getEmail() && name == currentPlayer->getName() && newPass.isEmpty())
    {
        QMessageBox::warning(this, "ERROR", "Nothing chaged!");
        return;
    }

    sendVerificationEmail(email);

    ui->Old_Pass_label->show();
    ui->Old_pass_line->show();
    ui->Code_email_line->show();
    ui->email_code_label->show();
    ui->Aply_btn->show();

    ui->Profile_name_line->setEnabled(false);
    ui->Profile_username_line->setEnabled(false);
    ui->Profile_Email_line->setEnabled(false);
    ui->Profile_phone_line->setEnabled(false);
    ui->Profile_pass_line->setEnabled(false);
}

void MainWindow::on_Aply_btn_clicked()
{
    QString email_validation = ui->Code_email_line->text().trimmed();
    if (email_validation != std::to_string(this->generatedCode))
    {
        QMessageBox::warning(this, "ERROR", "Your email code is wrong");
        return;
    }

    QString oldPass = ui->Old_pass_line->text().trimmed();
    QString hashedPassword = LoginWindow::hashPassword(oldPass);
    if (hashedPassword != currentPlayer->getPassword())
    {
        QMessageBox::warning(this, "ERROR", "Your Password is wrong");
        return;
    }

    QString newName = ui->Profile_name_line->text().trimmed();
    QString newUsername = ui->Profile_username_line->text().trimmed();
    QString newEmail = ui->Profile_Email_line->text().trimmed();
    QString newPhone = ui->Profile_phone_line->text().trimmed();
    QString newPass = ui->Profile_pass_line->text().trimmed();

    hashedPassword = LoginWindow::hashPassword(newPass);

    QString oldUsername = currentPlayer->getUserName();

    QSqlQuery query;
    QString queryString;

    if (newPass.isEmpty()) {
        queryString = "UPDATE users SET name = :name, username = :new_user, email = :email, phone = :phone "
                      "WHERE username = :old_user";
    } else {
        queryString = "UPDATE users SET name = :name, username = :new_user, email = :email, phone = :phone, password = :pass "
                      "WHERE username = :old_user";
    }

    query.prepare(queryString);

    query.bindValue(":name", newName);
    query.bindValue(":new_user", newUsername);
    query.bindValue(":email", newEmail);
    query.bindValue(":phone", newPhone);
    query.bindValue(":old_user", oldUsername);

    if (!newPass.isEmpty()) {
        query.bindValue(":pass", hashedPassword);
    }

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            currentPlayer->setName(newName);
            currentPlayer->setUserName(newUsername);
            currentPlayer->setEmail(newEmail);
            currentPlayer->setPhoneNumber(newPhone);
            if (!newPass.isEmpty()) {
                currentPlayer->setPassword(hashedPassword);
            }

            QMessageBox::information(this, "Success", "Your Profile updated!");

            ui->Profile_name_line->setEnabled(true);
            ui->Profile_username_line->setEnabled(true);
            ui->Profile_Email_line->setEnabled(true);
            ui->Profile_phone_line->setEnabled(true);
            ui->Profile_pass_line->setEnabled(true);
            ui->Profile_pass_line->clear();

            ui->Old_Pass_label->hide();
            ui->Old_pass_line->hide();
            ui->Code_email_line->hide();
            ui->email_code_label->hide();
            ui->Aply_btn->hide();

            ui->Profile_name_line->setText(currentPlayer->getName());
            ui->Profile_username_line->setText(currentPlayer->getUserName());
            ui->Profile_Email_line->setText(currentPlayer->getEmail());
            ui->Profile_phone_line->setText(currentPlayer->getPhoneNumber());

        } else {
            QMessageBox::warning(this, "ERROR", "User not found or no changes made!");
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}
void MainWindow::onMessageReceived(QJsonObject msg)
{

}
void MainWindow::on_CreatePushButton_clicked()
{

}

void MainWindow::on_ConnectToHostPushButton_clicked()
{
    QString serverIP = ui->guestLineEdit->text().trimmed();
    if(serverIP.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter the server IP!");
        return;
    }

    quint16 serverPort = 12345;

    // فقط یک بار ساخته شود
    if (client)
    {
        delete client;
    }
    client = new GameClient(this);
        // ---- سیگنال‌ها ----
    client->connectToServer(serverIP, serverPort);

    connect(client, &GameClient::messageReceived, this, &MainWindow::onMessageReceived);
    connect(client, &GameClient::connected, this, [=]() {
        QMessageBox::information(this, "Connected", "Connected to server!");
        ui->guestRadioButton->setEnabled(true);
        ui->HostRadioButton->setEnabled(true);
    });

    connect(client, &GameClient::errorOccurred, this, [=](QString msg) {
        QMessageBox::critical(this, "Error", msg);
    });

}

void MainWindow::updateGamesTable(const QVector<GameOptions> &games)
{
    ui->activeMatchesTableWidget->setRowCount(0);

    for(int i = 0; i < games.size(); ++i) {
        const auto &opts = games[i];
        ui->activeMatchesTableWidget->insertRow(i);

        ui->activeMatchesTableWidget->setItem(i, 0, new QTableWidgetItem(opts.name));
        ui->activeMatchesTableWidget->setItem(i, 1, new QTableWidgetItem(opts.color));
        ui->activeMatchesTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(opts.timeLimit)));
    }
}


