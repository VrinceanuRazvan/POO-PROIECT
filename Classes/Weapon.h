#ifndef OOP_WEAPON_H
#define OOP_WEAPON_H

#include "ElementalType.h"

class Weapon{
    float damageMultiplier;
    ElementalType type;
public:

    explicit Weapon(float damageMultiplier_ = 0, ElementalType type_ = ElementalType::None) : damageMultiplier(damageMultiplier_), type(type_) {}

    ~Weapon();

    [[nodiscard]] float getDamageMultiplier() const;

    void setType(ElementalType type_);

};


#endif //OOP_WEAPON_H
