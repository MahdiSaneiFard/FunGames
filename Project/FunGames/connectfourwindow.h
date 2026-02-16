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
signals:
    void timeIsUp();

private slots:
    void updateTimer();
    void onColumnClicked(int column);
private:
    QString color;      // "black" or "white"
    int matchTime;      // minutes
    int remainingSec;   // seconds
    QString turn = "black";

    QLabel* stickerDisplay;        // نمایش استیکر طرف مقابل
    QWidget* stickerPanel;         // پنل انتخاب استیکر
    QTimer* stickerTimer;          // تایمر حذف استیکر

    QLabel* timerLabel;
    QLabel* infoLabel;
    BoardWidget* board; // board->dropDisc(int column, const QString& color) bra endakhtan
    QTimer* gameTimer;

    void setupUI();
    void startTimer();
};

#endif // CONNECTFOURWINDOW_H
