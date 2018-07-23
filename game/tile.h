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
    void growUp();

  private:
    void setArt(char tileType);
};

#endif // TILE_H
