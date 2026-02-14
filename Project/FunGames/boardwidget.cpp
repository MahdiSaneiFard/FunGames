#include "BoardWidget.h"
#include "DiscWidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QPropertyAnimation>

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground);
}

void BoardWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    p.fillRect(rect(), QColor("#1e40af")); // board background

    int cellW = width() / 7;
    int cellH = height() / 6;

    p.setBrush(Qt::black);
    p.setPen(Qt::NoPen);

    // draw empty holes
    for (int r = 0; r < 6; ++r)
    {
        for (int c = 0; c < 7; ++c)
        {
            p.drawEllipse(
                c * cellW + 8,
                r * cellH + 8,
                cellW - 16,
                cellH - 16
                );
        }
    }
}

void BoardWidget::mousePressEvent(QMouseEvent* event)
{
    int column = event->pos().x() / (width() / 7);

    // ستون valid؟
    if(column < 0 || column > 6) return;

    // مهره خود بازیکن رو بینداز
    dropDisc(column, playerColor);

    // در اینجا می‌تونی پیام سرور بفرستی
    // مثال:
    // QJsonObject msg;
    // msg["msgType"] = "move";
    // msg["column"] = column;
    // msg["color"] = playerColor;
    // emit sendMessage(msg);
}

void BoardWidget::dropDisc(int column, const QString& color)
{
    // پیدا کردن ردیف خالی
    int row = -1;
    for (int r = 5; r >= 0; --r)
    {
        if (board[r][column] == 0)
        {
            row = r;
            break;
        }
    }
    if (row == -1) return; // ستون پر

    board[row][column] = (color == "black") ? 1 : 2; // black - > 1

    int cellW = width() / 7;
    int cellH = height() / 6;

    int x = column * cellW + 5;
    int yFinal = row * cellH + 5;

    DiscWidget* disc = new DiscWidget(color, this);
    disc->move(x, -cellH);
    disc->show();

    QPropertyAnimation* anim = new QPropertyAnimation(disc, "pos", this);
    anim->setStartValue(QPoint(x, -cellH));
    anim->setEndValue(QPoint(x, yFinal));
    anim->setDuration(700);
    anim->setEasingCurve(QEasingCurve::OutBounce);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}
