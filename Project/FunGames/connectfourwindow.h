#ifndef CONNECTFOURWINDOW_H
#define CONNECTFOURWINDOW_H

#include <QMainWindow>

namespace Ui {
class ConnectFourWindow;
}

class ConnectFourWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectFourWindow(QWidget *parent = nullptr);
    ~ConnectFourWindow();

private:
    Ui::ConnectFourWindow *ui;
};

#endif // CONNECTFOURWINDOW_H
