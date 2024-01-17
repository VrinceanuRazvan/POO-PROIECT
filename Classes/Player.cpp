#include "Player.h"


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

Player::Player()
        : Entity() {}

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

void Player::Attack(Entity &entity) {
    std::cout << "Player's turn! Choose a spell:" << std::endl;

    for (size_t i = 0; i < Spells.size(); ++i) {
        std::cout << i + 1 << ". " << Spells[i] << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the spell you want to use: ";
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= Spells.size()) {
        Spell playerSpell = Spells[choice - 1];

        std::cout << "Player casts " << playerSpell.getName() << std::endl;

        int damageDealt = playerSpell.getDamage();
        entity.takeDamage(damageDealt);
    } else {
        std::cout << "Invalid choice. Player skips turn." << std::endl;
    }
}

void Player::setWeapon(const Weapon &weapon_) {
    Player::weapon = weapon_;
}
