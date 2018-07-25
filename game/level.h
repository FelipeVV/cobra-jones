#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <QChar>

class QFile;
class Level
{
    friend class GameLevelView;
    friend class MainWindow;
    Q_DISABLE_COPY(Level);
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
