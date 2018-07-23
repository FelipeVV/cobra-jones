#include <QTextStream>
#include <QFile>
#include <QChar>
#include <QDebug>
#include "level.h"

Level::Level(QFile &file)
{
    loadMatrix(file);
}

Level::~Level()//revisar
{
    for(int counter = 0;counter<this->rows;counter++)
        delete this->matrix[counter];
    delete this->matrix;
}

QChar Level::getChar(int row, int col)
{
    return matrix[row][col];
}

void Level::createMatrix()
{
    matrix= new QChar*[rows];
    for(int counter = 0;counter<rows;counter++)
        matrix[counter]=new QChar[cols];
}

void Level::loadMatrix(QFile &file)
{
    QChar waste;
    QChar actual;
    int actualRow = 0, actualCol = 0;
    QTextStream data(&file);
    data>>rows;
    data>>cols;
    createMatrix();
    qDebug()<<rows<<" "<<cols;
    data>>waste;data>>waste;// cambios de linea
    while(!data.atEnd())
    {
        data>>actual;
        if(actual!='\n')
        {
            matrix[actualRow][actualCol]=actual;
            actualCol++;
            //qDebug()<<actual;
        }else
        {
            actualRow++;
            actualCol=0;
            //qDebug()<<"cambio de linea";
        }
        //qDebug() << actual;
    }
}
