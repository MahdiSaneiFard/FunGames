#pragma once
#include <QObject>
#include <QTcpServer>
#include "Client.h"
class Server : public QObject
{
    Q_OBJECT
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
