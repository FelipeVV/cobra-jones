#ifndef HOLEANIMATION_H
#define HOLEANIMATION_H

#include <QTimer>
//#include <QGraphicSV


class holeAnimation//: public QGraphicsPixmapItem
{
public:
    holeAnimation(double x1, double y1, double x2, double y2, double maxWidth, double maxHeight);
protected:
    QTimer *timer;
};

#endif // HOLEANIMATION_H
