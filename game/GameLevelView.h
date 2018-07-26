#ifndef GAMELEVELVIEW_H
#define GAMELEVELVIEW_H

#include <QWidget>
#include <QVector>
#include "MainWindow.h"

class QGraphicsScene;
class QGraphicsView;
class Level;
class Tile;
class Player;

class GameLevelView: public QWidget
{
    Q_DISABLE_COPY(GameLevelView)
    friend class MainWindow;

  protected:
    /// Manages graphic items. It is an invisible manager
    QGraphicsScene* scene = nullptr;
    /// A visible widget that renders the scene
    QGraphicsView* view = nullptr;
    /// Width and height of the view
    double screenWidth = 800.0;
    double screenHeight = 600.0;
    /// Size in pixels of the squared mosaic picture used.
    double imgSide = 32.0;
    /// Size in rows and cols of the level being loaded
    double cols = 0;
    double rows = 0;
    /// Width and height
    double tileWidth = 0;
    double tileHeight = 0;
    /// Actual level
    Level* currentLevel = nullptr;
    ///
    MainWindow* father=nullptr;
    /// Player instance
    Player* player = nullptr;
    /// Tiles in the view
    QVector<Tile*> tiles;

  private:
    void loadLevelView();
    void displayLevel();
    //void keyPressEvent(QKeyEvent *event);
    //void checkCollision(bool drill = false);
    void levelFail();
    void drill();

  public:
    /// Constructor
    explicit GameLevelView(Level* currentLevel, QWidget *parent = nullptr, MainWindow* father =  nullptr);
    /// Destructor
    ~GameLevelView();
    void prueba();
    void goToMenuRequested();

  signals:
    /// Signal for communicating to mainwindow
    void goMenu();

  private slots:
    /// Slot for go to menu request from client


};

#endif // GAMELEVELVIEW_H
