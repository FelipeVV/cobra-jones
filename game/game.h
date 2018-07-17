#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QVector>
#include "Level.h"
#include "tile.h"

class QGraphicsScene;
class QGraphicsView;

class Game: public QApplication
{
    //Q_DISABLE_COPY(Game)
    DISABLE_COPY_CLASS(Game);

  protected:
    // Manages graphic items. It is an invisible manager
    QGraphicsScene* scene;
    /// A visible widget that renders the scene
    QGraphicsView* view;
    double screenWidth = 592.0;
    double screenHeight = 592.0;
    QVector<Level*> levels;
    QVector<Tile*> tiles;

  public:
    /// Constructor
    Game(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~Game();
    /// Call this method instead of exec()
    int run();

  private:
    /// Load level file
    int loadLevels();
    int displayLevel();
};

#endif // GAME_H
