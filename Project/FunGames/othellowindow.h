#ifndef OTHELLOWINDOW_H
#define OTHELLOWINDOW_H

#include <QMainWindow>

namespace Ui {
class OthelloWindow;
}

class OthelloWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OthelloWindow(QWidget *parent = nullptr);
    void endGame();
    ~OthelloWindow();


private slots:// protocol jadid ro begir ke daram bara input: type game - > game name siganl miad in ja
//


signals:
    void gameFinished();

private:
    Ui::OthelloWindow *ui;
};

#endif // OTHELLOWINDOW_H
