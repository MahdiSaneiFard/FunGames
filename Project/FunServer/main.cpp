#include <QCoreApplication>
#include "Server.h"
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.start(12345);

    QTcpSocket socket;

    socket.connectToHost("127.0.0.1", 12345);

    if (!socket.waitForConnected(3000)) {
        qDebug() << "Connection failed!";
        return 1;
    }

    qDebug() << "Connected to server!";

    QJsonObject obj;
    obj["type"] = "test";
    obj["message"] = "Hello from test client";

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n');

    socket.write(data);
    socket.flush();
    socket.waitForBytesWritten(3000);

    qDebug() << "Message sent!";

    return a.exec();
}
