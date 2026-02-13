#ifndef CONNECTFOURWINDOW_H
#define CONNECTFOURWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

namespace Ui {
class ConnectFourWindow;
}

class ConnectFourWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectFourWindow(int time,QString Collor ,QWidget *parent = nullptr);
    QString color;
    int matchTime;

    ~ConnectFourWindow();
    void endGame();


public slots:// protocol jadid ro begir ke daram bara input: type game - > game name siganl miad in ja
    void prossesMessage(QJsonObject);


signals:
    void conncetFourFinished();
    void sendMessage(QJsonObject msg);


private:
    Ui::ConnectFourWindow *ui;
};

#endif // CONNECTFOURWINDOW_H
