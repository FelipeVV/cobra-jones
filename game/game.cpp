#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTextStream>
#include <QFile>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <iostream>

#include "game.h"
#include "level.h"
#include "Player.h"
#include "tile.h"

Game::Game(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
{
}

Game::~Game()
{
    delete this->scene;
    delete this->view;
}

int Game::loadLevels()
{
    const char* const filename = ":/assets/levels.txt";
    QFile file(filename);
    if ( ! file.open(QIODevice::ReadOnly) )
        return qDebug() << "Game: could not open " << filename << "\n", 2;

    //creating new level
    int rows,cols;
    char waste;
    char actual;
    int actualRow = 0, actualCol = 0;
    QTextStream data(&file);
    data>>rows;
    data>>cols;
    Level *levelOne = new Level(rows,cols);
    data>>waste;data>>waste;// cambios de linea
    while(!data.atEnd())
    {
        data>>actual;
        if(actual!='\n')
        {
            levelOne->matrix[actualRow][actualCol]=actual;
            actualCol++;
        }else
        {
            actualRow++;
            actualCol=0;
        }
        qDebug() << actual;
    }
    levels.append(levelOne);
    file.close();
    return 0;
}

int Game::displayLevel(int levelIndex)
{
    double rows = static_cast<double>(levels[levelIndex]->rows);
    double cols = static_cast<double>(levels[levelIndex]->cols);
    double imgSide = 32.0;
    double tileWidth = screenWidth / cols;
    double tileHeight = screenHeight / rows;
    qreal growthFactor = tileWidth / imgSide;

    qDebug() << rows << "\n" << cols << "\n" << tileWidth << "\n" << tileHeight << "\n";

    for(int row = 0; row < levels[levelIndex]->rows; ++row)
    {
        for(int col = 0; col < levels[levelIndex]->cols; ++col)
        {
            qreal posX = tileWidth * static_cast<double>(col);
            qreal posY = tileHeight * static_cast<double>(row);
            qDebug() << posX << posY;

            Tile *currentTile = new Tile();
            currentTile->setType(levels[levelIndex]->matrix[row][col]);
            //change x and y
            currentTile->setPos( QPoint(posX, posY) );
            //transform
            currentTile->setScale( growthFactor );

            qDebug() << "rect created";
            this->scene->addItem(currentTile);
            qDebug() << "rect added to scene\n";
            //tiles.append(currentTile);
        }
    }
    return 0;
}

int Game::run()
{
    loadLevels();
    //MainWindow.run();
    
    // An invisible object that manages all the items
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, screenWidth, screenHeight);
    displayLevel(0);

    //add the player caracter
    Player* playerCharacter = new Player();
    playerCharacter->setSkin(1);
    scene->addItem(playerCharacter);

    // make rect focusable
    playerCharacter->setFlag(QGraphicsItem::ItemIsFocusable);
    playerCharacter->setFocus();

    // A visible rectangle of the scene
    this->view = new QGraphicsView(this->scene);//fatha as argument
    view->setFixedSize(screenWidth, screenHeight);

    // Set a black color background or add an image as a background
    this->view->setBackgroundBrush(QBrush(Qt::darkCyan, Qt::SolidPattern));

    // The scene has infinite size, but we want it has the same size than the view
    this->scene->setSceneRect( this->view->rect() );

    // Disable scrollbars because they are not longer needed
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Play background music
    //playBackgroundMusic("FunkGameLoop32m.mp3");

    // Show the view and enter in application's event loop
    this->view->show();
    return exec();
}
