#include "tilebroken.h"

TileBroken::TileBroken(QChar type)
    : Tile::Tile(type)
{
    this->setArt();
}

void TileBroken::setArt()
{
    this->setPixmap(QPixmap(":/assets/tileBroken.png"));
}
