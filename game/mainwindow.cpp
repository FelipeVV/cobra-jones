#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "MainWindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"
#include "GameLevelView.h"

MainWindow::MainWindow(const QVector<Level*>& levels, QWidget* parent)
    : QWidget(parent)
    , levels{levels}
{
    //this->buildInterface();
    this->showGameMenu();
    //playGameRequested(1);
}

MainWindow::~MainWindow()
{
    delete gameMenuView;
}

/*void MainWindow::buildInterface()
{
    // Set the window title
    this->setWindowTitle("Cobra Jones");

    // For desktop, resize the main window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(512,320);
  #endif
}*/

void MainWindow::showGameMenu()
{
    // Show a dialog to ask for player's nickname and game mode
    //GameMenuView* gameMenuView = new GameMenuView(this);
    gameMenuView = new GameMenuView();
    //this->setCentralWidget( gameMenuView );
    gameMenuView->show();
    // Now the application is in game menu state
    this->state = GameState::gameMenu;
    connect(gameMenuView,SIGNAL(playGame(int)),this,SLOT(playGameRequested(int)));
}

void MainWindow::playGameRequested(int levelRequested)
{
    qDebug() << "playing level " << levelRequested;

    // create the mannager to play the level
    this->gameLevelView = new GameLevelView(levels[levelRequested-1],this);
    // Hide the game menu widget
    this->gameMenuView->hide();

}
