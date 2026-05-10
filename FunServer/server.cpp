#include "Server.h"
#include "Client.h"
#include "qsqlquery.h"
#include <QDebug>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QSqlError>

Server::Server(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection,
            this, &Server::onNewConnection);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("fungames.db");

    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
    } else {
        qDebug() << "Database connected successfully!";

        // اطمینان از وجود جدول
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS match_history ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "game_type TEXT, player_black TEXT, player_white TEXT, "
                   "winner_username TEXT, black_score INTEGER, white_score INTEGER, date DATETIME)");

        query.exec("ALTER TABLE match_history ADD COLUMN date DATETIME");
    }
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
    if (!client1)// set nashode nbood
    {
        client1 = new Client(socket, this);
        //connect(client1, &Client::moveReceived, this, [this](Client* s, QJsonObject d){
          //  if(activeGame) activeGame->handleMove(s, d);
        //});
    }
    else if (!client2)
    {
        client2 = new Client(socket, this); // doo ra set
        client2->otherClient = client1;
        client1->otherClient = client2;
       // connect(client2, &Client::moveReceived, this, [this](Client* s, QJsonObject d){
         //   if(activeGame) activeGame->handleMove(s, d);
        //});

       // activeGame = new OthelloGame();
        //activeGame->assignRoles(client1, client2, "black");
        //activeGame->startGame();
    }
    else
    {
        socket->disconnectFromHost();
    }
}
