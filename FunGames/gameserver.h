#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <QTcpServer>
#include <QObject>
#include "GameOptions.h"
#include "QVector"
#include <QTcpSocket>

class GameServer : public QObject {
    Q_OBJECT
public:
    explicit GameServer(QObject *parent = nullptr);

    bool start(quint16 port);

    void stop();

    bool isRunning() const;

    void addToCreatedMatches(const GameOptions& newMatch);

    const QVector<GameOptions>& getCreatedMatches();

    QString getServerIP() const;

    void sendList();
private slots:
    void onNewConnection() {
        while (server->hasPendingConnections()) {
            auto *sock = server->nextPendingConnection();

            connect(sock, &QTcpSocket::readyRead, this, [sock]() {
                // روش 1: ساده‌ترین حالت
                // QByteArray data = sock->readAll();

                // روش بهتر برای پیام‌های خطی: تا وقتی خط کامل داریم بخون
                while (sock->canReadLine()) {
                    QByteArray line = sock->readLine(); // شامل \n هم هست
                    line = line.trimmed();

                    qDebug() << "Server got:" << line;

                    // پاسخ برگردون
                    sock->write("ACK: " + line + "\n");
                }
            });

            connect(sock, &QTcpSocket::disconnected, sock, &QObject::deleteLater);

            qDebug() << "New client connected from" << sock->peerAddress().toString();
            sock->write("Welcome!\n");
        }
    }

private:
    QTcpServer *server;

    QVector<GameOptions> createdMatches;
};

#endif
