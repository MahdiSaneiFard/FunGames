#include "player.h"

Player::Player(const QString &name,
               const QString &username,
               const QString &email,
               const QString &phone,
               const QString &password)
    : Name(name), UserName(username), email(email),
    phoneNumber(phone), password(password),
    othelloScore(0), checkerScore(0), connectFourScore(0)
{}
