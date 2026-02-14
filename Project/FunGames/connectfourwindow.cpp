#include "ConnectFourWindow.h"
#include "BoardWidget.h"

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

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
    setFixedSize(600, 700);

    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    // --- Top bar ---
    QWidget* topBar = new QWidget(central);
    QHBoxLayout* topLayout = new QHBoxLayout(topBar);

    infoLabel = new QLabel("You are: " + color, topBar);
    timerLabel = new QLabel("Time: --:--", topBar);

    topLayout->addWidget(infoLabel);
    topLayout->addStretch();
    topLayout->addWidget(timerLabel);

    // --- Board ---
    board = new BoardWidget(central);
    board->setFixedSize(560, 480);
    board->setPlayerColor(color);
    mainLayout->addWidget(topBar);
    mainLayout->addWidget(board, 0, Qt::AlignCenter);

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

    remainingSec--;
    if (remainingSec < 0)
    {
        gameTimer->stop();
        endGame();
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
        board->dropDisc(col, pColor); // آخرین مهره پیروز

        QString winner = msg["winner"].toString();
        QString resultText = (winner == color) ? "You Won! 🎉" : "You Lost! 🚩";
        if(winner == "draw") resultText = "It's a Draw! 🤝";

        QMessageBox::information(this, "Game Over", resultText);
        endGame();
    }
}

void ConnectFourWindow::endGame()
{
    emit conncetFourFinished();
    close();
}
