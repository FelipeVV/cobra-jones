#ifndef ZOOBOO_H
#define ZOOBOO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Zooboo : public QObject, public QGraphicsPixmapItem
{
  public:
    void keyPressEvent(QKeyEvent* event);
    Zooboo(QGraphicsItem* parent = 0);
};

#endif // ZOOBOO_H
