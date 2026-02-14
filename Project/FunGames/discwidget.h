#ifndef DISCWIDGET_H
#define DISCWIDGET_H

#include <QWidget>

class DiscWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DiscWidget(const QString& color, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;

private:
    QColor discColor;
};

#endif
