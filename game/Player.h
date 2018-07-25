#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
class QSoundEffect;

class Player: public QGraphicsPixmapItem
{

  public:
    ///constructor
    Player(double tileHeight, double tileWidth);
    /// Called if this object has the focus and a key is pressed by user
    void keyPressEvent(QKeyEvent* event);
    /// ???
    void drill();
    void setSkin(int skin);
  protected:
    QSoundEffect* walkingSound=nullptr;
    double xWalkDistance = 0.0;
    double yWalkDistance = 0.0;
    double walk_speed = 10.0;
};

#endif // PLAYER_H
