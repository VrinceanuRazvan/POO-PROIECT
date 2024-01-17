#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Entity.h"

class Enemy : public Entity {

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

public:

    Enemy();

    ~Enemy();

    void move() override;

    void Attack(Entity &entity) override;

};


#endif //OOP_ENEMY_H
