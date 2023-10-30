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
            default:
                break;
        }
    }
}

void Game::play(){
    //player.spawn(sf::Vector2f (videoMode.width/2,videoMode.height/2));
    while(window.isOpen())
    {
        update();

        render();
    }
}

void Game::update() {
    this->pollEvent();
}

void Game::render() {
    window.clear();
    window.draw(worldTileset);
    window.draw(player);
    window.display();
}