#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QVector>
#include <QString>


class MainWindow;
class Level;
class QFile;

class Game: public QApplication
{
    DISABLE_COPY_CLASS(Game);
  public:
    QString levelsDirectory = ":/assets/";
    QString levelListLocation = ":/assets/levelList.txt";
  private:
    QVector<Level*> levels;
    MainWindow* mainWindow = nullptr;

  public:
    /// Constructor
    Game(int &argc, char **argv);
    /// Destructor
    ~Game();
    /// Call this method instead of exec()
    int run();

  private:
    /// Load level file
    int loadLevels();
    int createLevel(const QString direction);
    int displayLevel(int levelIndex);
};

#endif // GAME_H
