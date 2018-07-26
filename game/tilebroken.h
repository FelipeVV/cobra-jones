#ifndef TILEBROKEN_H
#define TILEBROKEN_H
#include "Tile.h"


class TileBroken : public Tile
{
protected:
    QChar type;
public:
    TileBroken(QChar type);
private:
    void setArt();
};

#endif // TILEBROKEN_H
