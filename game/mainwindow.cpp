#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "MainWindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"
#include "GameLevelView.h"

MainWindow::MainWindow(const QVector<Level*>& levels, QWidget* parent)
    : QMainWindow(parent)
    , levels{levels}
{
    this->buildInterface();
    this->showGameMenu();
}

MainWindow::~MainWindow()
{
    //delete view;
    //delete scene;
    delete gameMenuView;
}

void MainWindow::buildInterface()
{
    // Set the window title
    this->setWindowTitle("Cobra Jones");

    // For desktop, resize the main window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(512,320);
  #endif
}

void MainWindow::showGameMenu()
{
    // Show a dialog to ask for player's nickname and game mode
    //GameMenuView* gameMenuView = new GameMenuView(this);
    gameMenuView = new GameMenuView(this);
    this->setCentralWidget( gameMenuView );

    // Now the application is in game menu state
    this->state = GameState::gameMenu;
    connect(gameMenuView,SIGNAL(playGame(int)),this,SLOT(playGameRequested(int)));
}

/*void MainWindow::loadLevelView(int levelToCharge)
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
    //return 0;
}*/

void MainWindow::playGameRequested(int levelRequested)
{
    qDebug() << "playing level " << levelRequested;

    // create the mannager for play the level
    this->gameLevelView = new GameLevelView(levels[levelRequested-1],this);
    this->setCentralWidget(gameLevelView);
    //delete this->gameMenuView;
    // call the funtion that manage the view and scene
    //loadLevelView(levelRequested);

}
