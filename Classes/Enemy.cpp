#include <fstream>
#include <random>
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy() {
    setSprite();
}

//Enemy::Enemy(int hp, int baseDamage = 0, ElementalType type = ElementalType::None) : hp(hp), baseDamage(baseDamage),
//                                                                                     type(type) {}

Enemy &Enemy::operator=(const Enemy &other) {
    hp = other.hp;
    isTurn = other.isTurn;
    baseDamage = other.baseDamage;
    type = other.type;
    Spells = other.Spells;
    std::cout << "Operator = pentru clasa Enemy\n";
    return *this;
}


Enemy::Enemy(const Enemy &other) : hp(other.hp), isTurn(other.isTurn), baseDamage(other.baseDamage), type(other.type),
                                   Spells(other.Spells) {
    std::cout << "Constructor de copiere pentru clasa Enemy\n";
}

Enemy::~Enemy() {
    std::cout << "Desctructor apelat pentru clasa Enemy\n";
}

/*void Enemy::removeSpell(const Spell &spell_) {
    for (auto it = Spells.begin(); it != Spells.end();) {
        if(*it == spell_){
            it = Spells.erase(it);
            break;
        }
    }
}

void Enemy::addSpell(const Spell &spell_) {
    Enemy::Spells.push_back(spell_);
}*/

void Enemy::setSprite() {
    if (!texture.loadFromFile("Assets/Enemy.png")) {
        std::cout << "Erorr";
    }
    sprite.setTexture(texture);
}

void Enemy::Spawn(float x, float y) {
    sprite.setPosition(x, y);
}

void Enemy::Attack(Player &player) {
    std::cout << "Enemy's turn! Selecting a random spell..." << std::endl;

    if (!Spells.empty()) {
        int randomIndex = rand() % Spells.size();
        Spell enemySpell = Spells[randomIndex];

        std::cout << "Enemy attacks with " << enemySpell.getName() << std::endl;

        int damageDealt = enemySpell.getDamage();
        player.takeDamage(damageDealt);
    }
}

const sf::Sprite &Enemy::getSprite() const {
    return sprite;
}

void Enemy::GetRandomSpellSet(const std::string &filename, int n) {
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

/*void Enemy::setType(ElementalType type_) {
    Enemy::type = type_;
}

void Enemy::setBaseDamage(int baseDamage_) {
    Enemy::baseDamage = baseDamage_;
}

void Enemy::setIsTurn(bool isTurn_) {
    Enemy::isTurn = isTurn_;
}
*/
void Enemy::setHp(int hp_) {
    Enemy::hp = hp_;
}

int Enemy::getHp() const {
    return hp;
}

void Enemy::takeDamage(int _damage) {
    if (_damage >= 0) {
        this->hp -= _damage;
    }
}
/*
bool Enemy::isTurn1() const {
    return isTurn;
}

int Enemy::getBaseDamage() const {
    return baseDamage;
}

ElementalType Enemy::getType() const {
    return type;
}

const std::vector<Spell> &Enemy::getSpell() const {
    return spell;
}*/
