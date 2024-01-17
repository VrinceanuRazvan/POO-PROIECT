#include "Enemy.h"

Enemy::Enemy(int hp, float movementSpeed)
        : Entity(hp, movementSpeed), movementCooldown(sf::seconds(1.0f)), timeSinceLastMove(sf::Time::Zero) {
    setSprite();
}

Enemy *Enemy::clone() const {
    return new Enemy(*this);
}

Enemy::Enemy(const Enemy &other) : Entity(other), movementCooldown(other.movementCooldown) {}

void Enemy::move() {
    // Check if enough time has passed since the last move
    if (timeSinceLastMove >= movementCooldown) {
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

        // Reset the timer
        timeSinceLastMove = sf::Time::Zero;
    } else {
        // Increment the timer if the cooldown hasn't passed
        timeSinceLastMove += clock.restart();
    }
}

void Enemy::Attack(Entity &entity, int spellIndex = -1) {
    std::cout << spellIndex << std::endl;
    std::cout << "Enemy's turn! Selecting a random spell..." << std::endl;

    if (!Spells.empty()) {
        int randomIndex = rand() % Spells.size();
        Spell enemySpell = Spells[randomIndex];

        std::cout << "Enemy attacks with " << enemySpell.getName() << std::endl;

        int damageDealt = enemySpell.getDamage();
        entity.takeDamage(damageDealt);
    } else {
        std::cout << "Enemy has no spells!" << std::endl;
    }
}

void Enemy::setSprite() {
    if (!texture.loadFromFile("Assets/Enemy.png")) {
        std::cout << "Error loading enemy texture." << std::endl;
    }
    sprite.setTexture(texture);
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