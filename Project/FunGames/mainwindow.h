#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "GameOptions.h"
#include "player.h"

#include <QJsonObject>
class GameServer; // forward declaration
class GameClient;


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void OthelloMSG(QJsonObject msg);
    void ConnectFourMSG(QJsonObject msg);
    void CheckersMSG(QJsonObject msg);//?

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setPlayer(std::unique_ptr<Player> p);
private slots:
    void on_Change_btn_clicked();

    void on_Aply_btn_clicked();

    void sendGameMessage(QJsonObject msg);

    void on_CreatePushButton_clicked();

    void on_ConnectToHostPushButton_clicked();

    void updateGamesTable(const QVector<GameOptions> &games);

    void onMessageReceived(QJsonObject msg);

    void on_guestRadioButton_clicked();

    void on_HostRadioButton_clicked();

    void on_JoinPushButton_clicked();

private:
    Ui::MainWindow *ui;

    GameClient* client;
    QString connectedServerIP;
    quint16 connectedServerPort = 0;
    bool isConnectedToServer = false;

    void sendVerificationEmail(QString userEmail);
    int generatedCode;
    std::unique_ptr<Player> currentPlayer;
    void onRoleChanged(bool checked);
};
#endif // MAINWINDOW_H
