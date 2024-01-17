#include "Classes/Game.h"
#include "Classes/MyExceptions.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {

    #ifdef __linux__
    XInitThreads();
    #endif

    Game game;

    game.run();

    return 0;
}
