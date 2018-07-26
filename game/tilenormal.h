#ifndef TILENORMAL_H
#define TILENORMAL_H
#include "Tile.h"

class TileNormal : public Tile
{
protected:
    QChar type;
public:
    TileNormal(QChar type);
private:
    void setArt();
};

#endif // TILENORMAL_H
