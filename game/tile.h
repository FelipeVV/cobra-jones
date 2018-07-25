#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QChar>

class Tile : public QGraphicsPixmapItem
{
  protected:
    QChar type;

  public:
    void setType(QChar ch);
    QChar getType();
    void growUp();

  private:
    void setArt(QChar tileType);
};

#endif // TILE_H
