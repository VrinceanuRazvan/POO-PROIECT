#ifndef OOP_SPELL_H
#define OOP_SPELL_H

#include <utility>

#include "ElementalType.h"

class Spell{
    int damage{};
    ElementalType type;
    std::string name;
    std::string description;
public:

    explicit Spell(int damage = 0, ElementalType type = ElementalType::None, std::string name = "", std::string description = "") : damage(damage), type(type),
                                                                                            name(std::move(name)),
                                                                                            description(std::move(description)) {}

    Spell (const Spell&);

    Spell& operator=(const Spell &);

    ~Spell();

    /*friend std::ostream& operator<<(std::ostream& os,const Spell& spell_)
    {
        os << "Spell type: " << spell_.type << " Spell damage: "<< spell_.damage << " ";
        return os;
    }*/

    bool operator==(const Spell &rhs) const;

    bool operator!=(const Spell &rhs) const;


};


#endif //OOP_SPELL_H
