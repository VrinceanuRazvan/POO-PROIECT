#include "Entity.h"

Entity::Entity(int hp, float movementSpeed) : hp(hp), movementSpeed(movementSpeed) {
    setSprite();
}

Entity::Entity(const Entity &other) : sprite(other.sprite), texture(other.texture), name(other.name), hp(other.hp),
                                      movementSpeed(other.movementSpeed), type(other.type) {}

Entity &Entity::operator=(const Entity &other) {
    name = other.name;
    sprite = other.sprite;
    texture = other.texture;
    hp = other.hp;
    movementSpeed = other.movementSpeed;
    type = other.type;
    return *this;
}

void Entity::setSprite() {
    if (!texture.loadFromFile("Assets/Player.png")) {
        std::cout << "Erorr";
    }
    sprite.setTexture(texture);
}

const sf::Sprite &Entity::getSprite() const {
    return sprite;
}

void Entity::GetSpellSet(const std::string &filename, int n) {
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

void Entity::Spawn(float x, float y) {
    sprite.setPosition(x, y);
}

int Entity::getHp() const {
    return hp;
}

void Entity::setHp(int _hp) {
    this->hp = _hp;
}

void Entity::takeDamage(int _damage) {
    if (_damage >= 0) {
        this->hp -= _damage;
    }
}

void Entity::die() {
    delete this;
}
