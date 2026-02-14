#include "ConnectFourWindow.h"
#include "BoardWidget.h"

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>

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
    // اگر نوبت من نیست، هیچی نکن
    if(turn != color)
        return;

    // حرکت خودم
    board->dropDisc(column, color);

    // پیام به سرور
    QJsonObject msg;
    msg["type"] = "connectFour";
    msg["msgType"] = "move";
    msg["column"] = column;
    msg["color"] = color;

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
    QString type = msg["msgType"].toString();

    if (type == "move")
    {
        int col = msg["column"].toInt();
        QString playerColor = msg["color"].toString(); // black / white
        board->dropDisc(col, playerColor);
    }
    else if (type == "end")
    {
        endGame();
    }
}

void ConnectFourWindow::endGame()
{
    emit conncetFourFinished();
    close();
}
