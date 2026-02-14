#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>

class DiscWidget;

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget* parent = nullptr);

    void dropDisc(int column, const QString& color);
    void setPlayerColor(const QString& c) { playerColor = c; }

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    int board[6][7] = {}; // 0 empty, 1 black, 2 white
    QString playerColor;
};

#endif
