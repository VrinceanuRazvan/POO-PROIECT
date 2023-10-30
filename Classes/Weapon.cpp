#include "Weapon.h"

Weapon::~Weapon() {
    std::cout<<"Deconstructor weapon";
}

float Weapon::getDamageMultiplier() const {
    return damageMultiplier;
}
