#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include <vector>
#include "ElementalType.h"
#include "Spell.h"


class Enemy{
    int hp;
    bool isTurn = false;
    int baseDamage;
    ElementalType type;
    std::vector <Spell> spell;
public:

    Enemy();

    Enemy(int hp, int baseDamage, ElementalType type);

    ~Enemy();


    Enemy(const Enemy&);

    Enemy& operator=(const Enemy &);

    //void setHp(int);

    //void setIsTurn(bool);

    //void setBaseDamage(int);

    //void setType(ElementalType);

    void addSpell(const Spell&);

    void removeSpell(const Spell&);

    //[[nodiscard]] int getHp() const;

    //[[nodiscard]] bool isTurn1() const;

    //[[nodiscard]] int getBaseDamage() const;

    //[[nodiscard]] ElementalType getType() const;

    //[[nodiscard]] const std::vector<Spell> &getSpell() const;


};


#endif //OOP_ENEMY_H
