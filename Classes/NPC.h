#ifndef OOP_NPC_H
#define OOP_NPC_H

#include "Entity.h"

class NPC : public Entity {

public:
    // Constructor
    NPC(int hp = 100, float movementSpeed = 10);

    // Destructor
    ~NPC() override = default;

    NPC(const NPC &other);

    NPC &operator=(const NPC &other);

    NPC *clone() const override;

    void move() override;

    void setSprite();

    void Attack(Entity &entity, int spellIndex) override;

};

#endif //OOP_NPC_H
