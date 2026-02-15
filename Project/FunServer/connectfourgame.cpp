#include "connectfourgame.h"
#include <QJsonObject>

ConnectFourGame::ConnectFourGame() {
    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            board[i][j] = 0;
        }
    }
}

void ConnectFourGame::handlemove(int col, int playerVal)
{
    if (playerVal != currentPlayer) return;

    int row = -1;
    for (int r = 5; r >= 0; --r) {
        if (board[r][col] == 0) {
            board[r][col] = playerVal;
            row = r;
            break;
        }
    }

    qDebug() << row;

    if (row != -1) {
        if (checkWin(row, col)) {
            //qDebug() << "Win";
            broadcastVictory(playerVal, row, col);
        } else if (isBoardFull())
        {
            //qDebug() << "full";
            broadcastVictory(0, row, col);
        }
        else {
            //qDebug() << "done op";
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            broadcastUpdate(row, col, playerVal);
        }
    }
}

bool ConnectFourGame::isBoardFull() {
    for (int c = 0; c < 7; ++c) {
        if (board[0][c] == 0) return false; // اگر حتی یک خانه در سطر اول خالی باشد
    }
    return true;
}

void ConnectFourGame::broadcastUpdate(int row, int col, int playerVal) {
    QJsonObject msg;
    msg["type"] = "connectFour";
    msg["msgType"] = "update";
    msg["column"] = col;
    msg["color"] = (playerVal == 1) ? "black" : "white";
    msg["nextTurn"] = (currentPlayer == 1) ? "black" : "white";

    //qDebug() << msg << "update server";

    if (blackPlayer) blackPlayer->sendMessage(msg);
    if (whitePlayer) whitePlayer->sendMessage(msg);
}

void ConnectFourGame::broadcastVictory(int winnerVal, int lastRow, int lastCol) {
    QJsonObject msg;
    msg["type"] = "connectFour";
    msg["msgType"] = "game_over"; // یا "victory" بسته به کدی که در کلاینت زدی
    msg["column"] = lastCol;
    msg["color"] = (winnerVal == 1 || (winnerVal == 0 && currentPlayer == 1)) ? "black" : "white";

    if (winnerVal == 0) {
        msg["winner"] = "draw";
    } else {
        msg["winner"] = (winnerVal == 1) ? "black" : "white";
    }

    if (blackPlayer) blackPlayer->sendMessage(msg);
    if (whitePlayer) whitePlayer->sendMessage(msg);
}

bool ConnectFourGame::checkWin(int r, int c) {
    int val = board[r][c];

    int dirs[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};

    for (int i = 0; i < 4; i++) {
        int count = 1;
        // بررسی در هر دو طرف جهت (مثلاً راست و چپ)
        for (int side : {-1, 1}) {
            int dr = dirs[i][0] * side;
            int dc = dirs[i][1] * side;
            int currR = r + dr;
            int currC = c + dc;

            while (currR >= 0 && currR < 6 && currC >= 0 && currC < 7 && board[currR][currC] == val) {
                count++;
                currR += dr;
                currC += dc;
            }
        }
        if (count >= 4) return true;
    }
    return false;
}
