#include "tile.h"


void Tile::setType(char ch)
{
    this->type = ch;
    this->setArt(ch);
}

char Tile::getType()
{
    return this->type;
}

void Tile::setArt(char tileType)
{
    if (tileType=='-')
    {
        this->setPixmap(QPixmap(":/assets/floor.png"));
    }
    if (tileType=='#')
    {
        this->setPixmap(QPixmap(":/assets/floor_dark.png"));
    }
    if (tileType=='O')
    {
        this->setPixmap(QPixmap(":/assets/floor.png"));
    }
}
