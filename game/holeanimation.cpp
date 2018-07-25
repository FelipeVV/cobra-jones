#include "holeanimation.h"
#include <QGraphicsRectItem>
#include <QPainter>
#include <QDebug>


holeAnimation::holeAnimation(double x1, double y1, double x2, double y2, double maxWidth, double maxHeight)
{
    qDebug() << "hole created";
    QGraphicsRectItem *rect = new QGraphicsRectItem();

    double holeWidth = x2 - x1;
    double holeHeight = y2 - y1;

    QPainter painter(this);

    rect->setRect(x1, x2, holeWidth, holeHeight);
    painter.fillRect(rect, QBrush(QColor(128, 128, 255, 255)));
}
