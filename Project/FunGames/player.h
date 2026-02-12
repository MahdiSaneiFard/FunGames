#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player(const QString &name,
           const QString &username,
           const QString &email,
           const QString &phone,
           const QString &password)
        ;

    QString getName() const { return Name; }
    QString getUserName() const { return UserName; }
    QString getEmail() const { return email; }
    QString getPhoneNumber() const { return phoneNumber; }
    QString getPassword() const {return password;}

    void setName(QString name) { Name = name; }
    void setUserName(QString username) { UserName = username; }
    void setEmail(QString Email) { email = Email; }
    void setPhoneNumber(QString phone) { phoneNumber = phone; }
    void setPassword(QString pass) { password = pass;}

    int getOthelloScore() const { return othelloScore; }
    void setOthelloScore(int s) { othelloScore = s; }

    int getCheckerScore() const { return checkerScore; }
    void setCheckerScore(int s) { checkerScore = s; }

    int getConnectFourScore() const { return connectFourScore; }
    void setConnectFourScore(int s) { connectFourScore = s; }

private:
    QString Name;
    QString UserName;
    QString email;
    QString phoneNumber;
    QString password;
    int othelloScore;
    int checkerScore;
    int connectFourScore;
};

#endif // PLAYER_H
