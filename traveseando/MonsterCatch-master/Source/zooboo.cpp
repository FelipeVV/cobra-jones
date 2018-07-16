#include "zooboo.h"

#include <QDebug>
#include <QPixmap>
#include <QGraphicsScene>

void Zooboo::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Pressed a key";

}

Zooboo::Zooboo(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("qrc:/avatar.png"));
}
