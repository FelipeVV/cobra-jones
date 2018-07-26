#include "tilespecial.h"

TileSpecial::TileSpecial(QChar type)
    : Tile::Tile(type)
{
    this->setArt();
}

void TileSpecial::setArt()
{
    this->setPixmap(QPixmap(":/assets/tileSpecial.png"));
}
