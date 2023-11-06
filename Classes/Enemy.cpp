#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(int hp, int baseDamage = 0, ElementalType type = ElementalType::None) : hp(hp), baseDamage(baseDamage),
                                                                                     type(type) {}

Enemy &Enemy::operator=(const Enemy &other) {
    hp = other.hp;
    isTurn = other.isTurn;
    baseDamage = other.baseDamage;
    type = other.type;
    spell = other.spell;
    std::cout<<"Operator = pentru clasa Enemy";
    return *this;
}


Enemy::Enemy(const Enemy &other):hp(other.hp),isTurn(other.isTurn),baseDamage(other.baseDamage),type(other.type),spell(other.spell) {
    std::cout<<"Constructor de copiere pentru clasa Enemy";
}

Enemy::~Enemy() {
    std::cout<<"Desctructor apelat pentru clasa Enemy";
}

void Enemy::removeSpell(const Spell &spell_) {
    for(auto it = spell.begin(); it != spell.end();){
        if(*it == spell_){
            it = spell.erase(it);
            break;
        }
    }
}

void Enemy::addSpell(const Spell &spell_) {
    Enemy::spell.push_back(spell_);
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

void Enemy::setHp(int hp_) {
    Enemy::hp = hp_;
}

int Enemy::getHp() const {
    return hp;
}

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
