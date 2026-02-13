#ifndef OTHELLO_WINDOW_H
#define OTHELLO_WINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QJsonObject>
#include <QJsonArray>
#include "GameClient.h"

class OthelloWindow : public QWidget {
    Q_OBJECT/*
private:
    QPushButton* cells[8][8];
    QLabel* statusLabel;
    GameClient* client;
    QString myRole;

public:
    explicit OthelloWindow(GameClient* cl, QString role, QWidget *parent = nullptr);
    void updateBoard(const QJsonArray& boardData, QString currentTurn);
    void setStatus(QString text);

private slots:
    void onCellClicked();*/
};

#endif
