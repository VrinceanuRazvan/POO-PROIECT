#ifndef OOP_SPELL_H
#define OOP_SPELL_H

#include <utility>

#include "Type.h"

class Spell{
    int damage{};
    Type type;
    std::string name;
    std::string description;
public:

    explicit Spell(int damage = 0, Type type = Type::None, std::string name = "", std::string description = "") : damage(damage), type(type),
                                                                                            name(std::move(name)),
                                                                                            description(std::move(description)) {}

    Spell (const Spell &other) = default;

    Spell& operator=(const Spell & other) = default;

    /*friend std::ostream& operator<<(std::ostream& os,const Spell& spell_)
    {
        os << "Spell type: " << spell_.type << " Spell damage: "<< spell_.damage << " ";
        return os;
    }*/

    void setDamage(int damage_) {
        Spell::damage = damage_;
    }

    void setType(Type type_) {
        Spell::type = type_;
    }

    void setName(const std::string &name_) {
        Spell::name = name_;
    }

    void setDescription(const std::string &description_) {
        Spell::description = description_;
    }

    [[nodiscard]] int getDamage() const {
        return damage;
    }

    [[nodiscard]] Type getType() const {
        return type;
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    [[nodiscard]] const std::string &getDescription() const {
        return description;
    }

    bool operator==(const Spell &rhs) const {
        return damage == rhs.damage &&
               type == rhs.type &&
               name == rhs.name &&
               description == rhs.description;
    }

    bool operator!=(const Spell &rhs) const {
        return !(rhs == *this);
    }

    ~Spell()
    {
        std::cout<<"Distructor Spell";
    }

};


#endif //OOP_SPELL_H
