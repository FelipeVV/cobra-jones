#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QVector>

//borrar
#include "Level.h"
#include "tile.h"
class QGraphicsScene;
class QGraphicsView;


class MainWindow;
class Level;
class QFile;

class Game: public QApplication
{
    DISABLE_COPY_CLASS(Game);
  private:
    QVector<Level*> levels;
    MainWindow* mainWindow = nullptr;

  /*protected:
    // Manages graphic items. It is an invisible manager
    QGraphicsScene* scene;
    /// A visible widget that renders the scene
    QGraphicsView* view;
    double screenWidth = 800.0;
    double screenHeight = 800.0;

    QVector<Tile*> tiles;
    */
  public:
    /// Constructor
    Game(int &argc, char **argv, int flags = ApplicationFlags);
    //Game(int& argc, char **argv);
    /// Destructor
    ~Game();
    /// Call this method instead of exec()
    int run();

  private:
    /// Load level file
    int loadLevels(const int& number);
    int displayLevel(int levelIndex);
};

#endif // GAME_H
