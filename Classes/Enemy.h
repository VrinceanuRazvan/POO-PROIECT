#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Entity.h"

class Enemy : public Entity {

    sf::Time movementCooldown;
    sf::Time timeSinceLastMove;
    sf::Clock clock;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

public:

    Enemy();

    ~Enemy() override = default;

    Enemy *clone() const override;

    void move() override;

    void setSprite();

    void Attack(Entity &entity, int spellIndex) override;
};


#endif //OOP_ENEMY_H
