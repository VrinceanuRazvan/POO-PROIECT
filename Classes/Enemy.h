#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Game.h"

class Enemy{
    int hp;
    bool isTurn;
    int baseDamage;
    Type type;
    std::vector <Spell> spell;
public:

    explicit Enemy(int hp_ = 0, bool isTurn_ = false, int baseDamage_ = 0, Type type_ = Type::None, const std::vector<Spell> &spell_ = {}) :hp(hp_), isTurn(isTurn_),
                                                                                                                                            baseDamage(baseDamage_),
                                                                                                                                            type(type_),
                                                                                                                                            spell(spell_) {}

    Enemy(const Enemy& other) = default;

    Enemy& operator=(const Enemy & other) = default;

    void setHp(int hp_) {
        Enemy::hp = hp_;
    }

    void setIsTurn(bool isTurn_) {
        Enemy::isTurn = isTurn_;
    }

    void setBaseDamage(int baseDamage_) {
        Enemy::baseDamage = baseDamage_;
    }

    void setType(Type type_) {
        Enemy::type = type_;
    }

    void  addSpell(const Spell& spell_){
        Enemy::spell.push_back(spell_);
    }

    void removeSpell(const Spell &spell_){
        for(auto it = spell.begin(); it != spell.end();){
            if(*it == spell_){
                it = spell.erase(it);
                break;
            }
        }
    }

    [[nodiscard]] int getHp() const {
        return hp;
    }

    [[nodiscard]] bool isTurn1() const {
        return isTurn;
    }

    [[nodiscard]] int getBaseDamage() const {
        return baseDamage;
    }

    [[nodiscard]] Type getType() const {
        return type;
    }

    [[nodiscard]] int getSpells() const {
        return (int)spell.size();
    }

    ~Enemy() {
        std::cout<<"Disctructor apelat pentru clasa Enemy";
    };
};


#endif //OOP_ENEMY_H
