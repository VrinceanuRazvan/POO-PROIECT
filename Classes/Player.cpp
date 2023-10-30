#include "Player.h"

void Player::setSprite() {
    if (!texture.loadFromFile("Assets/Player.png"))
    {
        std::cout<<"Erorr";
    }
    sprite.setTexture(texture);
}

void Player::movem(int x, int y) {
    this->sprite.move(x * movementSpeed, y * movementSpeed);
}



void Player::move() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->movem(0,-1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->movem(0,1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->movem(1,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->movem(-1,0);

}

Player::Player() {
    this->movementSpeed=10;
    setSprite();
    setDamage();
}

Player::Player(const Player &other): name(other.name),sprite(other.sprite),texture(other.texture),hp(other.hp),baseDamage(other.baseDamage),Damage(other.Damage),
movementSpeed(other.movementSpeed),type(other.type), weapon(other.weapon),isTurn(other.isTurn){

    std::cout<<"Constructor de copiere pentru clasa Player";
}

Player &Player::operator=(const Player &other) {
    name = other.name;
    sprite = other.sprite;
    texture = other.texture;
    hp = other.hp;
    baseDamage = other.baseDamage;
    Damage = other.Damage;
    movementSpeed = other.movementSpeed;
    type = other.type;
    weapon = other.weapon;
    isTurn = other.isTurn;
    std::cout<<"Operator = pentru clasa Player";
    return *this;
}

Player::~Player() {
    std::cout<<"Deconstructor player";
}
