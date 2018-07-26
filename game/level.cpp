#include <QTextStream>
#include <QChar>
#include <QDebug>
#include <iostream>

#include "level.h"

Level::Level(QFile &file)
{
	loadMatrix(file);
}

Level::~Level()
{
	/// Deleting matrix
	for(int counter = 0;counter<this->rows;counter++)
		delete[] this->matrix[counter];
	delete[] this->matrix;
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
    // Create variables to read matrix data
    char waste;
    QChar actual;

    // For managing the data in the file
	QTextStream data(&file);

	// Reading rows and cols
    data >> rows >> cols;

    // Reserving memory for matrix
	createMatrix();
    //qDebug()<<rows<<" "<<cols;

    data >> waste;
    //std::cout << "{" << waste << "}";
    data >> waste;
    //std::cout << "{" << waste << "}";

    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            char ch = 'X';
            data >> ch;
            std::cout << "[" << ch << "]";
            matrix[row][col] = ch;
        }
        data >> waste;
        //std::cout << "{" << waste << "}";
        data >> waste;
        //std::cout << "{" << waste << "}";
        std::cout << "\n";
    }

    std::cout << "\n";

    //qDebug()<<"Level reading complete.\n";
}
