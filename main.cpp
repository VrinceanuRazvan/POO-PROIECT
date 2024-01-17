#include <iostream>
#include "Classes/Game.h"
#include "Classes/MyExceptions.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

using namespace std;

int main() {

    #ifdef __linux__
    XInitThreads();
    #endif

    Game game;

    game.run();

    try {
        Player a(-10, 10);
    } catch (const exception &e) {
        cerr << "Eroare: " << e.what() << '\n';
    }

    try {
        Player b(10, -10);
    } catch (const exception &e) {
        cerr << "Eroare: " << e.what() << '\n';
    }

    return 0;
}
