#include "Client.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "Server.h"

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

    else if (msg["type"].toString() == "move") {
        // emit moveReceived(this, msg);
    }

    else if(type == "create_match")
    {
        if(!(otherClient))
            qDebug() << "there is only one person connected to server";

        QString newGameMode = msg["game"].toString();

        QString hostColor = msg["hostColor"].toString();

        int matchTime = msg["timeLimit"].toInt();

        qDebug() << "new game mode : " << newGameMode;
        qDebug() << "new hostColor : " << hostColor;
        qDebug() << "new matchTime : " << matchTime;




        if (otherClient) {
            otherClient->sendMessage(msg);
        }
    }
    else if (type == "selected_match")
    {
        qDebug() << msg["game"].toString();
        Server* server = qobject_cast<Server*>(parent());
        if (server) {
            // ۱. ساخت بازی جدید
            if (server->activeGame) delete server->activeGame;
            server->activeGame = new OthelloGame();

            // ۲. تعیین نقش‌ها
            QString hostCol = msg["hostColor"].toString();
            server->activeGame->assignRoles(this, otherClient, hostCol);

            QJsonObject msg1;
            msg1["type"] = "start_game_broadcast";
            msg1["game"] = "othello";
            msg1["hostColor"] = msg["hostColor"].toString();
            msg1["timeLimit"] = msg["timeLimit"];
            msg1["yourColor"] = (hostCol == "white" ? "black" : "white");

            qDebug() << msg1["type"].toString();

            if (otherClient) {
                otherClient->sendMessage(msg1);
                msg1["yourColor"] = hostCol;
                this->sendMessage(msg1);
            }

            server->activeGame->startGame();
        }
    }
}

void Client::onDisconnected()
{
    qDebug() << "Client disconnected";
    socket->deleteLater();
    deleteLater();
}
