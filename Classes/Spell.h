#ifndef OOP_SPELL_H
#define OOP_SPELL_H

#include <utility>
#include <iostream>

class Spell{
    int damage = 0;
    std::string type;
    std::string name;
    std::string description;
public:

    Spell();

    Spell(int damage, std::string type, std::string name, std::string description);

    Spell (const Spell&);

    Spell& operator=(const Spell &);

    ~Spell();

    friend std::ostream& operator<<(std::ostream& os,const Spell& spell_);

    friend std::istream &operator>>(std::istream &is, Spell &spell_);

    bool operator==(const Spell &rhs) const;

    bool operator!=(const Spell &rhs) const;

    [[nodiscard]] int getDamage() const;

    const std::string &getName() const;

};


#endif //OOP_SPELL_H
