#ifndef OTHELLOWINDOW_H
#define OTHELLOWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QPushButton>
#include <QJsonArray>

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
};

#endif // OTHELLOWINDOW_H
