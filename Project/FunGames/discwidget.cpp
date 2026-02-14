#include "DiscWidget.h"
#include <QPainter>

DiscWidget::DiscWidget(const QString& color, QWidget* parent)
    : QWidget(parent)
{
    setFixedSize(70, 70);
    discColor = (color == "black") ? QColor(96,96,96) : Qt::white;
}

void DiscWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setBrush(discColor);
    p.setPen(Qt::NoPen);
    p.drawEllipse(rect().adjusted(5,5,-5,-5));
}
