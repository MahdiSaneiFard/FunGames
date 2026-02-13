#include "OthelloWindow.h"
#include "ui_OthelloWindow.h"
#include <QDebug>
#include <QPropertyAnimation>

OthelloWindow::OthelloWindow(int time, QString Collor, QWidget *parent) :
    QMainWindow(parent),
    color(Collor),
    matchTime(time),
    ui(new Ui::OthelloWindow)
{
    ui->setupUi(this);
    createBoard();
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
    QString msgType = msg["msgType"].toString();

    //chat اینجا پیام‌های سرور بررسی می‌شن
    if(msgType == "move")
    {
        //row col
    }
}

void OthelloWindow::createBoard()
{
    if (central) delete central; //chat: پاک کردن قبلی اگر بود
    central = new QWidget(this);
    setCentralWidget(central);

    if (grid) delete grid;
    grid = new QGridLayout(central);
    grid->setSpacing(2);

    board.clear();
    board.resize(boardSize);

    for(int row = 0; row < boardSize; ++row)
    {
        board[row].resize(boardSize);
        for(int col = 0; col < boardSize; ++col)
        {
            QPushButton *btn = new QPushButton(central);
            btn->setFixedSize(cellSize, cellSize);

            // تنظیم زمین
            btn->setStyleSheet("background-color: #8B4513; border: 1px solid black;"); //chat: رنگ قهوه ای زمین

            // قرار دادن مهره‌ها در حالت شروع اوتلو
            if((row == 3 && col == 3) || (row == 4 && col == 4))
            {
                QString img = (color == "white") ? ":/pices/resources/pices/whiteP.png" : ":/pices/resources/pices/blackP.png"; // مهره خود بازیکن
                btn->setIcon(QIcon(img));
                btn->setIconSize(QSize(cellSize - 10, cellSize - 10));
            }
            else if((row == 3 && col == 4) || (row == 4 && col == 3))
            {
                QString img = (color == "white") ? ":/pices/resources/pices/blackP.png" : ":/pices/resources/pices/whiteP.png"; // مهره حریف
                btn->setIcon(QIcon(img));
                btn->setIconSize(QSize(cellSize - 10, cellSize - 10));
            }
            else
            {
                btn->setIcon(QIcon()); // خانه خالی
            }

            connect(btn, &QPushButton::clicked, this, &OthelloWindow::cellClicked); //chat: کانکت دکمه
            grid->addWidget(btn, row, col);
            board[row][col] = btn;
        }
    }
}

void OthelloWindow::cellClicked()
{
    // دریافت دکمه‌ای که کلیک شده
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    // پیدا کردن مختصات دکمه در برد
    int row = -1, col = -1;
    for (int r = 0; r < boardSize; ++r)
    {
        for (int c = 0; c < boardSize; ++c)
        {
            if (board[r][c] == btn)
            {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) break;
    }

    if (row == -1 || col == -1) return; // ایمنی

    // افکت چرخش / کوچک شدن قبل از گذاشتن مهره
    animateFlip(btn);

    // تغییر تصویر دکمه بر اساس رنگ بازیکن
    QString imgPath;
    if (color.toLower() == "black")
        imgPath = ":/pices/resources/pices/blackP.png"; //chat: مسیر ریسورس مهره مشکی
    else
        imgPath = ":/pices/resources/pices/whiteP.png"; //chat: مسیر ریسورس مهره سفید

    QIcon icon(imgPath);
    btn->setIcon(icon);
    btn->setIconSize(QSize(cellSize - 10, cellSize - 10)); // کمی کوچکتر از خانه

    // ارسال حرکت به سرور
    QJsonObject msg;
    msg["type"] = "othello";
    msg["msgType"] = "move";
    msg["row"] = row;
    msg["col"] = col;

    emit sendMessage(msg);
}
void OthelloWindow::animateFlip(QPushButton *btn)
{
    if (!btn) return;

    int w = btn->width();
    int h = btn->height();

    // کوچک شدن دکمه
    QPropertyAnimation *shrink = new QPropertyAnimation(btn, "geometry");
    QRect startRect = btn->geometry();
    QRect endRect(startRect.center().x() - w/4, startRect.center().y() - h/4, w/2, h/2);
    shrink->setDuration(150);
    shrink->setStartValue(startRect);
    shrink->setEndValue(endRect);

    // بزرگ شدن دکمه
    QPropertyAnimation *expand = new QPropertyAnimation(btn, "geometry");
    expand->setDuration(150);
    expand->setStartValue(endRect);
    expand->setEndValue(startRect);

    // chat: وقتی shrink تموم شد، expand شروع می‌شه
    connect(shrink, &QPropertyAnimation::finished, [expand]() {
        expand->start(QAbstractAnimation::DeleteWhenStopped);
    });

    // شروع انیمیشن کوچک شدن
    shrink->start(QAbstractAnimation::DeleteWhenStopped);
}
///

///

///


///
