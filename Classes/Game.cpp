#include "Game.h"
///Constructor Deconstractor

Game::Game() {
    Weapon DefaultWeapon(1.2);

    player.setWeapon(DefaultWeapon);

    videoMode.width = 1280;
    videoMode.height = 768;
    window.create(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);

    if (!worldTileset.load("Assets/Grass.jpg", sf::Vector2u(64, 64), World, 20, 12)) {
        std::cout << "Error";
    }

    // Add enemies to the vector
    enemies.emplace_back();
    enemies.emplace_back();
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

void Game::play() {
    player.Spawn(100, 100);
    player.GetSpellSet("Spells.txt", 2);

    // Set initial positions for enemies
    enemies[0].Spawn(200, 200);
    enemies[1].Spawn(300, 300);

    enemies[0].GetSpellSet("Spells.txt", 2);
    enemies[1].GetSpellSet("Spells.txt", 2);

    while (window.isOpen()) {
        update();
        render();
    }
}

void Game::update() {
    this->pollEvent();

    for (auto &enemy: enemies) {
        enemy.move();
    }

    // Check for collisions with enemies
    for (auto &enemy: enemies) {
        if (player.getSprite().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())) {
            std::cout << "Player and enemy collided!" << std::endl;
            player.Spawn(500, 500);
            startCombat(enemy);
            player.setHp(100);
            enemy.setHp(100);
        }
    }
}

void Game::render() {
    window.clear();
    window.draw(worldTileset);

    // Draw all enemies
    for (auto &enemy: enemies) {
        window.draw(enemy);
    }

    window.draw(player);
    window.display();
}

void Game::startCombat(Enemy &enemy) {
    Enemy *currentEnemy = &enemy;

    // Display combat message or UI
    std::cout << "Combat Started with Enemy!" << std::endl;

    while (player.getHp() > 0 && currentEnemy->getHp() > 0) {
        // Player's turn
        player.Attack(*currentEnemy);
        if (currentEnemy->getHp() <= 0) {
            std::cout << "Enemy has been defeated! Player wins!" << std::endl;
            break;
        }

        // Enemy's turn
        currentEnemy->Attack(player);
        if (player.getHp() <= 0) {
            std::cout << "Player has been defeated! Enemy wins!" << std::endl;
            break;
        }
    }

    // Reset currentEnemy after combat
    currentEnemy = nullptr;
    std::cout << "Combat Ended!" << std::endl;
}


/*void Game::checkCombatResult() {
    if (player.getHp() <= 0 && enemy.getHp() <= 0) {
        std::cout << "It's a draw! Both player and enemy have been defeated." << std::endl;
    } else if (player.getHp() <= 0) {
        std::cout << "Player has been defeated! Enemy wins!" << std::endl;
    } else if (enemy.getHp() <= 0) {
        std::cout << "Enemy has been defeated! Player wins!" << std::endl;
    }
}*/