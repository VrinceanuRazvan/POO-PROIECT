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

    enemies.emplace_back();
    enemies.emplace_back();

    inCombat = false;

    combatMenuBackground.setSize(sf::Vector2f(400.f, 200.f));
    combatMenuBackground.setFillColor(sf::Color(0, 0, 0, 200));
    combatMenuBackground.setPosition(20.f, 20.f);

    //playerHPText.setFont(font);
    playerHPText.setCharacterSize(16);
    playerHPText.setPosition(30.f, 30.f);

    //enemyHPText.setFont(font);
    enemyHPText.setCharacterSize(16);
    enemyHPText.setPosition(30.f, 70.f);

    //combatLogText.setFont(font);
    combatLogText.setCharacterSize(16);
    combatLogText.setPosition(30.f, 110.f);

    for (int i = 0; i < player.getSpellCount(); ++i) {
        sf::RectangleShape button(sf::Vector2f(100.f, 40.f));
        button.setFillColor(sf::Color::Green); // Button color
        button.setPosition(20.f, 250.f + i * 50.f); // Adjust the position as needed
        spellButtons.push_back(button);
    }

}

Game::~Game() = default;

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

void Game::run() {

    player.Spawn(100, 100);
    player.GetSpellSet("Spells.txt", 2);

    // Set initial positions for enemies
    enemies[0].Spawn(200, 200);
    enemies[1].Spawn(300, 300);

    enemies[0].GetSpellSet("Spells.txt", 2);
    enemies[1].GetSpellSet("Spells.txt", 2);

    while (window.isOpen()) {
        pollEvent();
        update();
        render();
    }
}

void Game::update() {
    for (auto &enemy: enemies) {
        enemy.move();
    }

    for (auto &enemy: enemies) {
        if (!inCombat && player.getSprite().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())) {
            inCombat = true;
            startCombat(enemy);

            spellButtons.clear();

            for (int i = 0; i < player.getSpellCount(); ++i) {
                sf::RectangleShape button(sf::Vector2f(100.f, 40.f));
                button.setFillColor(sf::Color::Green);
                button.setPosition(20.f, 250.f + i * 50.f);
                spellButtons.push_back(button);
            }
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

    if (inCombat) {
        window.draw(combatMenuBackground);
        window.draw(playerHPText);
        window.draw(enemyHPText);
        window.draw(combatLogText);

        // Draw spell buttons
        for (const auto &button: spellButtons) {
            window.draw(button);
        }
    }
}

void Game::startCombat(Enemy &enemy) {
    Enemy *currentEnemy = &enemy;

    // Display combat message or UI
    std::cout << "Combat Started with Enemy!" << std::endl;

    while (player.getHp() > 0 && currentEnemy->getHp() > 0) {
        // Player's turn
        int selectedSpell = -1;
        while (selectedSpell == -1) {
            // Get the selected spell from the player
            for (size_t i = 0; i < spellButtons.size(); ++i) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (spellButtons[i].getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                                   static_cast<float>(mousePosition.y))) {
                        selectedSpell = i;
                        break;
                    }
                }
            }
        }
        player.Attack(*currentEnemy, selectedSpell);

        // Check if the enemy is defeated
        if (currentEnemy->getHp() <= 0) {
            std::cout << "Enemy has been defeated! Player wins!" << std::endl;
            break;
        }

        // Enemy's turn
        currentEnemy->Attack(player, -1);

        // Check if the player is defeated
        if (player.getHp() <= 0) {
            std::cout << "Player has been defeated! Enemy wins!" << std::endl;
            break;
        }
    }

    // Reset currentEnemy after combat
    currentEnemy = nullptr;
    inCombat = false;
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