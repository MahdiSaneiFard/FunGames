#ifndef OTHELLOWINDOW_H
#define OTHELLOWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QPushButton>
#include <QJsonArray>
#include <QTimer>  // اضافه شد
#include <QLabel>

namespace Ui {
class OthelloWindow;
}

class OthelloWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OthelloWindow(int time, QWidget *parent = nullptr);
    void endGame();
    ~OthelloWindow();
    void setPlayerColor(QString color);


public slots:// protocol jadid ro begir ke daram bara input: type game - > game name siganl miad in ja
    void prossesMessage(QJsonObject);


signals:
    void othelloFinished();
    void sendMessage(QJsonObject msg);


private:
    Ui::OthelloWindow *ui;
    QPushButton* boardButtons[8][8];
    QString myColor;
    QString currentTurn = "black";
    void createBoard();
    void setupInitialPieces();
    void updateButtonToPiece(int r, int c, QString color);
    bool canMoveHere(int row, int col, QString color, const QJsonArray &boardArray);

    QTimer *gameTimer;
    int remainingSec;
    int matchTime; // زمان کل بر حسب دقیقه
    QLabel *timerLabel;

    void startTimer();
    void updateTimer();
};

#endif // OTHELLOWINDOW_H
