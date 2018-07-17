#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
//#include <QSoundEffect>

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
    if(event->key() == Qt::Key_Space)
    {

    }
}

void Player::setSkin(int skin)
{
    if(skin==1)
        setPixmap(QPixmap(":/assets/avatar.png"));
}
/*void Player::detectCollisions()
{
    // Traverse all graphic items that are colliding with this
    const QList<QGraphicsItem*>& items = collidingItems();
    //for ( QGraphicsItem* item : items )
    {
        // If a graphic item is an obstacle remove it from scene
        if ( Obstacle* obstacle = dynamic_cast<Obstacle*>(item) )
        {
            // Play the collision sound
            //this->collisionSound->play();

            // Stop current move animation and move in another direction
            //this->moveAnimation->stop();
            //this->move();
        }
    }
}*/
