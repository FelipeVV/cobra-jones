#ifndef GAMELEVELVIEW_H
#define GAMELEVELVIEW_H

#include <QWidget>
#include <QVector>
#include "mainwindow.h"

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
    int chargeLevel;

    /// Be able to know who is this instance's father/caller
	MainWindow* father=nullptr;

    /// Player instance
	Player* player = nullptr;

    /// Tiles in the view
	QVector<Tile*> tiles;

    /// levels vector
    const QVector<Level*>& levels;

  private:
    /// Function that loads level
    void loadLevelView(int chargeLevel);
    /// Load already loaded level
    void displayLevel();
    /// When player fails, this method runs
    void levelFail();
    /// create tile object depending on parameter char,
    /// which can be one of the following:
    /// O
    /// -
    /// #
    Tile* createTile(QChar type);

  public:
    /// Constructor
    explicit GameLevelView(const QVector<Level*>& levels,QWidget *parent = nullptr, MainWindow* father =  nullptr);
    /// Destructor
    ~GameLevelView();
    void removeLevel(int action);
    void goToMenuRequested();
    void manageAction(int action);

  signals:
	/// Signal for communicating to mainwindow
	void goMenu();

  private slots:
	/// Slot for go to menu request from client


};

#endif // GAMELEVELVIEW_H
