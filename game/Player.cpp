#include <QDebug>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QApplication>
#include <QTimer>
#include "tile.h"

#include "Player.h"

/// Constructor. Gets information about desired size, and place to spawn.
Player::Player(double tileWidth, double tileHeight, double spawnX, double spawnY, GameLevelView* fatha)
{
    /// Assign fatha
    this->fatha = fatha;

    /// Set the walking speed in each axis
	xWalkDistance = tileWidth;
	yWalkDistance = tileHeight;

    /// Change x and y
	setX(spawnX);
	setY(spawnY);
}

/// Destructor
Player::~Player()
{
}

/// Sets appereance of the player skin.
void Player::setSkin(int skin)
{
    /// Input 1, skin goes to default
	if(skin==1)
		setPixmap(QPixmap(":/assets/dawn sprite.png"));
}

/// Detects collision with left side of the screen.
/// Player should not walk if their origin x axis is 0,
/// becase that means they're next to the side of the screen.
bool Player::collisionLeft()
{
	if( x() <= 0 )
		return true;

	return false;
}


/// Detects collision with upper side of the screen.
/// Player should not walk if their origin y axis is 0,
/// becase that means they're next to the top of the screen.
bool Player::collisionUp()
{
    if( y() <= 0 ){
        return true;
    }
	return false;
}

/// If we are in the last available square in the x axis, return true.
bool Player::collisionRight()
{
	double roomWidth = 800.0;
	if( x() >= roomWidth - xWalkDistance )
		return true;
	return false;
}

/// If we are in the last available square in the y axis, return true.
bool Player::collisionDown()
{
	double roomHeight = 600.0;
	if( y() >= roomHeight - yWalkDistance )
		return true;
	return false;
}

/// Moves the player depending on the string input
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

/// Uses built in functions to get a list of colliding items with this player instance.
const QList<QGraphicsItem *> Player::getCollidingItems()
{
	const QList<QGraphicsItem*>& items = collidingItems();
	return items;
}

/// Built in keyPressEvent
void Player::keyPressEvent(QKeyEvent *event)
{

    /// React to input

    /// The following if conditionals contain two elements:
    /// 1. Check if the key press corresponds to a direction.
    /// 2. boolean function that returns false if player is on the repsective edge of the screen.
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

/// Collision checker function.
/// Recieves a boolean parameter. This parameter defines wether the collsion check
/// is simply the player passing through(false) or the player drilling on the floor,
/// which has more risk(true).
///
void Player::checkCollision(bool drill)
{
    const QList<QGraphicsItem*>& playerCollidingItems = getCollidingItems();
    for ( QGraphicsItem* item : playerCollidingItems )
    {
        /// Cast the tile we are colliding with
        Tile* actual = dynamic_cast<Tile*>(item);

        /// First, make sure the tile and player are in the same 'tile space'.
        /// This is an extra step besides regular collision because of resizing irregularities.
        if(areInSameTilePosition(x(), y(), actual))
        {
            /// If the player is drilling on the floor...
            /// Drilling takes risk. If player drills in a tile
            /// thats not...
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
            /// The player is just passing through
            /// the only risk is steping on a trap
            {
                if(actual->getType()=='#')
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

    qDebug() << "[" << actual->getType() << "]: " << floor(x1) << "," << floor(y1) << "~" << floor(x2) << "," << floor(y2) << "?";
    /// There are slight variations in the exact place were the player
    /// lands after taking a step. This slight distance variations are
    /// managed with a graceDistance.
    /// If the distance(difference) between x1 and x2 is small enough, it counts as a collision.
    double graceDistance = 5;
    if(( abs(floor(x1) - floor(x2)) < graceDistance ) && ( abs(floor(y1) - floor(y2)) < graceDistance ))
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
