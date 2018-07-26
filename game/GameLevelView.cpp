#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QtMath>
#include <QDebug>
#include <QKeyEvent>
#include <QList>

#include "GameLevelView.h"
#include "Player.h"
#include "tile.h"
#include "tilenormal.h"
#include "tilebroken.h"
#include "tilespecial.h"
#include "level.h"

#define NEWLINE "\n"

/// Call parent constructor.
/// Set level to reference pased in parameters.
GameLevelView::GameLevelView(const QVector<Level*>& levels,QWidget *parent, MainWindow *father)
  : QWidget(parent)
  , levels{levels}
    {
        /// An invisible object that manages all the items
        this->scene = new QGraphicsScene();
        this->scene->setSceneRect(0, 0, screenWidth, screenHeight);
        this->father = father;

        /// A visible rectangle of the scene
        this->view = new QGraphicsView(this->scene);
        view->setFixedSize(screenWidth, screenHeight);

        /// Show the view and enter in application's event loop
        this->view->show();
    }

/// Destructor. Delete view and scene
GameLevelView::~GameLevelView()
{
	delete view;
	delete scene;
}


void GameLevelView::loadLevelView(int chargeLevel)
{
    this->chargeLevel = chargeLevel;

    /// Add the level items
    displayLevel();


    /// Calculate the place in the center where the player should spawn.
    /// First the center of the floor is measured.
    /// Then the nearest valid point in the grid is chosen.
    /// A valid point is a multiple of tileWidth(or tileheight).
    double spawnX = floor((screenWidth/2)/tileWidth) * tileWidth;
    double spawnY = floor((screenHeight/2)/tileHeight) * tileHeight;

    /// debug
    qDebug() << "Width: "<< screenWidth << ". Height: " << screenHeight << NEWLINE
            << "spawnX: " << spawnX << ". spawnY: " << spawnY;

    /// Create player
    player = new Player(tileWidth, tileHeight, spawnX, spawnY, this);
	player->setSkin(1);

    /// Add the player caracter
	scene->addItem(player);

    /// Make player focusable
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

    /// Set a color background the same color as the tile's sides.
    /// This is because the place each tile is set in is not pixel perfect.
    /// That creates thin black vertical lines between some tile in the level that look ugly.
    /// A solution is to make those black lines the same color of the
	this->view->setBackgroundBrush(QBrush(QColor(231,180,155), Qt::SolidPattern));

    /// The scene has infinite size, but we want it has the same size than the view
	this->scene->setSceneRect( this->view->rect() );

    /// Disable scrollbars because they are not needed
	this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void GameLevelView::goToMenuRequested()
{
	father->backToMenuRequested();
}

/// Heavy explanation:
/// This might seem confusing at first, but a lot of local variables are
/// instaned in order tom make it more edible.
/// This method, based on the size of each tile.png and the size of the screen,
/// creates the tile objects in the proper position and size.
/// The formulas found in this method's body were taken from a whiteboard where we drew everything we needed.
/// For more info go to (https://imgur.com/Q0XQXR7).
void GameLevelView::displayLevel()
{
    /// Select, from player input, the level requested
    Level* currentLevel = levels[chargeLevel];

    /// Recieve rows and cols but as floating point values
    rows = static_cast<double>(currentLevel->rows);
	cols = static_cast<double>(currentLevel->cols);

    /// Decide tile width, taking in consideration how many must fit in the screen horizontally.
	tileWidth = screenWidth / cols;

    /// Decide tile width, taking in consideration how many must fit in the screen horizontally.
	tileHeight = screenHeight / rows;

    /// GrowthFactor is the number the size of the tile(imgSide) must be multiplied if to fit screen requirements(tileWidth).
	qreal growthFactor = tileWidth / imgSide;

	qDebug() << rows << "\n" << cols << "\n" << tileWidth << "\n" << tileHeight << "\n";

    /// Traverse the entire matrix
    for(int row = 0; row < currentLevel->rows; ++row)
	{
		for(int col = 0; col < currentLevel->cols; ++col)
		{
            /// Get the position where tile object should spawn, based on the current row and col we are in.
            qreal posX = tileWidth * static_cast<double>(col);
			qreal posY = tileHeight * static_cast<double>(row);
			qDebug() << posX << posY;

            /// Create tile based on char that the matrix contains(meta data).
            Tile *currentTile = createTile(currentLevel->matrix[row][col]);

            /// Position correctly
			currentTile->setPos( QPoint(posX, posY) );

            /// Transform, based on growth factor
            currentTile->setScale( growthFactor );

            /// Add tile so it can be shown.
			this->scene->addItem(currentTile);
            qDebug() << "tile added to scene";
		}
    }
}

/// Remove current level
void GameLevelView::removeLevel(int action)
{
    /// Create new level to change to
    Level* currentLevel=levels[chargeLevel];

    /// Give new value to rows and cols (R)
    rows = static_cast<double>(currentLevel->rows);
    cols = static_cast<double>(currentLevel->cols);

    /// Remove and delete player
    this->scene->removeItem(player);
    delete player;
    player=nullptr;

    /// Remove every tile that was placed in the scene
    const QList<QGraphicsItem*>& allTiles = scene->items();
    for ( QGraphicsItem* item : allTiles )
    {
        scene->removeItem(item);
    }

    /// After current level is deleted, do something depending on the int sent. (R)
    manageAction(action);
}

/// Meaning of each action(int argument)
/// 0: Level was lost, load current Level again.
/// 1: Level was won, go to next level.
/// 2: player requested to return to Menu.
void GameLevelView::manageAction(int action){
    if(action == 1)
    {
        chargeLevel++;
        if(chargeLevel>=9)
            chargeLevel=1;
        this->loadLevelView(chargeLevel);
    }
    if(action == 0)
        this->loadLevelView(chargeLevel);
    if(action == 2)
        goToMenuRequested();
}

/// create tile object depending on parameter char,
/// which can be one of the following:
/// O
/// -
/// #
Tile* GameLevelView::createTile(QChar type)
{
    if(type == '-')
        return new TileNormal(type);
    if(type == '#')
        return new TileBroken(type);
    if(type == 'O')
        return new TileSpecial(type);
    /// else: create a tile with an "invalid" tile image.
    return new Tile(type);
}
