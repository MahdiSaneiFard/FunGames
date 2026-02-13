#pragma once
#include <QObject>
#include <QTcpServer>
#include "Client.h"
#include "othellogame.h"

class Server : public QObject
{
    Q_OBJECT
    OthelloGame* activeGame = nullptr;
    void handleClientMessage(Client* sender, QJsonObject msg);
public:
    explicit Server(QObject *parent = nullptr);
    bool start(quint16 port);

    Client* client1 = nullptr;
    Client* client2 = nullptr;

private slots:
    void onNewConnection();

private:


    QTcpServer *tcpServer;
};
