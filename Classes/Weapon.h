#ifndef OOP_WEAPON_H
#define OOP_WEAPON_H

#include <iostream>

class Weapon{
    float damageMultiplier;
    std::string type;
public:

    explicit Weapon(float damageMultiplier_ = 0) : damageMultiplier(damageMultiplier_){}

    ~Weapon();

    [[nodiscard]] float getDamageMultiplier() const;

    //void setType(ElementalType type_);

};


#endif //OOP_WEAPON_H
