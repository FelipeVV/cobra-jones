#ifndef LEVEL_H
#define LEVEL_H
#include <vector>


class Level
{
    friend class Game;
  private:
    int rows;
    int cols;
    //std::vector<std::vector<char>> matrix;
    char ** matrix;

  public:
    Level(int cols, int rows);
    void setValue(int row, int col, char value);
};

#endif // LEVEL_H
