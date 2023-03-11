#include "Game.h"

using namespace sf;

int main()
{
    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    //Init Game engine
    Game game;

    //Game loop
    while (game.getWindowIsOpen())
    {

        //Update
        game.update();

        //Render
        game.render();
    }

    //End of application
    return 0;
}