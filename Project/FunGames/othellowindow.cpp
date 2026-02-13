#include "othellowindow.h"
#include "ui_othellowindow.h"

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
    emit gameFinished();
    this->close();
}

