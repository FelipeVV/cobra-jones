#include "level.h"

Level::Level(int cols, int rows)
    :rows{rows}
    ,cols{cols}
{
    matrix= new char*[rows];
    for(int counter = 0;counter<rows;counter++)
        matrix[counter]=new char[cols];
}

void Level::setValue(int row,int col,char value){
    matrix[row][col]=value;
}
