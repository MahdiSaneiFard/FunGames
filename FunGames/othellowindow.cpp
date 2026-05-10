#include "othellowindow.h"
#include "ui_othellowindow.h"
#include <QJsonObject>
#include <QString>
#include <QGridLayout>
#include <QMessageBox>

OthelloWindow::OthelloWindow(int time, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OthelloWindow)
{
    ui->setupUi(this);
    this->matchTime = time;
    this->remainingSec = time * 60;

    createBoard();
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &OthelloWindow::updateTimer);
    startTimer();
}

void OthelloWindow::startTimer()
{
    if (gameTimer) {
        updateTimer(); // برای اینکه از همان لحظه اول لیبل آپدیت شود
        gameTimer->start(1000); // هر ۱۰۰۰ میلی‌ثانیه (۱ ثانیه) یکبار تیک بزند
    }
}

void OthelloWindow::updateTimer()
{
    // ۱. تبدیل ثانیه کل به دقیقه و ثانیه (این‌ها int هستند)
    int min = remainingSec / 60;
    int sec = remainingSec % 60;

    // ۲. تبدیل اعداد به String با فرمت دو رقمی و ست کردن روی لیبل UI
    ui->timer->setText(
        QString("%1:%2")
            .arg(min, 2, 10, QChar('0')) // عدد اول، حداقل ۲ رقم، مبنای ۱۰، پر کردن با کاراکتر '0'
            .arg(sec, 2, 10, QChar('0'))
        );

    // ۳. منطق کم شدن زمان
    if(myColor == currentTurn) {
        remainingSec--;

        // قرمز کردن رنگ متن وقتی زمان کم است (مثلاً زیر ۱۰ ثانیه)
        if (remainingSec <= 10) {
            ui->timer->setStyleSheet("color: red; font-weight: bold;");
        }
    }

    // ۴. اتمام زمان
    if (remainingSec <= 0) {
        remainingSec = 0; // جلوگیری از منفی شدن
        gameTimer->stop(); // توقف تیک‌تاک تایمر

        // نمایش 00:00 روی صفحه
        ui->timer->setText("00:00");

        // ۴. اطلاع‌رسانی به سرور که زمان من تمام شده است
        QJsonObject timeoutMsg;
        timeoutMsg["type"] = "othello";
        timeoutMsg["msgType"] = "timesUp"; // سرور باید این نوع پیام را مدیریت کند
        timeoutMsg["player"] = myColor;     // اعلام اینکه زمان چه کسی تموم شده

        qDebug() << timeoutMsg;

        emit sendMessage(timeoutMsg);
    }
}

void OthelloWindow::createBoard() {
    // ۱. تنظیمات گرید برای چسبیدن خانه‌ها و ایجاد خطوط مشکی
    QGridLayout *gridLayout = new QGridLayout(ui->boardContainer);
    gridLayout->setSpacing(1); // ایجاد فاصله بسیار کم برای نمایش خطوط مشکی بین خانه‌ها
    gridLayout->setContentsMargins(0, 0, 0, 0);
    ui->boardContainer->setStyleSheet("background-color: #000000;"); // پس‌زمینه مشکی برای خطوط

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            boardButtons[r][c] = new QPushButton();
            boardButtons[r][c]->setFixedSize(60, 60);

            // استایل پایه: سبز تیره مشابه تصویر شما
            boardButtons[r][c]->setStyleSheet(
                "QPushButton {"
                "   background-color: #1a9277;" // رنگ سبز دقیق اتلو
                "   border: none;"
                "}"
                "QPushButton:hover {"
                "   background-color: #147a63;" // تغییر رنگ ملایم هنگام هاور
                "}"
                );

            connect(boardButtons[r][c], &QPushButton::clicked, [this, r, c]() {
                // ۱. فقط اگر نوبت من است اجازه کلیک دارم
                if (currentTurn != myColor) {
                    return;
                }

                // ۲. فقط در خانه‌ای که مهره ندارد (سبز است) می‌توان کلیک کرد
                // (فعلاً منطق پیچیده اتلو را فاکتور می‌گیریم و فقط جای خالی را چک می‌کنیم)
                if (boardButtons[r][c]->styleSheet().contains("radius:0.5")) {
                    return;
                }

                QJsonObject moveMsg;
                moveMsg["type"] = "othello";
                moveMsg["msgType"] = "move";
                moveMsg["row"] = r;
                moveMsg["col"] = c;
                moveMsg["color"] = myColor; // اعلام رنگی که حرکت را انجام داده

                emit sendMessage(moveMsg);
            });

            gridLayout->addWidget(boardButtons[r][c], r, c);
        }
    }

    // ۲. قرار دادن ۴ مهره مرکزی (شروع بازی)
    setupInitialPieces();
}

bool OthelloWindow::canMoveHere(int row, int col, QString color, const QJsonArray &boardArray) {
    // 1. بررسی خالی بودن خانه (در کلاینت 0 یعنی خالی)
    if (boardArray[row].toArray()[col].toInt() != 0) return false;

    int myVal = (color == "black") ? 1 : 2;
    int oppVal = (color == "black") ? 2 : 1;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        bool hasOpponentBetween = false;

        // حرکت در جهت i تا وقتی مهره حریف هست
        while (r >= 0 && r < 8 && c >= 0 && c < 8 && boardArray[r].toArray()[c].toInt() == oppVal) {
            r += dr[i];
            c += dc[i];
            hasOpponentBetween = true;
        }

        // اگر بعد از مهره‌های حریف، مهره خودمان بود، حرکت مجاز است
        if (hasOpponentBetween && r >= 0 && r < 8 && c >= 0 && c < 8) {
            if (boardArray[r].toArray()[c].toInt() == myVal) return true;
        }
    }
    return false;
}

void OthelloWindow::setupInitialPieces() {
    // طبق تصویر: (3,3) سفید، (3,4) سیاه، (4,3) سیاه، (4,4) سفید
    updateButtonToPiece(3, 3, "white");
    updateButtonToPiece(4, 4, "white");
    updateButtonToPiece(3, 4, "black");
    updateButtonToPiece(4, 3, "black");
}

// تابع کمکی برای نقاشی مهره‌های دایره‌ای
void OthelloWindow::updateButtonToPiece(int r, int c, QString color) {
    QString style = "background-color: #1a9277; border: none; padding: 5px;";
    if (color == "white") {
        style += "border-radius: 30px; background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 white, stop:1 #e0e0e0); border: 2px solid #b0b0b0;";
    } else if (color == "black") {
        style += "border-radius: 30px; background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 #333, stop:1 black); border: 2px solid #111;";
    }

    // نکته: برای دایره ماندن، دکمه باید مربع باشد و radius نصف اندازه آن باشد
    boardButtons[r][c]->setStyleSheet("QPushButton {" + style + "}");
}

void OthelloWindow::setPlayerColor(QString color) {
    this->myColor = color;
    // برای راهنمایی بازیکن، در تایتل پنجره بنویس چه رنگی است
    this->setWindowTitle("Othello - You are " + color);
}

OthelloWindow::~OthelloWindow()
{
    delete ui;
}
void OthelloWindow::endGame()
{
    emit othelloFinished();
    this->close();
}

void OthelloWindow::prossesMessage(QJsonObject msg)
{
    /*QString msgType = msg["msgType"].toString();
    /*
        type - > othello
        msgType - > move (hammon noe payam
        data - > valid


    */
    /*
    if(msgType == "")
    {

    }*/
    qDebug() << msg;
    QString msgType = msg["msgType"].toString();

    if (msg["type"].toString() == "othello")
    {
        if (msgType == "update_board") {
            if (!msg.contains("board")) return; // ایمنی در برابر پیام‌های ناقص

            qDebug() << msg;

            QJsonArray boardArray = msg["board"].toArray();
            currentTurn = msg["currentPlayer"].toString();

            for (int r = 0; r < 8; ++r) {
                QJsonArray rowArray = boardArray[r].toArray();
                for (int c = 0; c < 8; ++c) {
                    int cellValue = rowArray[c].toInt();

                    if (cellValue == 1) {
                        updateButtonToPiece(r, c, "black");
                    } else if (cellValue == 2) {
                        updateButtonToPiece(r, c, "white");
                    } else {
                        // خانه فعلاً از نظر سرور خالی است (0)
                        // حالا کلاینت خودش چک می‌کند که آیا اینجا "پیشنهادی" هست یا نه
                        if (currentTurn == myColor && canMoveHere(r, c, myColor, boardArray)) {
                            // نمایش راهنمای حرکت
                            boardButtons[r][c]->setStyleSheet("background-color: #2ecc71; border: 1px solid white;");
                        } else {
                            // خانه کاملاً خالی و بدون حرکت مجاز
                            boardButtons[r][c]->setStyleSheet(
                                "QPushButton { background-color: #1a9277; border: none; }"
                                "QPushButton:hover { background-color: #147a63; }"
                                );
                        }
                    }
                }
            }

            ui->label_3->setText(QString::number(msg["blackScore"].toInt()));
            ui->white_score->setText(QString::number(msg["whiteScore"].toInt()));

            // نمایش وضعیت نوبت و رنگ بازیکن به صورت همزمان
            QString status = (currentTurn == myColor) ? "YOUR TURN!" : "Waiting for opponent...";
            this->setWindowTitle(QString("Othello [%1] - %2").arg(myColor.toUpper()).arg(status));
        }
        else if (msgType == "endgane" || msgType == "endtime")
        {
            // ۱. متوقف کردن تایمر کلاینت برای جلوگیری از تیک زدن اضافی
            if (gameTimer) gameTimer->stop();

            qDebug() << "Game Ended. Type:" << msgType << msg;

            // ۲. بروزرسانی نهایی بورد (اگر بورد در پیام فرستاده شده باشد)
            if (msg.contains("board")) {
                QJsonArray boardArray = msg["board"].toArray();
                for (int r = 0; r < 8; ++r) {
                    QJsonArray rowArray = boardArray[r].toArray();
                    for (int c = 0; c < 8; ++c) {
                        int cellValue = rowArray[c].toInt();
                        if (cellValue == 1) updateButtonToPiece(r, c, "black");
                        else if (cellValue == 2) updateButtonToPiece(r, c, "white");
                    }
                }
            }

            // ۳. استخراج اطلاعات برنده و امتیازها
            QString winner = msg["winner"].toString();
            int bScore = msg["blackScore"].toInt();
            int wScore = msg["whiteScore"].toInt();
            QString resultText;

            // ۴. شخصی‌سازی متن پیام بر اساس نوع پایان بازی
            QString reasonText = "";
            if (msgType == "endtime") {
                QString loserColor = msg["color"].toString();
                reasonText = (loserColor == myColor) ? "Your time ran out! ⌛\n" : "Opponent's time ran out! ⌛\n";
            }

            // ۵. تعیین متن وضعیت برد/باخت
            if (winner == "draw") {
                resultText = reasonText + QString("The game is a Draw! 🤝\nBlack: %1 - White: %2").arg(bScore).arg(wScore);
            } else {
                QString winStatus = (winner == myColor) ? "Victory! 🎉" : "Defeat! 🚩";
                resultText = reasonText + QString("%1\nWinner: %2\n\nFinal Scores:\nBlack: %3 | White: %4")
                                              .arg(winStatus).arg(winner.toUpper()).arg(bScore).arg(wScore);
            }

            // ۶. نمایش مسیج باکس و بستن پنجره
            QMessageBox::information(this, "Game Over", resultText);
            endGame();
        }
    }
}

// haji harja khasti payam befresti
//emit sendMessage(msg);
