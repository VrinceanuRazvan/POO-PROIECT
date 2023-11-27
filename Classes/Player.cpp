#include <fstream>
#include <random>
#include "Player.h"

void Player::setSprite() {
    if (!texture.loadFromFile("Assets/Player.png"))
    {
        std::cout<<"Erorr";
    }
    sprite.setTexture(texture);
}

void Player::movem(int x, int y) {
    this->sprite.move((float)x * movementSpeed,(float) y * movementSpeed);
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

void Player::Spawn(float x, float y) {
    sprite.setPosition(x, y);
}

void Player::Attack() {

}

const sf::Sprite &Player::getSprite() const {
    return sprite;
}

void Player::GetRandomSpellSet(const std::string &filename, int n) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cout << "Error opening the file." << std::endl;
        return;
    }

    std::vector<Spell> allSpells;
    Spell tempSpell;
    while (inputFile >> tempSpell) {
        allSpells.push_back(tempSpell);
    }

    inputFile.close();

    if ((int) allSpells.size() < n) {
        std::cout << "Not enough spells in the file." << std::endl;
        Spells = allSpells;
    }

    std::shuffle(allSpells.begin(), allSpells.end(), std::mt19937(std::random_device()()));

    std::vector<Spell> randomSpells(allSpells.begin(), allSpells.begin() + n);

    Spells = randomSpells;

}
