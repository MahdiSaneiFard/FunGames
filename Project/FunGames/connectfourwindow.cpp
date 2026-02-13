#include "connectfourwindow.h"
#include "ui_connectfourwindow.h"
#include <QJsonObject>

ConnectFourWindow::ConnectFourWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConnectFourWindow)
{
    ui->setupUi(this);
}

ConnectFourWindow::~ConnectFourWindow()
{
    delete ui;
}
void ConnectFourWindow::endGame()
{
    emit conncetFourFinished();
    this->close();
}

void ConnectFourWindow::prossesMessage(QJsonObject msg)
{
    QString msgType = msg["msgType"].toString();

    if(msgType == "")
    {

    }
}

//haji harja khasti payam befresti
//emit sendMessage(msg);
