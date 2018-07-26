#ifndef TILESPECIAL_H
#define TILESPECIAL_H
#include "Tile.h"

class TileSpecial : public Tile
{
protected:
    QChar type;
public:
    TileSpecial(QChar type);
private:
    void setArt();
};

#endif // TILESPECIAL_H
