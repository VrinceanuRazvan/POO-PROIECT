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

    Enemy(int hp = 100, float movementSpeed = 10);

    ~Enemy() override = default;

    Enemy *clone() const override;

    Enemy(const Enemy &other);

    void move() override;

    void setSprite();

    void Attack(Entity &entity, int spellIndex) override;
};


#endif //OOP_ENEMY_H
