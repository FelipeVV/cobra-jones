#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <QChar>
#include <QFile>

class Level
{
    friend class GameLevelView;
    Q_DISABLE_COPY(Level);
  private:
    int rows;
    int cols;
    QChar ** matrix;

  public:
    /// Cosntructor
    Level(QFile& file);
    /// Desctructor
    ~Level();
    /// Return char in the matrix in these row and col
    QChar getChar(int row,int col);

  private:
    /// Load matrix from file
    void loadMatrix(QFile& file);
    /// Reserve the needed memory to charge matrix
    void createMatrix();
};

#endif // LEVEL_H
