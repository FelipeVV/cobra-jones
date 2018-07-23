#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <QChar>

class QFile;
class Level
{
    //friend class Game;
    //Q_DISABLE_COPY(Level);
    //deshabilitar copias
  private:
    int rows;
    int cols;
    QChar ** matrix;

  public:
    Level(QFile& file);
    ~Level();
    QChar getChar(int row,int col);

  private:
    void loadMatrix(QFile& file);
    void createMatrix();
};

#endif // LEVEL_H
