#include "GameLevelView.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QtMath>
#include <QDebug>
#include <QKeyEvent>

#include "Player.h"
#include "Tile.h"
#include "Level.h"


#define NEWLINE "\n"

GameLevelView::GameLevelView(Level *currentLevel, QWidget *parent, MainWindow *father)
  : QWidget(parent)
  , currentLevel(currentLevel)
    {
        // An invisible object that manages all the items
        this->scene = new QGraphicsScene();
        this->scene->setSceneRect(0, 0, screenWidth, screenHeight);
        this->father = father;
        // A visible rectangle of the scene
        this->view = new QGraphicsView(this->scene);
        view->setFixedSize(screenWidth, screenHeight);
        loadLevelView();
    }

GameLevelView::~GameLevelView()
{
    delete view;
    delete scene;
}

void GameLevelView::loadLevelView()
{
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

    // make f focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Set a color background
    this->view->setBackgroundBrush(QBrush(QColor(231,180,155), Qt::SolidPattern));

    // The scene has infinite size, but we want it has the same size than the view
    this->scene->setSceneRect( this->view->rect() );

    // Disable scrollbars because they are not longer needed
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Show the view and enter in application's event loop
    this->view->show();
}

/*void GameLevelView::keyPressEvent(QKeyEvent *event)
{

    // React to input
    if((event->key() == Qt::Key_Left) && !player->collisionLeft() )
    {
        player->move("left");
        qDebug()<<"hereeeeee";
    }

    if( (event->key() == Qt::Key_Right) && !player->collisionRight())
    {
        player->move("right");
    }

    if( (event->key() == Qt::Key_Up) && !player->collisionUp() )
    {
        player->move("up");
    }

    if( (event->key() == Qt::Key_Down) && !player->collisionDown() )
    {
        player->move("down");
    }
    if(event->key() == Qt::Key_Space)
    {
        this->drill();
    }
    if(event->key() == Qt::Key_P)
    {
        qDebug()<<"cierrelo papi ";
    }
    checkCollision();
}*/

void GameLevelView::levelFail()
{
    qDebug() << "lvl failed\n";
    /*
    holeAnimation* hole = new holeAnimation(0, 0, 100, 100, 0, 0);
    scene->addItem(hole);*/
}

/*void GameLevelView::drill()
{
    checkCollision(true);
}*/

/*void GameLevelView::checkCollision(bool drill)
{
    const QList<QGraphicsItem*>& playerCollidingItems = player->getCollidingItems();
    for ( QGraphicsItem* item : playerCollidingItems )
    {
        Tile* actual = dynamic_cast<Tile*>(item);
        if ( (actual) && (!drill))
        {
            if(actual->getType()=='#'){
                //actual->growUp();
                //qreal growFactor =
                levelFail();
                //actual->setScale( growthFactor );
            }
        }
        if ((actual) && (drill))
        {
            // Play the collision sound
            if(actual->getType()=='O')
                qDebug() << "lvl passed \n";
            if(actual->getType()=='-')
                levelFail();

        }
    }
}*/


void GameLevelView::prueba()
{
    qDebug() << "adskfn";
}

/*void GameLevelView::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_P)
        emit goMenu();
}*/

void GameLevelView::goToMenuRequested()
{
    father->backToMenuRequested();
}

void GameLevelView::displayLevel()
{
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

            Tile *currentTile = new Tile();
            currentTile->setType(currentLevel->matrix[row][col]);
            //change x and y
            currentTile->setPos( QPoint(posX, posY) );
            //transform
            currentTile->setScale( growthFactor );

            qDebug() << "rect created";
            this->scene->addItem(currentTile);
            qDebug() << "rect added to scene\n";
            tiles.append(currentTile);
        }
    }
}
