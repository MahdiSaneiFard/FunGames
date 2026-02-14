#ifndef CONNECTFOURWINDOW_H
#define CONNECTFOURWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

class QLabel;
class QTimer;
class BoardWidget;

class ConnectFourWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectFourWindow(int time, QString Collor, QWidget *parent = nullptr);
    ~ConnectFourWindow();

    void endGame();

signals:
    void conncetFourFinished();
    void sendMessage(QJsonObject msg);

public slots:
    void prossesMessage(QJsonObject msg);

private slots:
    void updateTimer();

private:
    QString color;      // "black" or "white"
    int matchTime;      // minutes
    int remainingSec;   // seconds

    QLabel* timerLabel;
    QLabel* infoLabel;
    BoardWidget* board;
    QTimer* gameTimer;

    void setupUI();
    void startTimer();
};

#endif // CONNECTFOURWINDOW_H
