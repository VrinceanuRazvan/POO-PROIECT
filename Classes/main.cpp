#include "Game.h"


int main() {
    Game game;

    while(game.getisWindowOpen())
    {
        game.update();

        game.render();
    }

    return 0;
}
