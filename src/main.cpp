#include "game.h"

Game game(512, 512);

    int main(int argc, char *argv[])
{

    if (!game.init("My window"))
    {
        return -1;
    }
    while (game.running())
    {
        game.handelEvent();
        game.update();
        game.render();
    }

    return 0;
}