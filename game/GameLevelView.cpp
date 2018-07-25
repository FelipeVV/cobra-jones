#include "GameLevelView.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QColor>

#include "Player.h"
#include "tile.h"
#include "level.h"

void GameLevelView::loadLevelView()
{
    // Add the level items
    displayLevel();

    //add the player caracter
    Player* playerCharacter = new Player();
    playerCharacter->setSkin(1);
    scene->addItem(playerCharacter);

    // make rect focusable
    playerCharacter->setFlag(QGraphicsItem::ItemIsFocusable);
    playerCharacter->setFocus();

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

GameLevelView::GameLevelView(Level *currentLevel, QWidget *parent)
  : QWidget(parent)
  , currentLevel(currentLevel)
    {
        // An invisible object that manages all the items
        this->scene = new QGraphicsScene();
        this->scene->setSceneRect(0, 0, screenWidth, screenHeight);
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

void GameLevelView::displayLevel()
{
    double rows = static_cast<double>(currentLevel->rows);
    double cols = static_cast<double>(currentLevel->cols);
    double imgSide = 32.0;
    double tileWidth = screenWidth / cols;
    double tileHeight = screenHeight / rows;
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
