#include "MainWindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"
#include <QDebug>

MainWindow::MainWindow(const QVector<Level*>& levels, QWidget* parent)
    : QMainWindow(parent)
    , levels{levels}
{
    this->buildInterface();
    this->showGameMenu();
}

MainWindow::~MainWindow()
{
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
    GameMenuView* gameMenuView = new GameMenuView(this);
    this->setCentralWidget( gameMenuView );

    // Now the application is in game menu state
    this->state = GameState::gameMenu;
    connect(gameMenuView,SIGNAL(playGame(int)),this,SLOT(playGameRequested(int)));
}

void MainWindow::playGameRequested(int levelRequested)
{
    qDebug() << "playing level " << levelRequested;
    // create the view and scene for play the game

    // call the funtion that manage the view and scene

}
