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
        this->setPixmap(QPixmap(":/assets/tileNormal.png"));
    }
    if (tileType=='#')
    {
        this->setPixmap(QPixmap(":/assets/tileBroken.png"));
    }
    if (tileType=='O')
    {
        this->setPixmap(QPixmap(":/assets/tileNormal.png"));
    }
}
