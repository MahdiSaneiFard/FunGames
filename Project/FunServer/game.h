#ifndef GAME_H
#define GAME_H
#include <QObject>
#include "Client.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game() = default;
    virtual void handleMove(Client* player, const QJsonObject& move) = 0;
    virtual void startGame() = 0;
    virtual ~Game() {}
};

#endif // GAME_H
