#include "Player.h"

Player::Player()
        : Entity() {
    setSprite();
}

Player *Player::clone() const {
    return new Player(*this);
}

Player::Player(const Player &other) : Entity(other), weapon(other.weapon) {}

Player &Player::operator=(const Player &other) {
    name = other.name;
    sprite = other.sprite;
    texture = other.texture;
    hp = other.hp;
    movementSpeed = other.movementSpeed;
    type = other.type;
    weapon = other.weapon;
    return *this;
}

void Player::move() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->sprite.move(0, -(float) movementSpeed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->sprite.move(0, (float) movementSpeed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->sprite.move((float) movementSpeed, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->sprite.move(-(float) movementSpeed, 0);
}

void Player::Attack(Entity &entity, int spellIndex) {
    if (spellIndex >= 0 && spellIndex < (int) Spells.size()) {
        Spell playerSpell = Spells[spellIndex];
        std::cout << "Player attacks with " << playerSpell.getName() << std::endl;

        int damageDealt = playerSpell.getDamage();
        entity.takeDamage(damageDealt);
    } else {
        std::cout << "Invalid spell index!" << std::endl;
    }
}

void Player::setWeapon(const Weapon &weapon_) {
    Player::weapon = weapon_;
}

int Player::getSpellCount() {
    return Spells.size();
}

void Player::setSprite() {
    if (!texture.loadFromFile("Assets/Player.png")) {
        std::cout << "Error loading enemy texture." << std::endl;
    }
    sprite.setTexture(texture);
}

void swap(Player &p1, Player &p2) {
    swap(static_cast<Entity &>(p1), static_cast<Entity &>(p2));

    using std::swap;
    swap(p1.weapon, p2.weapon);
}
