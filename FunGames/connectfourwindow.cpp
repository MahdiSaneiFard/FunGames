#include "ConnectFourWindow.h"
#include "BoardWidget.h"

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

ConnectFourWindow::ConnectFourWindow(int time, QString Collor, QWidget *parent)
    : QMainWindow(parent),
    color(Collor),
    matchTime(time)
{
    setupUI();
    startTimer();
    connect(board, &BoardWidget::columnClicked,
            this, &ConnectFourWindow::onColumnClicked);
}

ConnectFourWindow::~ConnectFourWindow() {}
void ConnectFourWindow::setupUI()
{
    setWindowTitle("Connect Four");
    setFixedSize(700, 700);

    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    // ================= TOP BAR =================
    QWidget* topBar = new QWidget(central);
    QHBoxLayout* topLayout = new QHBoxLayout(topBar);

    infoLabel = new QLabel("You are: " + color, topBar);
    timerLabel = new QLabel("Time: --:--", topBar);

    topLayout->addWidget(infoLabel);
    topLayout->addStretch();
    topLayout->addWidget(timerLabel);

    mainLayout->addWidget(topBar);

    // ================= STICKER DISPLAY =================
    stickerDisplay = new QLabel(central);
    stickerDisplay->setFixedSize(120, 120);
    stickerDisplay->setAlignment(Qt::AlignCenter);
    stickerDisplay->setStyleSheet(
        "border: 2px dashed gray;"
        "font-size: 46px;"
        "background: transparent;"
        );
    stickerDisplay->hide();

    mainLayout->addWidget(stickerDisplay, 0, Qt::AlignCenter);

    // ================= BOARD =================
    board = new BoardWidget(central);
    board->setFixedSize(560, 480);
    board->setPlayerColor(color);

    // ================= STICKER PANEL =================
    stickerPanel = new QWidget(central);
    stickerPanel->setFixedWidth(90);

    QVBoxLayout* stickerLayout = new QVBoxLayout(stickerPanel);
    stickerLayout->setAlignment(Qt::AlignTop);

    QPushButton* stickerSmile       = new QPushButton("😀", stickerPanel);
    QPushButton* stickerFire        = new QPushButton("🔥", stickerPanel);
    QPushButton* stickerHeart       = new QPushButton("❤️", stickerPanel);
    QPushButton* stickerCelebration = new QPushButton("🎉", stickerPanel);

    QList<QPushButton*> stickers = {
        stickerSmile,
        stickerFire,
        stickerHeart,
        stickerCelebration
    };

    for (auto btn : stickers) {
        btn->setFixedSize(60, 60);
        btn->setStyleSheet("font-size: 26px;");
        stickerLayout->addWidget(btn);
    }

    stickerLayout->addStretch();

    // ================= BOARD + SPACE + STICKER PANEL =================
    QHBoxLayout* middleLayout = new QHBoxLayout();
    middleLayout->addWidget(board);
    middleLayout->addSpacing(40);   // حدود ۱ سانت
    middleLayout->addWidget(stickerPanel);

    mainLayout->addLayout(middleLayout);

    // ================= STICKER TIMER =================
    stickerTimer = new QTimer(this);
    stickerTimer->setSingleShot(true);

    connect(stickerTimer, &QTimer::timeout, this, [=]() {
        stickerDisplay->clear();
        stickerDisplay->hide();
    });

    // ================= STICKER SEND =================
    connect(stickerSmile, &QPushButton::clicked, this, [=]() {
        QJsonObject msg;
        msg["type"] = "connectFour";
        msg["msgType"] = "sticker";
        msg["sticker"] = "smile";
        emit sendMessage(msg);
    });

    connect(stickerFire, &QPushButton::clicked, this, [=]() {
        QJsonObject msg;
        msg["type"] = "connectFour";
        msg["msgType"] = "sticker";
        msg["sticker"] = "fire";
        emit sendMessage(msg);
    });

    connect(stickerHeart, &QPushButton::clicked, this, [=]() {
        QJsonObject msg;
        msg["type"] = "connectFour";
        msg["msgType"] = "sticker";
        msg["sticker"] = "heart";
        emit sendMessage(msg);
    });

    connect(stickerCelebration, &QPushButton::clicked, this, [=]() {
        QJsonObject msg;
        msg["type"] = "connectFour";
        msg["msgType"] = "sticker";
        msg["sticker"] = "celebration";
        emit sendMessage(msg);
    });
}


void ConnectFourWindow::onColumnClicked(int column)
{
    if(turn != color)
        return;

    // پیام به سرور
    QJsonObject msg;
    msg["type"] = "connectFour";
    msg["msgType"] = "move";
    msg["column"] = column;
    msg["color"] = color;

    qDebug() << msg;

    emit sendMessage(msg);


    // تغییر نوبت (یا منتظر پاسخ سرور)
}


void ConnectFourWindow::startTimer()
{
    remainingSec = matchTime * 60;

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout,
            this, &ConnectFourWindow::updateTimer);

    updateTimer();
    gameTimer->start(1000);
}

void ConnectFourWindow::updateTimer()
{
    int min = remainingSec / 60;
    int sec = remainingSec % 60;

    timerLabel->setText(
        QString("Time: %1:%2")
            .arg(min, 2, 10, QChar('0'))
            .arg(sec, 2, 10, QChar('0'))
        );
    if(color == turn)
        remainingSec--;
    if (remainingSec < 0)
    {
        QJsonObject msg;
        msg["type"] = "connectFour";
        msg["msgType"] = "timesUp";
        msg["color"] = color;
        gameTimer->stop();
        emit sendMessage(msg);
    }

}

void ConnectFourWindow::prossesMessage(QJsonObject msg)
{
    QString msgType = msg["msgType"].toString();

    qDebug() << msg << "update client";

    if (msgType == "update") {
        qDebug() << msg << "update client2";
        int col = msg["column"].toInt();
        QString pColor = msg["color"].toString();

        // حالا که سرور تایید کرده، مهره را می‌اندازیم
        board->dropDisc(col, pColor);

        // آپدیت نوبت برای حرکت بعدی
        turn = msg["nextTurn"].toString();
        infoLabel->setText(QString("You are %1 | Turn: %2")
                               .arg(color)
                               .arg(turn == color ? "YOUR TURN" : "Opponent's Turn"));
    }
    else if (msgType == "game_over") {
        int col = msg["column"].toInt();
        QString pColor = msg["color"].toString();
        if(col != 1000)
            board->dropDisc(col, pColor); // آخرین مهره پیروز

        QString winner = msg["winner"].toString();
        QString resultText = (winner == color) ? "You Won! 🎉" : "You Lost! 🚩";
        if(winner == "draw") resultText = "It's a Draw! 🤝";

        QMessageBox::information(this, "Game Over", resultText);
        endGame();
    }
    else if (msgType == "sticker")
    {
        QString sticker = msg["sticker"].toString();

        // --- Anti-spam: تایمر قبلی رو متوقف کن ---
        stickerTimer->stop();

        // --- انتخاب استیکر ---
        if (sticker == "smile")
            stickerDisplay->setText("😀");
        else if (sticker == "fire")
            stickerDisplay->setText("🔥");
        else if (sticker == "heart")
            stickerDisplay->setText("❤️");
        else if (sticker == "celebration")
            stickerDisplay->setText("🎉");
        else
            return;

        // --- نمایش ---
        stickerDisplay->show();

        // --- حذف خودکار بعد از ۳ ثانیه ---
        stickerTimer->start(3000);
    }


}

void ConnectFourWindow::endGame()
{
    emit conncetFourFinished();

}
