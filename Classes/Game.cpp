#include "Game.h"
///Constructor Deconstractor

Game::Game() {

    player = new Player();

    videoMode.width = 1280;
    videoMode.height = 768;
    window = new sf::RenderWindow(videoMode,"Game",sf::Style::Titlebar | sf::Style::Close);

    if (!worldTileset.load("Assets/Grass.jpg", sf::Vector2u(64, 64), World, 20, 12))
    {
        std::cout<<"Erorr";
    }
}

Game::~Game() {
    delete window;
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
                player->movement();
                if(this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }
            default:
                break;
        }
    }
}

void Game::play(){
    while(window->isOpen())
    {
        update();

        render();
    }
}

void Game::update() {
    this->pollEvent();
}

void Game::render() {
    window->clear();
    window->draw(worldTileset);
    window->draw(*player);
    window->display();
}