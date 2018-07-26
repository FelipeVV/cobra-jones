#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "mainwindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"
#include "GameLevelView.h"

MainWindow::MainWindow(const QVector<Level*>& levels, QWidget* parent)
	: QWidget(parent)
	, levels{levels}
{
	//this->buildInterface();
	this->showGameMenu();
	// When player press new game button or chose level button
	connect(gameMenuView,SIGNAL(playGame(int)),this,SLOT(playGameRequested(int)));
	//connect(gameLevelView,SIGNAL(goMenu()),this,SLOT(backToMenuRequested()));
}

MainWindow::~MainWindow()
{
	delete gameMenuView;
}

void MainWindow::showGameMenu()
{
	// Show a dialog to ask for player's nickname and game mode
	gameMenuView = new GameMenuView();
	//this->setCentralWidget( gameMenuView );
	gameMenuView->show();
	// Now the application is in game menu state
	this->state = GameState::gameMenu;
}

void MainWindow::playGameRequested(int levelRequested)
{
    requested = levelRequested;
    qDebug() << "playing level " << levelRequested;
    // Now the application is in playing state
    this->state = GameState::playing;

    // Create the mannager to play the level
    this->gameLevelView = new GameLevelView(levels,this);
    this->gameLevelView->loadLevelView(requested-1);
    //this->gameLevelView->removeLevel();
    //gameLevelView->isActiveWindow();
    //gameLevelView->setFocus();*/
    // Hide the game menu widget
    this->gameMenuView->hide();
    delete gameMenuView;
    // Back to menu requested

}

void MainWindow::backToMenuRequested()
{
    this->showGameMenu();
}
