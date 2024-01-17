#include "Weapon.h"

Weapon::~Weapon() = default;

float Weapon::getDamageMultiplier() const {
    return damageMultiplier;
}

/*void Weapon::setType(ElementalType type_) {
    Weapon::type = type_;
}*/
