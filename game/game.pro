#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T13:03:07
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CobraJones
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        Main.cpp \
        Game.cpp \
    Level.cpp \
    Player.cpp \
    Tile.cpp \
    MainWindow.cpp \
    GameMenuView.cpp \
    GameLevelView.cpp \
    holeanimation.cpp

HEADERS += \
        Game.h \
    Level.h \
    Player.h \
    Tile.h \
    MainWindow.h \
    GameMenuView.h \
    GameLevelView.h \
    holeanimation.h

FORMS += \
    GameMenuView.ui

RESOURCES += \
    ../assets/resources.qrc
