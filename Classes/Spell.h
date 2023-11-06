#ifndef OOP_SPELL_H
#define OOP_SPELL_H

#include <utility>

#include "ElementalType.h"

class Spell{
    int damage = 0;
    ElementalType type;
    std::string name;
    std::string description;
public:

    Spell();

    Spell(int damage, ElementalType type, std::string name, std::string description);

    Spell (const Spell&);

    Spell& operator=(const Spell &);

    ~Spell();

    friend std::ostream& operator<<(std::ostream& os,const Spell& spell_);

    bool operator==(const Spell &rhs) const;

    bool operator!=(const Spell &rhs) const;


};


#endif //OOP_SPELL_H
