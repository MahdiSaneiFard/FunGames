#include "othellowindow.h"
#include "ui_othellowindow.h"
#include <QJsonObject>
#include <QString>

OthelloWindow::OthelloWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OthelloWindow)
{
    ui->setupUi(this);
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
    /*
        type - > othello
        msgType - > move (hammon noe payam
        data - > valid


    */

    if(msgType == "")
    {

    }
}

// haji harja khasti payam befresti
//emit sendMessage(msg);
