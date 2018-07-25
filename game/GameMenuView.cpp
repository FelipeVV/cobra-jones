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
    connect(ui->pushButton,&QPushButton::clicked, this,GameMenuView::tryToPlay);

    // value of the spinbox have been changed
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(changeLevelWanted(int)));
}

GameMenuView::~GameMenuView()
{
    delete ui;
}

void GameMenuView::tryToPlay()
{
    // Signal when the user want to play the game, the parameter is the level to charge
    emit playGame(levelWanted);
}

void GameMenuView::changeLevelWanted(int level)
{
    // Change the levelWanted
    levelWanted = level;
}
