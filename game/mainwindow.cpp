#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "mainwindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"
#include "GameLevelView.h"

/// Run parent constructor
MainWindow::MainWindow(const QVector<Level*>& levels, QWidget* parent)
	: QWidget(parent)
	, levels{levels}
{
	this->showGameMenu();

    /// Signal for when player presses 'new game' button or 'choose level' button.
    connect(gameMenuView,SIGNAL(playGame(int)),this,SLOT(playGameRequested(int)));
}

/// Destructor
MainWindow::~MainWindow()
{
	delete gameMenuView;
}

/// Create level view and tell it to show itself.
void MainWindow::showGameMenu()
{
    /// Create menuView
	gameMenuView = new GameMenuView();

    /// Show it
	gameMenuView->show();

    /// Change state to gameMenu!
	this->state = GameState::gameMenu;
}

/// This method is 'called' from a method in gameMenuView
/// Requests to play a level. Which level, the one in parameters.
void MainWindow::playGameRequested(int levelRequested)
{
    /// Update level requested
    requested = levelRequested;
    qDebug() << "Requested level: " << levelRequested;

    /// Change state to playing!
    this->state = GameState::playing;

    /// Create the manager(GameLevelView) to play the level
    this->gameLevelView = new GameLevelView(levels,this);

    /// Load the level requested, from the vector containing level meta data(rows, cols, matrix)
    this->gameLevelView->loadLevelView(requested-1);

    /// Hide the game menu widget
    this->gameMenuView->hide();
    delete gameMenuView;
}

void MainWindow::backToMenuRequested()
{
    this->showGameMenu();
}
