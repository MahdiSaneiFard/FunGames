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

    else if (type == "login") {
        this->username = msg["username"].toString();
        qDebug() << "Client identified as:" << username;
    }

    else if (msg["type"].toString() == "othello") {
        // emit moveReceived(this, msg);
        if (msg["msgType"] == "move")
        {
            //qDebug() << msg;
            Server* server = qobject_cast<Server*>(parent());
            if (server && server->activeGame) {
                server->activeGame->handleMove(this, msg);
            }
        }

        else if(msg["msgType"] == "timesUp")
        {
            qDebug() << msg;
            Server* server = qobject_cast<Server*>(parent());
            if (server && server->activeGame) {
                server->activeGame->endGame(true, msg["player"].toString());
            }
        }
    }

    else if (msg["type"] == "connectFour")
    {
        if (msg["msgType"] == "move")
        {
            qDebug() << msg;
            Server* server = qobject_cast<Server*>(parent());
            if (server && server->activeCFGame) {
                int col = msg["column"].toInt();

                // اصلاح ۲: تبدیل String رنگ به عدد (1 برای سیاه، 2 برای سفید)
                QString colorStr = msg["color"].toString();
                int playerVal = (colorStr == "black") ? 1 : 2;

                server->activeCFGame->handlemove(col, playerVal);
            }
        }

        else if(msg["msgType"] == "timesUp")
        {
            qDebug() << msg;
            Server* server = qobject_cast<Server*>(parent());
            if (server && server->activeCFGame) {
                server->activeCFGame->broadcastVictory((msg["color"].toString() == "white") ? 1 : 2,1000 ,1000);// az ghast barakse
            }
        }
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
        if (server && (msg["game"].toString() == "othello")) {
            // ۱. ساخت بازی جدید
            if (server->activeGame){ delete server->activeGame; server->activeGame = nullptr; }
            if (server->activeCFGame){ delete server->activeCFGame; server->activeCFGame = nullptr; }
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
        if (server && (msg["game"].toString() == "connectFour")){
            if (server->activeGame){ delete server->activeGame; server->activeGame = nullptr; }
            if (server->activeCFGame){ delete server->activeCFGame; server->activeCFGame = nullptr; }
            server->activeCFGame = new ConnectFourGame();

            QString hostCol = msg["hostColor"].toString();
            if (hostCol == "black") {
                server->activeCFGame->setPlayers(this, otherClient);
            } else {
                server->activeCFGame->setPlayers(otherClient, this);
            }

            QJsonObject msg1;
            msg1["type"] = "start_game_broadcast";
            msg1["game"] = "connectFour";
            msg1["hostColor"] = msg["hostColor"].toString();
            msg1["timeLimit"] = msg["timeLimit"];
            msg1["yourColor"] = (hostCol == "white" ? "black" : "white");

            qDebug() << msg1["type"].toString();

            if (otherClient) {
                otherClient->sendMessage(msg1);
                msg1["yourColor"] = hostCol;
                this->sendMessage(msg1);
            }
        }
    }
}

void Client::onDisconnected()
{
    qDebug() << "Client disconnected";
    socket->deleteLater();
    deleteLater();
}
