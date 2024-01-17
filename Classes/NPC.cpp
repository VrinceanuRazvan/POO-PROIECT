#include "NPC.h"

NPC::NPC(int hp, float movementSpeed) : Entity(hp, movementSpeed) {
    setSprite();
}

NPC::NPC(const NPC &other) : Entity(other) {}

NPC *NPC::clone() const {
    return new NPC(*this);
}

void NPC::move() {
    //Nu vreau sa se miste
}

void NPC::Attack(Entity &entity, int spellIndex = -1) {
    std::cout << "Enemy's turn! Using the only spell..." << std::endl;
    std::cout << spellIndex << std::endl;
    if (!Spells.empty()) {
        Spell enemySpell = Spells.front();

        std::cout << "Enemy attacks with " << enemySpell.getName() << std::endl;

        int damageDealt = enemySpell.getDamage();
        entity.takeDamage(damageDealt);
    } else {
        std::cout << "Enemy has no spells!" << std::endl;
    }
}

void NPC::setSprite() {
    if (!texture.loadFromFile("Assets/NPC.png")) {
        std::cout << "Error loading enemy texture." << std::endl;
    }
    sprite.setTexture(texture);
}

NPC &NPC::operator=(const NPC &other) {
    NPC temp(other);
    swap(*this, temp);
    return *this;
}


