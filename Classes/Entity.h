#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "Spell.h"

class Entity : public sf::Drawable, public sf::Transformable {

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string name;
    int hp;
    float movementSpeed;
    std::string type;
    std::vector<Spell> Spells;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite, states);

    }

public:

    explicit Entity(int hp = 100, float movementSpeed = 10);

    Entity(const Entity &other);

    Entity &operator=(const Entity &other);

    ~Entity() override = default;

    void setSprite();

    virtual void move() = 0;

    virtual void Attack(Entity &entity, int spellIndex) = 0;

    void die();

    const sf::Sprite &getSprite() const;

    void GetSpellSet(const std::string &filename, int n);

    void Spawn(float x, float y);

    void takeDamage(int _damage);

    int getHp() const;

    void setHp(int _hp);
};

#endif //OOP_ENTITY_H