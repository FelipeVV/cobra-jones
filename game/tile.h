#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

class Tile : public QGraphicsPixmapItem
{
  protected:
    char type;

  public:
    void setType(char ch);
    char getType();
};

#endif // TILE_H
