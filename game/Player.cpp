#include <QDebug>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QApplication>

#include "Player.h"
#include <tile.h>

Player::Player(double tileWidth, double tileHeight, double spawnX, double spawnY)
{
    // Set the walking speed in each axis
    xWalkDistance = tileWidth;
    yWalkDistance = tileHeight;

    //change x and y
    setX(spawnX);
    setY(spawnY);

    // Pre-load the collision sound
    walkingSound = new QSoundEffect(qApp);
    walkingSound->setSource(QUrl("qrc:/assets/sfx_movement_footsteps1b.wav"));
    walkingSound->setVolume(0.98f);
}


void Player::keyPressEvent(QKeyEvent *event)
{

    // React to input
    if(event->key() == Qt::Key_Left)
    {
        setPos(x() - xWalkDistance, y());
        //walkingSound->play();

    }

    if(event->key() == Qt::Key_Right)
    {
        setPos(x() + xWalkDistance, y());
    }

    if(event->key() == Qt::Key_Up)
    {
        setPos(x(), y() - yWalkDistance);
    }

    if(event->key() == Qt::Key_Down)
    {
        setPos(x(), y() + yWalkDistance);
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
            if(actual->getType()=='#'){
                //actual->growUp();
                //qreal growFactor =
                qDebug() << "lvl failed\n";
                //actual->setScale( growthFactor );*/
            }
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
