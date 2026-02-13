#include "Client.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Client::Client(QTcpSocket *s, QObject *parent)
    : QObject(parent), socket(s)
{
    connect(socket, &QTcpSocket::readyRead,
            this, &Client::onReadyRead);
    connect(socket, &QTcpSocket::disconnected,
            this, &Client::onDisconnected);
}

void Client::onReadyRead()
{
    buffer.append(socket->readAll());

    while (true) {
        int end = buffer.indexOf('\n');
        if (end == -1)
            break;

        QByteArray line = buffer.left(end);
        buffer.remove(0, end + 1);

        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(line, &err);

        if (err.error != QJsonParseError::NoError) {
            qWarning() << "Bad JSON";
            continue;
        }

        processMessage(doc.object());
    }
}

void Client::sendMessage(const QJsonObject &msg)
{
    QJsonDocument doc(msg);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n'); // علامت پایان پیام
    socket->write(data);
}

void Client::processMessage(const QJsonObject &msg)
{
    QString type = msg["type"].toString();
    qDebug() << "Message type:" << type;

    if(type == "role") // سرور تعیین می‌کنه این کلاینت Host است یا Guest
    {
        QString assignedRole = msg["role"].toString(); // "host" یا "guest"
        this->role = assignedRole;
        qDebug() << "Assigned role:" << assignedRole;
    }

    if (msg["type"].toString() == "move") {
        emit moveReceived(this, msg);
    }
}

void Client::onDisconnected()
{
    qDebug() << "Client disconnected";
    socket->deleteLater();
    deleteLater();
}
