#include <QTextStream>
#include <QFile>
#include <QChar>
#include <QDebug>

#include "level.h"

Level::Level(QFile &file)
{
    // charge the matrix from file
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
    // Return the char in the matrix in this row,col value
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
    // Variables for load from the file the chars
    QChar waste, actual;
    // For manage where is saved each char
    int actualRow = 0, actualCol = 0;
    // For manage the data in the file
    QTextStream data(&file);
    // Reading rows and cols
    data>>rows>>cols;
    // Reserving memory for matrix
    createMatrix();
    qDebug()<<rows<<" "<<cols;
    // Every line change is sent to the trash because it is not loaded into the matrix
    data>>waste;data>>waste;
    // Reading file
    while(!data.atEnd())
    {
        data>>actual;
        if(actual!='\n')// Its a valid char
        {
            matrix[actualRow][actualCol]=actual;// Adding char to matrix
            actualCol++;
            //qDebug()<<actual;
        }
        else // Its the end of a line, the row value increase and the cols starts from 0 again
        {
            actualRow++;
            actualCol=0;
            //qDebug()<<"cambio de linea";
        }
    }
}
