#include "MainWindow.h"
//#include "ui_mainwindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"

/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}*/

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
    this->setWindowTitle("La Cobra que no cobra :'D");

    // For desktop, resize the main window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->resize(320, 480);
  #endif
}

void MainWindow::showGameMenu()
{
    // Show a dialog to ask for player's nickname and game mode
    GameMenuView* gameMenuView = new GameMenuView(this);
    this->setCentralWidget( gameMenuView );

    // Now the application is in game menu state
    //this->state = GameState::gameMenu;
}


/*MainWindow::~MainWindow()
{
    //delete ui;
}*/
