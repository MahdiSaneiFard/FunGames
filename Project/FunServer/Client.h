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

private:
    void processMessage(const QJsonObject &msg);
    void sendMessage(const QJsonObject &msg);
    QTcpSocket *socket;
    QByteArray buffer;
};
