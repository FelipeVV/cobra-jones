#ifndef GAME_H
#define GAME_H

#include <QApplication>
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
};

#endif // GAME_H
