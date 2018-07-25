#include "tile.h"
#include <QChar>


void Tile::setType(QChar ch)
{
    this->type = ch;
    this->setArt(ch);
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

void Tile::setArt(QChar tileType)
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
