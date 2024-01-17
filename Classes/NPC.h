#ifndef OOP_NPC_H
#define OOP_NPC_H

#include "Entity.h"

class NPC : public Entity {

public:
    // Constructor
    NPC();

    // Destructor
    ~NPC() override = default;

    void move() override;

    void setSprite();

    void Attack(Entity &entity, int spellIndex) override;

};

#endif //OOP_NPC_H
