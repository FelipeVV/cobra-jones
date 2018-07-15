#include <QGraphicsView>
#include <QGraphicsScene>

#include "game.h"

Game::Game(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
{
}

Game::~Game()
{
    delete this->scene;
    delete this->view;
}

int Game::run()
{
    if(int loaded = this->loadLevels() )
        return loaded;
    // Init the random seed
    //qsrand(QTime::currentTime().msec());

    // An invisible object that manages all the items
    this->scene = new QGraphicsScene();

    // A visible rectangle of the scene
    this->view = new QGraphicsView(this->scene);//fatha as argument
  //#if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->view->resize(800, 600);
  //#endif

    // Set a black color background or add an image as a background
    this->view->setBackgroundBrush(QBrush(Qt::darkCyan, Qt::SolidPattern));
//    scene->addItem( new QGraphicsPixmapItem(QPixmap("://Background.png")) );
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
