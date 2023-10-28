#include "Game.h"
///Constructor Deconstractor

Game::Game() {
    initVariables();
    initWindow();
}

Game::~Game() {
    delete window;
}

void Game::initVariables() {
    window = nullptr;
    player = new Player;
    worldTileset.load("Assets/Grass.jpg", sf::Vector2u(64, 64), World, 20, 12);
}

void Game::initWindow() {
    videoMode.width = 1280;
    videoMode.height = 768;
    window = new sf::RenderWindow(videoMode,"Game",sf::Style::Titlebar| sf::Style::Close);
}



///Functions

void Game::pollEvent() {
    while(this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }
            default:
                break;
        }
    }
}

void Game::update() {
    this->pollEvent();
}

void Game::render() {
    window->clear();
    window->draw(worldTileset);
    window->draw(player->getSprite());
    window->display();
}

bool Game::getisWindowOpen() {
    return this->window->isOpen();
}
