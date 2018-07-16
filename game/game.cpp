#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTextStream>
#include <QFile>
#include <QGraphicsPixmapItem>

#include <iostream>

#include "game.h"
#include "level.h"
#include "MyRect.h"

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
        return std::cerr << "Game: could not open " << filename << std::endl, 2;

    //creating new level
    int rows,cols;
    char waste;
    char actual;
    int actualRow = 0, actualCol = 0;
    QTextStream data(&file);
    data>>rows;
    data>>cols;
    //std::cout<<rows<<cols<<std::endl;
    Level levelOne(rows,cols);
    data>>waste;data>>waste;// cambios de linea
    while(!data.atEnd())
    {
        data>>actual;
        if(actual!='\n')
        {
            levelOne.matrix[actualRow][actualCol]=actual;
            actualCol++;
        }else
        {
            actualRow++;
            actualCol=0;
        }
        std::cout<<actual;
    }

    file.close();
    return 0;
}

int Game::run()
{
    loadLevels();
    // Init the random seed
    //qsrand(QTime::currentTime().msec());

    // An invisible object that manages all the items
    this->scene = new QGraphicsScene();

    //add the player caracter
    // Create, put size and add rect to the scene
    MyRect* playerCharacter = new MyRect();
    //rect->setRect(0, 0, 75, 75);
    playerCharacter->setPixmap(QPixmap(":/assets/avatar.png"));
    scene->addItem(playerCharacter);
    // make rect focusable
    playerCharacter->setFlag(QGraphicsItem::ItemIsFocusable);
    playerCharacter->setFocus();
    // A visible rectangle of the scene
    this->view = new QGraphicsView(this->scene);//fatha as argument
  //#if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->view->resize(800, 600);
  //#endif
    //
    //  where factorX = 1.0, no changes
    // factor es el que quiero entre el que tengo
    // boundingBox() da el que tengo  con .width
    //transforn object->setTransform(QTransform().scale(factorX,factorY));
    //
    //
    // Set a black color background or add an image as a background
    this->view->setBackgroundBrush(QBrush(Qt::darkCyan, Qt::SolidPattern));
    //scene->addItem( new QGraphicsPixmapItem(QPixmap(":/assets/Background.png")) );
//    QPixmap pim(":/Background.png");
//    view->setBackgroundBrush(pim);

    // The scene has infinite size, but we want it has the same size than the view
    // This stops the weird behavior of the autoscroll feature of the view being smaller than the
    // scene, because the scene auto-increases when objects are moved
    this->scene->setSceneRect( this->view->rect() );

    // Disable scrollbars because they are not longer needed
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Load the graphic resources
    //this->svgRenderer = new QSvgRenderer(QString("://assets.svg"), this);

    // Create the player control
    /*this->player = new Player();
    this->player->setSharedRenderer(svgRenderer);
    this->scene->addItem(this->player);
    this->player->setInitialPos();*/

    // Launch an enemy periodically
    /*QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::launchObstacle);
    timer->start(1500);*/

    // Play background music
    //playBackgroundMusic("FunkGameLoop32m.mp3");

    // Show the view and enter in application's event loop
    this->view->show();
    return exec();
}
