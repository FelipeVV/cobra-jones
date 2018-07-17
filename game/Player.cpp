#include "Player.h"
#include <QDebug>
#include <QKeyEvent>

/*
void Player::Player()
{
   setRect(0, 0, 100, 100);
}
*/

void Player::keyPressEvent(QKeyEvent *event)
{

    // React to input
    double walk_speed = 10.0;
    if(event->key() == Qt::Key_Left)
    {
        setPos(x() - walk_speed, y());
    }

    if(event->key() == Qt::Key_Right)
    {
        setPos(x() + walk_speed, y());
    }

    if(event->key() == Qt::Key_Up)
    {
        setPos(x(), y() - walk_speed);
    }

    if(event->key() == Qt::Key_Down)
    {
        setPos(x(), y() + walk_speed);
    }
}
