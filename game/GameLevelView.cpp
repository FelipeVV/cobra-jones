#include "GameLevelView.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QtMath>
#include <QDebug>
#include <QKeyEvent>
#include <QList>

#include "Player.h"
#include "tile.h"
#include "tilenormal.h"
#include "tilebroken.h"
#include "tilespecial.h"
#include "level.h"


#define NEWLINE "\n"

GameLevelView::GameLevelView(const QVector<Level*>& levels,QWidget *parent, MainWindow *father)
  : QWidget(parent)
  , levels{levels}
    {
        // An invisible object that manages all the items
        this->scene = new QGraphicsScene();
        this->scene->setSceneRect(0, 0, screenWidth, screenHeight);
        this->father = father;
        // A visible rectangle of the scene
        this->view = new QGraphicsView(this->scene);
        view->setFixedSize(screenWidth, screenHeight);
        // Show the view and enter in application's event loop
        this->view->show();
    }

GameLevelView::~GameLevelView()
{
	delete view;
	delete scene;
}

void GameLevelView::loadLevelView(int chargeLevel)
{
    this->chargeLevel=chargeLevel;
    // Add the level items
    displayLevel();


    // Calculate the place in the center where the player should spawn
    double spawnX = floor((screenWidth/2)/tileWidth) * tileWidth;
    double spawnY = floor((screenHeight/2)/tileHeight) * tileHeight;
    qDebug() << "Width: "<< screenWidth << ". Height: " << screenHeight << NEWLINE
            << "spawnX: " << spawnX << ". spawnY: " << spawnY;

	//add the player caracter
	player = new Player(tileWidth, tileHeight, spawnX, spawnY,this);
	player->setSkin(1);
	scene->addItem(player);

    // make player focusable
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	// Set a color background
	this->view->setBackgroundBrush(QBrush(QColor(231,180,155), Qt::SolidPattern));

	// The scene has infinite size, but we want it has the same size than the view
	this->scene->setSceneRect( this->view->rect() );

	// Disable scrollbars because they are not longer needed
	this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void GameLevelView::prueba()
{
	qDebug() << "adskfn";
}

void GameLevelView::goToMenuRequested()
{
	father->backToMenuRequested();
}

void GameLevelView::displayLevel()
{
    Level* currentLevel=levels[chargeLevel];
	rows = static_cast<double>(currentLevel->rows);
	cols = static_cast<double>(currentLevel->cols);
	imgSide = 32.0;
	tileWidth = screenWidth / cols;
	tileHeight = screenHeight / rows;
	qreal growthFactor = tileWidth / imgSide;

	qDebug() << rows << "\n" << cols << "\n" << tileWidth << "\n" << tileHeight << "\n";

	for(int row = 0; row < currentLevel->rows; ++row)
	{
		for(int col = 0; col < currentLevel->cols; ++col)
		{
			qreal posX = tileWidth * static_cast<double>(col);
			qreal posY = tileHeight * static_cast<double>(row);
			qDebug() << posX << posY;

            Tile *currentTile = createTile(currentLevel->matrix[row][col]);
			//change x and y
			currentTile->setPos( QPoint(posX, posY) );
			//transform
			currentTile->setScale( growthFactor );

            qDebug() << "tile created";
			this->scene->addItem(currentTile);
            qDebug() << "tile added to scene";
            //tiles.append(currentTile);
		}
	}
}

void GameLevelView::removeLevel(int action)
{
    Level* currentLevel=levels[chargeLevel];
    rows = static_cast<double>(currentLevel->rows);
    cols = static_cast<double>(currentLevel->cols);
    this->scene->removeItem(player);
    delete player;
    player=nullptr;

    const QList<QGraphicsItem*>& allTiles = scene->items();
    for ( QGraphicsItem* item : allTiles )
    {
        Tile* actual = dynamic_cast<Tile*>(item);
        scene->removeItem(item);
        delete actual;
    }
    manageAction(action);
}

void GameLevelView::manageAction(int action){
    if(action == 1){
        chargeLevel++;
        if(chargeLevel>9)
            chargeLevel=1;
        this->loadLevelView(chargeLevel);
    }
    if(action == 0)
        this->loadLevelView(chargeLevel);
    if(action == 2)
        goToMenuRequested();
}

Tile* GameLevelView::createTile(QChar type)
{
    if(type == '-')
        return new TileNormal(type);
    if(type == '#')
        return new TileBroken(type);
    if(type == 'O')
        return new TileSpecial(type);
    //else
    return new Tile(type);
}
