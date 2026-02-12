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

void Client::sendMessageToServer(const QString &text)
{
    QJsonObject msg;
    msg["type"] = "chat";
    msg["message"] = text;

    QJsonDocument doc(msg);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n');

    socket->write(data);
    socket->flush();
}


void Client::onReadyRead()
{
    qDebug() << "Data arrived!";
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
    qDebug() << "Full message received:" << msg;

    QString type = msg["type"].toString();
    qDebug() << "Message type:" << type;

    if(type == "role") // سرور تعیین می‌کنه این کلاینت Host است یا Guest
    {
        QString assignedRole = msg["role"].toString(); // "host" یا "guest"
        this->role = assignedRole;
        qDebug() << "Assigned role:" << assignedRole;
    }

    if(type == "test")  // ← پیام تستی
    {
        QString message = msg["message"].toString();
        qDebug() << "Message content:" << message;
    }

    if(type == "chat") {
        QString text = msg["message"].toString();
        qDebug() << "Client said:" << text;
    }
}

void Client::onDisconnected()
{
    qDebug() << "Client disconnected";
    socket->deleteLater();
    deleteLater();
}
