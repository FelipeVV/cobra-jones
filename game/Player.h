#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem
{

  public:
    //void Player();
    void keyPressEvent(QKeyEvent* event);
};

#endif // PLAYER_H
