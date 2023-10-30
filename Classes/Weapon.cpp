#include "Weapon.h"

Weapon::~Weapon() {
    std::cout<<"Deconstructor weapon";
}

float Weapon::getDamageMultiplier() const {
    return damageMultiplier;
}

/*void Weapon::setType(ElementalType type_) {
    Weapon::type = type_;
}*/
