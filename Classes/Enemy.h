#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Game.h"

class Enemy{
    int hp;
    bool isTurn;
    int baseDamage;
    ElementalType type;
    std::vector <Spell> spell;
public:

    explicit Enemy(int hp_ = 0, bool isTurn_ = false, int baseDamage_ = 0, ElementalType type_ = ElementalType::None, const std::vector<Spell> &spell_ = {}) :hp(hp_), isTurn(isTurn_),
                                                                                                                                            baseDamage(baseDamage_),
                                                                                                                                            type(type_),
                                                                                                                                            spell(spell_) {}

    ~Enemy();

    Enemy(const Enemy&);

    Enemy& operator=(const Enemy &);

    /*void setHp(int);

    void setIsTurn(bool);

    void setBaseDamage(int);

    void setType(ElementalType);

    void addSpell(const Spell&);

    void removeSpell(const Spell&);

    [[nodiscard]] int getHp() const;

    [[nodiscard]] bool isTurn1() const;

    [[nodiscard]] int getBaseDamage() const;

    [[nodiscard]] ElementalType getType() const;

    [[nodiscard]] const std::vector<Spell> &getSpell() const;

     */
};


#endif //OOP_ENEMY_H
