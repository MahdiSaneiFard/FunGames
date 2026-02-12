#include "Server.h"
#include "Client.h"
#include <QDebug>

Server::Server(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection,
            this, &Server::onNewConnection);
}

bool Server::start(quint16 port)
{
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        qCritical() << "Server failed:" << tcpServer->errorString();
        return false;
    }

    qDebug() << "Server listening on port" << port;
    return true;
}

void Server::onNewConnection()
{
    QTcpSocket *socket = tcpServer->nextPendingConnection();
    qDebug() << "New client connected";
    if (!client1)
        client1 = new Client(socket, this);
    else if (!client2)
        client2 = new Client(socket, this);
    else
    {
        socket->disconnectFromHost();
    }
}
