#ifndef OTHELLOWINDOW_H
#define OTHELLOWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

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


public slots:// protocol jadid ro begir ke daram bara input: type game - > game name siganl miad in ja
    void prossesMessage(QJsonObject);


signals:
    void othelloFinished();
    void sendMessage(QJsonObject msg);


private:
    Ui::OthelloWindow *ui;
};

#endif // OTHELLOWINDOW_H
