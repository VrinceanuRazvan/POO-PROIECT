#ifndef OOP_WEAPON_H
#define OOP_WEAPON_H

#include "Type.h"

class Weapon{
    float damageMultiplier;
    Type type;
public:

    explicit Weapon(float damageMultiplier_ = 0, Type type_ = Type::None) : damageMultiplier(damageMultiplier_), type(type_) {}

    void setdamageMultiplier(float damageMultiplier_) {
        Weapon::damageMultiplier = damageMultiplier_;
    }

    void setType(Type type_) {
        Weapon::type = type_;
    }

    [[nodiscard]] float getdamageMultiplier() const {
        return damageMultiplier;
    }

    [[nodiscard]] Type getType() const {
        return type;
    }

    bool operator==(const Weapon &rhs) const {
        return damageMultiplier == rhs.damageMultiplier &&
               type == rhs.type;
    }

    bool operator!=(const Weapon &rhs) const {
        return !(rhs == *this);
    }

    ~Weapon() = default;
};


#endif //OOP_WEAPON_H
