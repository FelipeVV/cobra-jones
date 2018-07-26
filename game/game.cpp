#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "game.h"
#include "mainwindow.h"
#include "level.h"

#define NEWLINE "\n"

/// Constructor, call parent constructor
Game::Game(int &argc, char **argv)
	: QApplication(argc, argv)
{}

/// Delete main window + levels
Game::~Game()
{
	delete this->mainWindow;
    /// Delete each level
	for(int counter = 0; counter < levels.size();counter++)
		delete levels[counter];
}

/// Important function. Reads levelsList.txt, the file that tells the program what all the levels are called.
/// After reading levelsList, the function assumes they are all under ":/assets/", saved under the variable name levelsDirectory.
/// This function then creates strings with the directions and sends them to createLevel().
int Game::loadLevels()
{
    /// Open the file with the level names
	QFile file(levelListLocation);
	if ( ! file.open(QIODevice::ReadOnly) )
        return qDebug() << "Game: could not open LevelList" << NEWLINE, 2;

    /// Interpret file as input
	QTextStream input(&file);

    /// Read amount of levels
	int amountOfLevels = 0;
	input >> amountOfLevels;
	qDebug() << "Amount of levels: " << amountOfLevels << NEWLINE;
\
    /// This QString contains the name of the file that contains a single level.
    /// Example:
        /// input01.txt containing:
        /// 8 8
        /// --------
        /// -##-----
        /// --------
        /// -#---OO-
        /// -#------
        /// -#------
        /// ----###-
        /// --------
	QString fileName;

    /// Creating levels with each file name
	for(int index = 0; index < amountOfLevels; ++index)
	{
        /// Reading each line with the level name
		input >> fileName;

        /// Adding assets directory
        /// This creates the direction where the file is located.
        /// The files are all in the same place
        fileName = levelsDirectory + fileName;

        /// Creating level
        if(int result = createLevel(fileName))
        {
            /// Error handling. Function createLevel(filename) should idealy return 0.
            file.close();
			return result;
		}
	}
    /// Close the level list file
	file.close();

	return 0;
}

/// This function creates an individual Level instance and adds it to the vector containing all levels.
/// Parameter direction contains the exact direction of the level##.txt file.
/// Example:
/// ":/assets/level02.txt"
int Game::createLevel(const QString direction)
{
    /// Open the level file
	QFile file(direction);
	if ( ! file.open(QIODevice::ReadOnly) )
		return qDebug() << "Game: could not open " << direction << "\n", 3;

    /// New level with this file
    /// Send created level the task to interpret file
	Level* level = new Level(file);

    /// If level!=nullptr, add to the list
    if(level)
		levels.push_back(level);

    /// Closing the level file
	file.close();
	return 0;
}

int Game::run()
{
    /// Call function LoadLevels
    if( int result = loadLevels())
    {
        /// Error handling, error while loading levels
        return result;
		qDebug()<<"Error al cargar niveles";
	}

    /// Create mainWindow. mainWindow will have the task to manage views and levels meta data(rows, cols, matrix)
	this->mainWindow = new MainWindow(this->levels);
	mainWindow->hide();

    /// exec
    return exec();
}
