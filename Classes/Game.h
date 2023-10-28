#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Tileset.h"
#include "Spell.h"
#include "Enemy.h"
#include "Player.h"

class Game {
private:

    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    const int World[10000] =
            {
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            };

    Tileset worldTileset ;

    sf::Event ev;


    Player* player;

public:

    Game();

    virtual ~Game();

    void play();

    void pollEvent();

    void update();

    void render();
};


#endif //OOP_GAME_H
