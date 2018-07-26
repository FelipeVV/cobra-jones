#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>
#include "GameLevelView.h"
#include <QKeyEvent>
//#include <QWidget>

class QSoundEffect;

class Player: public QGraphicsPixmapItem
{
    //Q_OBJECT
    friend class GameLevelView;
  protected:
    GameLevelView* fatha;
    QSoundEffect* walkingSound=nullptr;
    double xWalkDistance = 0.0;
    double yWalkDistance = 0.0;
    double walk_speed = 10.0;

  public:
    ///constructor
    Player(double tileWidth, double tileHeight, double spawnX, double spawnY,GameLevelView *fatha);
    ~Player();
    /// ???
    void keyPressEvent(QKeyEvent* event);
    void drill();
    void setSkin(int skin);
    void tryGoMenu();
    void levelFail();
    bool collisionLeft();
    bool collisionRight();
    bool collisionUp();
    bool collisionDown();
    void move(QString direction);
    const QList<QGraphicsItem*> getCollidingItems();
};

#endif // PLAYER_H
