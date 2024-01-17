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

    try {
        throw CustomError("CustomError: A custom error occurred.");
    } catch (const MyException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        throw AnotherError();
    } catch (const MyException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        throw CriticalError();
    } catch (const MyException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        throw FileError("example.txt");
    } catch (const MyException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;

    return 0;
}
