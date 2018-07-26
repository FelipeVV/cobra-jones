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
    Tile(QChar type);
    void setType(QChar ch);
    QChar getType();
    void growUp();

  private:
    void setArt();
};

#endif // TILE_H
