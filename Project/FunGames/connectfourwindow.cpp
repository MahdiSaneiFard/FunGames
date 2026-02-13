#include "connectfourwindow.h"
#include "ui_connectfourwindow.h"

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
