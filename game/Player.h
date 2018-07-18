#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
class QSoundEffect;

class Player: public QGraphicsPixmapItem
{

  public:
    ///constructor
    Player();
    /// Called if this object has the focus and a key is pressed by user
    void keyPressEvent(QKeyEvent* event);
    /// ???
    void drill();
    void setSkin(int skin);
  protected:
    QSoundEffect* walkingSound=nullptr;
};

#endif // PLAYER_H
