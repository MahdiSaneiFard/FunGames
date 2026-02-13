#ifndef OTHELLOWINDOW_H
#define OTHELLOWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>

namespace Ui {
class OthelloWindow;
}

class OthelloWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OthelloWindow(int time,QString Collor ,QWidget *parent = nullptr);
    QString color;
    int matchTime;

    void endGame();
    ~OthelloWindow();



public slots:// protocol jadid ro begir ke daram bara input: type game - > game name siganl miad in ja
    void prossesMessage(QJsonObject);

signals:
    void othelloFinished();
    void sendMessage(QJsonObject msg);
private slots:
    void cellClicked();

private:

    QWidget *central = nullptr;       // صفحه اصلی
    QGridLayout *grid = nullptr;      // گرید زمین بازی
    QVector<QVector<QPushButton*>> board; // ماتریس دکمه‌ها

    Ui::OthelloWindow *ui;
    int boardSize = 8;  // اندازه صفحه
    int cellSize = 70;  // اندازه هر خانه

    void createBoard();
    void animateFlip(QPushButton *btn);

};

#endif // OTHELLOWINDOW_H
