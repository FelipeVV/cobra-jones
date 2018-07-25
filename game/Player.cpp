#include <QDebug>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QApplication>
#include <tile.h>

#include "Player.h"
#include "holeanimation.h"

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
    if((event->key() == Qt::Key_Left) && !collisionLeft() )
    {
        setPos(x() - xWalkDistance, y());
        //walkingSound->play();

    }

    if( (event->key() == Qt::Key_Right) && !collisionRight())
    {
        setPos(x() + xWalkDistance, y());
    }

    if( (event->key() == Qt::Key_Up) && !collisionUp() )
    {
        setPos(x(), y() - yWalkDistance);
    }

    if( (event->key() == Qt::Key_Down) && !collisionDown() )
    {
        setPos(x(), y() + yWalkDistance);
    }
    if(event->key() == Qt::Key_Space)
    {
        this->drill();
    }
    if(event->key() == Qt::Key_P)
    {
        qDebug()<<"cierrelo papi ";
    }
    const QList<QGraphicsItem*>& items = collidingItems();
    for ( QGraphicsItem* item : items )
    {
        if (Tile* actual =dynamic_cast<Tile*>(item) )
        {
            if(actual->getType()=='#'){
                //actual->growUp();
                //qreal growFactor =
                levelFail();
                //actual->setScale( growthFactor );*/
            }
        }
    }
}

void Player::levelFail()
{
    qDebug() << "lvl failed\n";
    holeAnimation* hole = new holeAnimation(0, 0, 100, 100, 0, 0);
}

void Player::setSkin(int skin)
{
    if(skin==1)
        setPixmap(QPixmap(":/assets/dawn sprite.png"));
}

bool Player::collisionLeft()
{
    if( x() <= 0 )
        return true;
    return false;
}

bool Player::collisionUp()
{
    if( y() <= 0 )
        return true;
    return false;
}


bool Player::collisionRight()
{
    double roomWidth = 800.0;
    if( x() >= roomWidth - xWalkDistance )
        return true;
    return false;
}

bool Player::collisionDown()
{
    double roomHeight = 600.0;
    if( y() >= roomHeight - yWalkDistance )
        return true;
    return false;
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
                levelFail();

        }
    }
}
