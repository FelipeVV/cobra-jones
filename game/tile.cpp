#include "tile.h"
#include <QChar>


Tile::Tile(QChar type)
{
    this->type = type;
    this->setArt();
}

void Tile::setType(QChar ch)
{
    this->type = ch;
    this->setArt();
}

QChar Tile::getType()
{
    return this->type;
}

void Tile::growUp()
{
    //qreal growFactor = this->
    //this->setScale();
}

void Tile::setArt()
{
    this->setPixmap(QPixmap(":/assets/tileUndefined.png"));
    /*
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
    */
}
