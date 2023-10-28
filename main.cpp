#include "Classes/Game.h"
#include <chrono>
#include <thread>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {

    #ifdef __linux__
    XInitThreads();
    #endif

    Game game;

    game.play();

    return 0;
}
