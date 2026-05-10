#include "gameserver.h"
#include <QNetworkInterface>
#include <QHostAddress>
#include <QDebug>
#include <QString>
#include <QTcpSocket>


GameServer::GameServer(QObject *parent)
    : QObject(parent)
{
    server = new QTcpServer(this);
}

void GameServer::sendList(){
    QTcpSocket* serverSocket = new QTcpSocket;
    serverSocket->connectToHost(server->serverAddress(),12345);
    QDataStream in(serverSocket);
    QString command;
    in >> command;
    if(command == "GET_GAMES ")
    {
        serverSocket->write("GAMES_LIST ");
        serverSocket->write("1 ");
        serverSocket->write("asdf ");
        serverSocket->write("(createdMatches.at(0).color).c_str() ");
        serverSocket->write("(createdMatches.at(0).color).c_str() ");
    }
        serverSocket->write("connect dada ");
}

bool GameServer::start(quint16 port)
{
    if (server->isListening())
        return true;

    bool ok = server->listen(QHostAddress::Any, port);

    if (ok)
        qDebug() << "Server started on port" << port;
    else
        qDebug() << "Server failed:" << server->errorString();

    return ok;
}



void GameServer::stop()
{
    if (server->isListening()) {
        server->close();
        qDebug() << "Server stopped";
    }
}

bool GameServer::isRunning() const
{
    return server->isListening();
}

void GameServer::addToCreatedMatches(const GameOptions& newMatch)
{
    createdMatches.push_back(newMatch);
}

const QVector<GameOptions>& GameServer::getCreatedMatches()
{
    return createdMatches;
}

QString GameServer::getServerIP() const {
    foreach (const QHostAddress &addr, QNetworkInterface::allAddresses()) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol && addr != QHostAddress(QHostAddress::LocalHost))
            return addr.toString();
    }
    return "127.0.0.1";
}
