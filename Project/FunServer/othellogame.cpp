#include "othellogame.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

OthelloGame::OthelloGame() {
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j) board[i][j] = Empty;

    board[3][3] = White; board[4][4] = White;
    board[3][4] = Black; board[4][3] = Black;
    currentPlayer = Black; // طبق قانون اتللو همیشه سیاه شروع می‌کنه
}

void OthelloGame::assignRoles(Client* host, Client* guest, QString hostColorChoice) {
    if (hostColorChoice.toLower() == "black") {
        blackPlayer = host;
        whitePlayer = guest;
    } else {
        whitePlayer = host;
        blackPlayer = guest;
    }
}

void OthelloGame::startGame() {
    // پیامی به کلاینت‌ها بفرست که بازی شروع شده
    QJsonObject startMsg;
    startMsg["type"] = "game_start";
    broadcastGameState(); // وضعیت اولیه صفحه رو بفرست
}

void OthelloGame::broadcastGameState() {
    QJsonObject state;
    state["type"] = "othello";
    state["msgType"] = "update_board";
    state["currentPlayer"] = (currentPlayer == Black) ? "black" : "white";

    int blackCount = 0;
    int whiteCount = 0;

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (board[r][c] == Black) blackCount++;
            else if (board[r][c] == White) whiteCount++;
        }
    }

    state["blackScore"] = blackCount;
    state["whiteScore"] = whiteCount;

    QJsonArray boardArray;
    for (int r = 0; r < 8; ++r) {
        QJsonArray rowArray;
        for (int c = 0; c < 8; ++c) {
            rowArray.append(board[r][c]); // 0: Empty, 1: Black, 2: White
        }
        boardArray.append(rowArray);
    }
    state["board"] = boardArray;

    qDebug() << state;

    // ارسال برای هر دو کلاینت
    if (blackPlayer) blackPlayer->sendMessage(state);
    if (whitePlayer) whitePlayer->sendMessage(state);
}

bool OthelloGame::IsValidMove(int row, int col, int playerColor) {
    if (row < 0 || row >= 8 || col < 0 || col >= 8) return false;
    if (board[row][col] != Empty) return false;

    int opponent = (playerColor == Black) ? White : Black;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        bool hasOpponentBetween = false;

        while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opponent) {
            r += dr[i];
            c += dc[i];
            hasOpponentBetween = true;
        }

        if (hasOpponentBetween && r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == playerColor) {
            return true;
        }
    }
    qDebug() << row << ' ' << col << ' ' << playerColor;
    return false;
}

void OthelloGame::flipPieces(int row, int col, int playerColor) {
    int opponent = (playerColor == Black) ? White : Black;
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    board[row][col] = playerColor;

    for (int i = 0; i < 8; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        QVector<QPair<int, int>> potentialFlips;

        while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opponent) {
            potentialFlips.append({r, c});
            r += dr[i];
            c += dc[i];
        }

        if (!potentialFlips.isEmpty() && r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == playerColor) {
            for (const auto& pos : potentialFlips) {
                board[pos.first][pos.second] = playerColor;
            }
        }
    }
}

bool OthelloGame::hasAnyValidMove(int playerColor) {
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (board[r][c] == Empty && IsValidMove(r, c, playerColor))
                return true;
        }
    }
    return false;
}

void OthelloGame::handleMove(Client* player, const QJsonObject& move) {
    int r = move["row"].toInt();
    int c = move["col"].toInt();

    // اصلاح منطق تشخیص رنگ کلاینت
    int color = (player == blackPlayer) ? Black : White;

    if (color != currentPlayer) return;

    if (IsValidMove(r, c, color)) {
        qDebug() << move;
        flipPieces(r, c, color);

        for (int i = 0 ; i < 8 ; i++)
        {
            for (int j = 0 ; j < 8 ; j++)
            {
                qDebug() << board[i][j];
            }
        }

        int opponent = (color == Black) ? White : Black;

        if (hasAnyValidMove(opponent)) {
            qDebug() << opponent << move;
            currentPlayer = opponent;
        } else if (hasAnyValidMove(color)) {
            currentPlayer = color; // نوبت حریف سوخت (Pass)
        } else {
            endGame(); // هیچ‌کدوم حرکت ندارن
            return;
        }
        broadcastGameState();
    }
}

void OthelloGame::endGame() {
    int blackCount = 0;
    int whiteCount = 0;

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (board[r][c] == Black) blackCount++;
            else if (board[r][c] == White) whiteCount++;
        }
    }

    QJsonObject endMsg;
    endMsg["type"] = "othello";
    endMsg["msgType"] = "endgane";
    endMsg["blackScore"] = blackCount;
    endMsg["whiteScore"] = whiteCount;

    QJsonArray boardArray;
    for (int r = 0; r < 8; ++r) {
        QJsonArray rowArray;
        for (int c = 0; c < 8; ++c) {
            rowArray.append(board[r][c]); // 0: Empty, 1: Black, 2: White
        }
        boardArray.append(rowArray);
    }
    endMsg["board"] = boardArray;

    if (blackCount > whiteCount) endMsg["winner"] = "black";
    else if (whiteCount > blackCount) endMsg["winner"] = "white";
    else endMsg["winner"] = "draw";

    if (blackPlayer) blackPlayer->sendMessage(endMsg);
    if (whitePlayer) whitePlayer->sendMessage(endMsg);

    // اینجا می‌توانید متدی برای ذخیره در دیتابیس هم فراخوانی کنید
}
