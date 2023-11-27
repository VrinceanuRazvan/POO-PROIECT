#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include <vector>
#include "Spell.h"
#include <SFML/Graphics.hpp>


class Enemy : public sf::Drawable, sf::Transformable {
    int hp;
    bool isTurn = false;
    int baseDamage;
    sf::Sprite sprite;
    sf::Texture texture;
    std::string type;
    std::vector<Spell> Spells;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

public:

    Enemy();

    //Enemy(int hp, int baseDamage, ElementalType type);

    ~Enemy();


    Enemy(const Enemy&);

    Enemy& operator=(const Enemy &);

    void Spawn(float x, float y);

    void Attack();

    const sf::Sprite &getSprite() const;

    void GetRandomSpellSet(const std::string &filename, int n);

    void setSprite();

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
