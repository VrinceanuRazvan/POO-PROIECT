#include "Enemy.h"

Enemy::Enemy()
        : Entity() {}

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

void Enemy::move() {
    int randomDirection = rand() % 4;

    switch (randomDirection) {
        case 0:
            this->sprite.move(0, -(float) movementSpeed);
            break;
        case 1:
            this->sprite.move(0, (float) movementSpeed);
            break;
        case 2:
            this->sprite.move((float) movementSpeed, 0);
            break;
        case 3:
            this->sprite.move(-(float) movementSpeed, 0);
            break;
        default:
            break;
    }
}

void Enemy::Attack(Entity &entity) {
    std::cout << "Enemy's turn! Selecting a random spell..." << std::endl;

    if (!Spells.empty()) {
        int randomIndex = rand() % Spells.size();
        Spell enemySpell = Spells[randomIndex];

        std::cout << "Enemy attacks with " << enemySpell.getName() << std::endl;

        int damageDealt = enemySpell.getDamage();
        entity.takeDamage(damageDealt);
    }
}