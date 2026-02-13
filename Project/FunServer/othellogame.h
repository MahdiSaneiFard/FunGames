#ifndef OTHELLOGAME_H
#define OTHELLOGAME_H
#include <game.h>

class OthelloGame : public Game
{
    Client* blackPlayer = nullptr;
    Client* whitePlayer = nullptr;
    enum Cell { Empty = 0, Black = 1, White = 2 };
    int board[8][8];
    int currentPlayer;

public:
    OthelloGame();
    void assignRoles(Client* host, Client* guest, QString hostColorChoice);
    bool IsValidMove(int row, int col, int playerColor);
    void flipPieces(int row, int col, int playerColor);
    bool hasAnyValidMove(int playerColor);
    void handleMove(Client* player, const QJsonObject& move) override;
    void startGame() override;
    void endGame();
    void broadcastGameState();
};

#endif // OTHELLOGAME_H
