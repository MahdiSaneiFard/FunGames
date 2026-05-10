#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QByteArray>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket *socket, QObject *parent = nullptr);

    QString role;
    QString username;

private slots:
    void onReadyRead();
    void onDisconnected();

signals:
    //void moveReceived(Client* sender, QJsonObject data);

private:
    QTcpSocket *socket;
    QByteArray buffer;

public:
    void processMessage(const QJsonObject &msg);
    void sendMessage(const QJsonObject &msg);
    Client* otherClient;
};
