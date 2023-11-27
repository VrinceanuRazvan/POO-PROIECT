#include "Game.h"
///Constructor Deconstractor

Game::Game() {

    videoMode.width = 1280;
    videoMode.height = 768;
    window.create(videoMode,"Game",sf::Style::Titlebar | sf::Style::Close);

    if (!worldTileset.load("Assets/Grass.jpg", sf::Vector2u(64, 64), World, 20, 12))
    {
        std::cout<<"Erorr";
    }
}

Game::~Game() = default;

///Functions

void Game::pollEvent() {
    while(this->window.pollEvent(this->ev))
    {

        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window.close();
                break;

            case sf::Event::KeyPressed:
                player.move();
                if(this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window.close();
                }
                break;
            default:
                break;
        }
    }
}

void Game::play(){
    //player.spawn(sf::Vector2f (videoMode.width/2,videoMode.height/2));

    enemy.GetRandomSpellSet("Spells.txt", 2);
    player.GetRandomSpellSet("Spells.txt", 2);

    player.Spawn(100, 100);
    enemy.Spawn(100, 200);

    enemy.setHp(100);
    player.setHp(100);

    while(window.isOpen())
    {
        update();

        render();
    }
}

void Game::update() {
    this->pollEvent();

    if (player.getSprite().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())) {
        std::cout << "Player and enemy collided!" << std::endl;
        //float X = player.getSprite().getPosition().x;
        //float Y = player.getSprite().getPosition().y;
        player.Spawn(500, 500);
        startCombat();

        player.setHp(100);
        enemy.setHp(100);

        //player.Spawn(X,Y);

    }

}

void Game::render() {
    window.clear();
    window.draw(worldTileset);
    window.draw(enemy);
    window.draw(player);
    window.display();
}

void Game::startCombat() {
    // Display combat message or UI
    std::cout << "Combat Started!" << std::endl;

    while (player.getHp() > 0 && enemy.getHp() > 0) {
        // Player's turn
        player.Attack(enemy);
        if (enemy.getHp() <= 0) {
            break;
        }

        // Enemy's turn
        enemy.Attack(player);
        if (player.getHp() <= 0) {
            break;
        }
    }

    // Combat has ended
    checkCombatResult();
    std::cout << "Combat Ended!" << std::endl;
}


void Game::checkCombatResult() {
    if (player.getHp() <= 0 && enemy.getHp() <= 0) {
        std::cout << "It's a draw! Both player and enemy have been defeated." << std::endl;
    } else if (player.getHp() <= 0) {
        std::cout << "Player has been defeated! Enemy wins!" << std::endl;
    } else if (enemy.getHp() <= 0) {
        std::cout << "Enemy has been defeated! Player wins!" << std::endl;
    }
}