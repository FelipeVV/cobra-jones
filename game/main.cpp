#include "game.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    Game game(argc, argv);

    return game.run();
}
