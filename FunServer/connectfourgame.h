#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H
#include "Client.h"

class ConnectFourGame
{
    Client* blackPlayer = nullptr;
    Client* whitePlayer = nullptr;
    int board[6][7] = {0};
    int currentPlayer = 1;
public:
    ConnectFourGame();
    void handlemove(int col, int playerVal);
    bool checkWin(int r, int c);
    void broadcastUpdate(int row, int col, int playerVal);
    void broadcastVictory(int winnerVal, int lastRow, int lastCol);
    bool isBoardFull();
    void setPlayers(Client* b, Client* w) { blackPlayer = b; whitePlayer = w; }
};

#endif // CONNECTFOURGAME_H
