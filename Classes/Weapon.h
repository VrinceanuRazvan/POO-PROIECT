#ifndef OOP_WEAPON_H
#define OOP_WEAPON_H

#include <iostream>

class Weapon{
    float damageMultiplier;
    std::string type;
public:

    Weapon(float damageMultiplier_ = 1) : damageMultiplier(damageMultiplier_) {
        if (damageMultiplier < 1)
            throw std::invalid_argument("Damage multyplayer trebuie sa fie mai amre ca 1 sau egal");
    }

    ~Weapon();

    [[nodiscard]] float getDamageMultiplier() const;

    //void setType(ElementalType type_);
};


#endif //OOP_WEAPON_H
