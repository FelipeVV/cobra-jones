#include <QDebug>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QApplication>

#include "Player.h"
#include <tile.h>

Player::Player()
{
    // Pre-load the collision sound
    walkingSound = new QSoundEffect(qApp);
    walkingSound->setSource(QUrl("qrc:/assets/sfx_movement_footsteps1b.wav"));
    walkingSound->setVolume(0.98f);
}


void Player::keyPressEvent(QKeyEvent *event)
{

    // React to input
    double walk_speed = 10.0;
    if(event->key() == Qt::Key_Left)
    {
        setPos(x() - walk_speed, y());
        //walkingSound->play();

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
        this->drill();
    }
    const QList<QGraphicsItem*>& items = collidingItems();
    for ( QGraphicsItem* item : items )
    {
        if (Tile* actual =dynamic_cast<Tile*>(item) )
        {
            if(actual->getType()=='#')
                qDebug() << "lvl failed\n";
        }
    }
}

void Player::setSkin(int skin)
{
    if(skin==1)
        setPixmap(QPixmap(":/assets/dawn sprite.png"));
}


void Player::drill(){
    // Traverse all graphic items that are colliding with this
    const QList<QGraphicsItem*>& items = collidingItems();
    for ( QGraphicsItem* item : items )
    {
        // If a graphic item is an
        if (Tile* actual =dynamic_cast<Tile*>(item) )
        {
            // Play the collision sound
            if(actual->getType()=='O')
                qDebug() << "lvl passed \n";
            if(actual->getType()=='-')
                qDebug() << "lvl failed\n";

        }
    }
}
