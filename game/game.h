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
  public:
    /// All levels are in the assets directory
	QString levelsDirectory = ":/assets/";
    /// Document that contain levels names, if want add more levels modify this file
	QString levelListLocation = ":/assets/levelList.txt";
  private:
    /// Vector that holds all the level's data (rows, cols, matrix)
    QVector<Level*> levels;
    /// MainWindow
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
    /// Create each level with their specific file name
	int createLevel(const QString direction);

};

#endif // GAME_H
