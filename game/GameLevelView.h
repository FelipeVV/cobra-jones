#ifndef GAMELEVELVIEW_H
#define GAMELEVELVIEW_H

#include <QWidget>
#include <QVector>

class QGraphicsScene;
class QGraphicsView;
class Level;
class Tile;

class GameLevelView: public QWidget
{
    //DISABLE_COPY_CLASS(GameLevelView);

  protected:
    /// Manages graphic items. It is an invisible manager
    QGraphicsScene* scene = nullptr;
    /// A visible widget that renders the scene
    QGraphicsView* view = nullptr;
    /// Width and height of the view
    double screenWidth = 800.0;
    double screenHeight = 600.0;
    /// Actual level
    Level* currentLevel = nullptr;
    /// Tiles in the view
    QVector<Tile*> tiles;

  private:
    void loadLevelView();
    void displayLevel();

  public:
    /// Constructor
    explicit GameLevelView(Level* currentLevel, QWidget *parent = nullptr);
    /// Destructor
    ~GameLevelView();

};

#endif // GAMELEVELVIEW_H
