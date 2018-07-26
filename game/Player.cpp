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
        fatha->removeLevel(2);
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
        if ( (actual) && (!drill) && (y() == actual->y()))
        {
            if(actual->getType()=='#'){
                qDebug()<<"lvl failed \n";
                levelFail();
            }
        }
        if ((actual) && (drill) && (y() == actual->y()))
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
    }
}

void Player::levelFail()
{
    //setPixmap(QPixmap(":/assets/floor_dark.png"));
    fatha->removeLevel(0);
}

void Player::levelWin()
{
    //setPixmap(QPixmap(":/assets/avatar.png"));
    fatha->removeLevel(1);
}
