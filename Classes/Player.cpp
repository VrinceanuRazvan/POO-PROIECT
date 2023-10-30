#include "Player.h"

void Player::setSprite() {
    if (!texture.loadFromFile("Assets/Player.png"))
    {
        std::cout<<"Erorr";
    }
    sprite.setTexture(texture);
}

void Player::move(int x, int y) {
    this->sprite.move(x * movementSpeed, y * movementSpeed);
}

void Player::move() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->move(0,-1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->move(0,1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->move(1,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->move(-1,0);

}

