QT += core gui widgets svg multimedia

TARGET = MonsterCatch
TEMPLATE = app
CONFIG += c++11

HEADERS += \
	AnimatedObject.h \
	Game.h \
	Player.h \
	Score.h \
	Obstacle.h \
    zooboo.h

SOURCES += \
	main.cpp \
	AnimatedObject.cpp \
	Game.cpp \
	Player.cpp \
	Score.cpp \
	Obstacle.cpp \
    zooboo.cpp

RESOURCES += ../Resources/Resources.qrc \
    testresource.qrc
