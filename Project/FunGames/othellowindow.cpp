#include "othellowindow.h"
#include "ui_othellowindow.h"
#include <QJsonObject>
#include <QString>
#include <QGridLayout>

OthelloWindow::OthelloWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OthelloWindow)
{
    ui->setupUi(this);
    createBoard();
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
        else if (msgType == "endgane")
        {
            if (!msg.contains("board")) return; // ایمنی در برابر پیام‌های ناقص

            qDebug() << msg;

            QJsonArray boardArray = msg["board"].toArray();
            currentTurn = msg["currentPlayer"].toString();

            for (int r = 0; r < 8; ++r) {
                QJsonArray rowArray = boardArray[r].toArray();
                for (int c = 0; c < 8; ++c) {
                    int cellValue = rowArray[c].toInt();

                    // 0: Empty, 1: Black, 2: White (مطابق منطق سرور)
                    if (cellValue == 1) {
                        updateButtonToPiece(r, c, "black");
                    } else if (cellValue == 2) {
                        updateButtonToPiece(r, c, "white");
                    } else {
                        // ریست کردن استایل برای خانه‌های خالی
                        boardButtons[r][c]->setStyleSheet(
                            "QPushButton { background-color: #1a9277; border: none; }"
                            "QPushButton:hover { background-color: #147a63; }"
                            );
                    }
                }
            }

            QString status = (msg["winner"] == myColor) ? "You Win!" : "You Lose!";
            status = (msg["winner"] == "draw") ? "Draw" : status;
            this->setWindowTitle(QString("Othello [%1] - %2").arg(myColor.toUpper()).arg(status));
        }
    }
}

// haji harja khasti payam befresti
//emit sendMessage(msg);
