#include <QFile>
#include <QDebug>
#include <iostream>
#include "game.h"
#include "mainwindow.h"
#include "level.h"

#define NEWLINE "\n"


Game::Game(int &argc, char **argv)
    : QApplication(argc, argv)
{
}

Game::~Game()
{
    //delete this->mainWindow;
}



int Game::loadLevels()
{
    QFile file(levelListLocation);
    if ( ! file.open(QIODevice::ReadOnly) )
        return qDebug() << "Game: could not open LevelList" << "\n", 2;
    QTextStream input(&file);

    int amountOfLevels = 0;
    input >> amountOfLevels;

    qDebug() << "Amount of levels: " << amountOfLevels << NEWLINE;

    QString fileName;
    for(int index = 0; index < amountOfLevels; ++index)
    {
        input >> fileName;
        fileName = levelsDirectory + fileName;
        qDebug() << "Found level direction: " << fileName << NEWLINE;
        createLevel(fileName);
    }
    file.close();

    return 0;
}

int Game::createLevel(const QString direction)
{
    QFile file(direction);
    if ( ! file.open(QIODevice::ReadOnly) )
        return qDebug() << "Game: could not open " << direction << "\n", 3;

    Level* level = new Level(file);
    if(level)
        levels.push_back(level);
    file.close();
    return 0;
}

int Game::run()
{
    if( int result = loadLevels())//numero de niveles
        return result;

    this->mainWindow = new MainWindow(this->levels);
    mainWindow->show();
    return exec();
}
