#include <QDebug>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QApplication>
#include <QTimer>
#include "tile.h"

#include "Player.h"

Player::Player(double tileWidth, double tileHeight, double spawnX, double spawnY, GameLevelView* fatha)
{
	this->fatha= fatha;
	// Set the walking speed in each axis
	xWalkDistance = tileWidth;
	yWalkDistance = tileHeight;

	//change x and y
	setX(spawnX);
	setY(spawnY);

    /*qreal growthFactor = tileHeight / tileWidth;
    setScale( growthFactor );*/
}

Player::~Player()
{
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
    if( y() <= 0 ){
        return true;
    }
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

void Player::move(QString direction)
{
	if(direction == "left")
		setPos(x() - xWalkDistance, y());
	if(direction == "right")
		setPos(x() + xWalkDistance, y());
	if(direction == "up")
		setPos(x(), y() - yWalkDistance);
	if(direction == "down")
		setPos(x(), y() + yWalkDistance);
}

const QList<QGraphicsItem *> Player::getCollidingItems()
{
	const QList<QGraphicsItem*>& items = collidingItems();
	return items;
}

void Player::keyPressEvent(QKeyEvent *event)
{

	// React to input
	if((event->key() == Qt::Key_Left)&& !collisionLeft())
	{
		move("left");
        checkCollision(false);
	}

	if( (event->key() == Qt::Key_Right) && !collisionRight())
	{
		move("right");
        checkCollision(false);
	}

	if( (event->key() == Qt::Key_Up) && !collisionUp())
	{
		move("up");
        checkCollision(false);
	}

	if( (event->key() == Qt::Key_Down) && !collisionDown() )
	{
		move("down");
        checkCollision(false);
	}
	if( (event->key() == Qt::Key_P))
	{
        //fatha->removeLevel(2);
	}
    if( (event->key() == Qt::Key_Space))
    {
        checkCollision(true);
    }
    //checkCollision(false);
}

void Player::checkCollision(bool drill)
{
    const QList<QGraphicsItem*>& playerCollidingItems = getCollidingItems();
    for ( QGraphicsItem* item : playerCollidingItems )
    {
        Tile* actual = dynamic_cast<Tile*>(item);
        /*
        if ( (!drill) && areInSameTilePosition(x(), y(), actual) )
        {
            if(actual->getType()=='#'){
                qDebug()<<"lvl failed \n";
                levelFail();
            }
        }
        if ( (drill) && areInSameTilePosition(x(), y(), actual) )
        {
            // Play the collision sound
            if(actual->getType()=='O'){
                qDebug() << "lvl passed \n";
                levelWin();
            }
            if(actual->getType()=='-'){
                qDebug() << "lvl failed \n";
                levelFail();
            }
        }
        */

        // First, make sure the tile and player are in the same 'tile space'.
        // This is an extra step besides collision because of resizing irregularities.
        if(areInSameTilePosition(x(), y(), actual))
        {
            if(drill)
            {
                if(actual->getType()=='O')
                {
                    levelWin();
                }
                if(actual->getType()=='-')
                {
                    levelFail();
                }
            }
            else //!drill
            {
                if(actual->getType()=="#")
                {
                    levelFail();
                }
            }
        }
    }
}

bool Player::areInSameTilePosition(double x1, double y1, Tile* actual)
{
    double x2 = actual->x();
    double y2 = actual->y();

    qDebug() << "[" << actual->getType() << "]: " << x1 << "," << y1 << "~" << x2 << "," << y2 << "?";
    if((floor(x1) == floor(x2))&&(floor(y1) == floor(y2)))
    {
        qDebug() << "Collision true";
        return true;
    }
    //else
    qDebug() << "Collision false";
    return false;
}

void Player::levelFail()
{
    qDebug() << "lvl failed \n";
    //setPixmap(QPixmap(":/assets/floor_dark.png"));
    fatha->removeLevel(0);
}

void Player::levelWin()
{
    qDebug() << "lvl passed \n";
    //setPixmap(QPixmap(":/assets/avatar.png"));
    fatha->removeLevel(1);
}
