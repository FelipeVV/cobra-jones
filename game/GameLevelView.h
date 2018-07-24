#ifndef GAMELEVELVIEW_H
#define GAMELEVELVIEW_H

#include <QWidget>
#include <QVector>

/*namespace Ui {
class GameLevelView;
}*/

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

  /*private:
    Ui::GameLevelView *ui;*/

  public:
    /// Constructor
    explicit GameLevelView(QWidget *parent = nullptr);
    /// Destructor
    ~GameLevelView();

};

#endif // GAMELEVELVIEW_H
