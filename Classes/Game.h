#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Tileset.h"
#include <vector>
#include <iostream>

class Game {
public:
    Game();

    ~Game();

    void run();

private:
    sf::RenderWindow window;
    sf::Event ev;
    sf::VideoMode videoMode;
    Tileset worldTileset;
    std::vector<Enemy> enemies;
    Player player;
    bool inCombat;

    const int World[200] = {0};

    sf::RectangleShape combatMenuBackground;
    std::vector<sf::RectangleShape> spellButtons;

    sf::Text playerHPText;
    sf::Text enemyHPText;
    sf::Text combatLogText;

    void pollEvent();
    void update();
    void render();
    void startCombat(Enemy &enemy);
};

#endif // GAME_H
