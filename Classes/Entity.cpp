#include "Entity.h"

Entity::Entity(int hp, float movementSpeed)
        : hp(hp), movementSpeed(movementSpeed) {}

const sf::Sprite &Entity::getSprite() const {
    return sprite;
}

Entity::Entity(const Entity &other) : sprite(other.sprite), texture(other.texture), name(other.name), hp(other.hp),
                                      movementSpeed(other.movementSpeed), type(other.type) {}

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

/*void Entity::setHp(int _hp) {
    this->hp = _hp;
}*/

void Entity::takeDamage(int _damage) {
    if (_damage >= 0) {
        this->hp -= _damage;
    }
}

/*void Entity::die() {
    delete this;
}*/

void swap(Entity &first, Entity &second) noexcept {
    using std::swap;
    swap(first.sprite, second.sprite);
    swap(first.texture, second.texture);
    swap(first.name, second.name);
    swap(first.hp, second.hp);
    swap(first.movementSpeed, second.movementSpeed);
    swap(first.type, second.type);
    swap(first.Spells, second.Spells);
}

Entity &Entity::operator=(const Entity &other) {
    if (this != &other) {
        Entity *temp = other.clone();
        swap(*this, *temp);
        delete temp;
    }
    return *this;
}