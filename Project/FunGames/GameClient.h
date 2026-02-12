// GameClient.h
#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

class GameClient : public QObject
{
    Q_OBJECT
public:
    explicit GameClient(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void sendMessage(const QJsonObject &msg);

signals:
    void connected();
    void disconnected();
    void messageReceived(QJsonObject msg);
    void errorOccurred(QString err);

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *socket;
    QByteArray buffer;
};
