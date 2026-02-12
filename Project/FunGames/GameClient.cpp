#include "GameClient.h"
#include <QDebug>

GameClient::GameClient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &GameClient::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &GameClient::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &GameClient::onReadyRead);
    connect(socket, qOverload<QAbstractSocket::SocketError>(&QTcpSocket::errorOccurred),
            this, &GameClient::onError);
}

void GameClient::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void GameClient::sendMessage(const QJsonObject &msg)
{
    QJsonDocument doc(msg);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n'); // علامت پایان پیام
    socket->write(data);
}

// ================== دریافت داده ==================
void GameClient::onReadyRead()
{
    buffer.append(socket->readAll());

    while (true) {
        int index = buffer.indexOf('\n');
        if (index == -1)
            break; // هنوز پیام کامل نیامده

        QByteArray line = buffer.left(index);
        buffer.remove(0, index + 1);

        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(line, &err);
        if (err.error != QJsonParseError::NoError) {
            qWarning() << "JSON parse error:" << err.errorString();
            continue;
        }

        if (!doc.isObject()) continue;

        emit messageReceived(doc.object());
    }
}

// ================== سیگنال‌ها ==================
void GameClient::onConnected() { emit connected(); }
void GameClient::onDisconnected() { emit disconnected(); }

void GameClient::onError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError)
    emit errorOccurred(socket->errorString());
}
