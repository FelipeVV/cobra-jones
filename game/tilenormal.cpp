#include "tilenormal.h"


TileNormal::TileNormal(QChar type)
    : Tile::Tile(type)
{
    this->setArt();
}

void TileNormal::setArt()
{
    this->setPixmap(QPixmap(":/assets/tileNormal.png"));
}
