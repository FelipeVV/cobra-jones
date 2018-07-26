#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "Game.h"
#include "MainWindow.h"
#include "Level.h"

#define NEWLINE "\n"


Game::Game(int &argc, char **argv)
    : QApplication(argc, argv)
{}

Game::~Game()
{
    delete this->mainWindow;
    // Delete each level
    for(int counter = 0; counter < levels.size();counter++)
        delete levels[counter];
}



int Game::loadLevels()
{
    // Open the file with the level names
    QFile file(levelListLocation);
    if ( ! file.open(QIODevice::ReadOnly) )
        return qDebug() << "Game: could not open LevelList" << "\n", 2;
    // For reading text from file
    QTextStream input(&file);

    int amountOfLevels = 0;

    input >> amountOfLevels;

    qDebug() << "Amount of levels: " << amountOfLevels << NEWLINE;

    QString fileName;
    // Creating levels with each file name
    for(int index = 0; index < amountOfLevels; ++index)
    {
        // Reading each line with the level name
        input >> fileName;
        // Adding assets directory
        fileName = levelsDirectory + fileName;
        qDebug() << "Found level direction: " << fileName << NEWLINE;
        // Creating level
        if(int result = createLevel(fileName)){
            file.close();
            return result;
        }
    }
    // Close the level list file
    file.close();

    return 0;
}

int Game::createLevel(const QString direction)
{
    // Open the level file
    QFile file(direction);
    if ( ! file.open(QIODevice::ReadOnly) )
        return qDebug() << "Game: could not open " << direction << "\n", 3;
    // New level with this file
    Level* level = new Level(file);
    if(level)
        levels.push_back(level);
    // Closing the level file
    file.close();
    return 0;
}

int Game::run()
{
    if( int result = loadLevels()){
        return result;
        qDebug()<<"Error al cargar niveles";
    }

    this->mainWindow = new MainWindow(this->levels);
    return exec();
}
