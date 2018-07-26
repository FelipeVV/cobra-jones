#include "GameMenuView.h"
#include "ui_GameMenuView.h"
#include <QDebug>

GameMenuView::GameMenuView(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GameMenuView)
{
	// Create the user interface created with QtDesigner
	ui->setupUi(this);

	// when play button is pressed, connect that event with the MainWindow
	connect(ui->pushButton_2,&QPushButton::clicked, this, &GameMenuView::tryToPlayNewGame);

	connect(ui->pushButton,&QPushButton::clicked, this, &GameMenuView::tryToPlay);

	// value of the spinbox have been changed
	connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(changeLevelWanted(int)));
}

GameMenuView::~GameMenuView()
{
	delete ui;
}

void GameMenuView::tryToPlay()
{
	// Signal when the user want to play the game in a specific level
	emit playGame(levelWanted);
}

void GameMenuView::tryToPlayNewGame()
{
	// Signal when the user want to play new game, that means start in first level
	emit playGame(1);
}

void GameMenuView::changeLevelWanted(int level)
{
	// Change the levelWanted
	levelWanted = level;
}
