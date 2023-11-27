#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <cmath>
#include "Weapon.h"
#include "Spell.h"
#include "Enemy.h"
#include <fstream>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Enemy;

class Player : public sf::Drawable, sf::Transformable {
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    int hp;
    float baseDamage;
    int Damage;
    float movementSpeed;
    std::string type;
    Weapon weapon;
    bool isTurn = false;
    std::vector<Spell> Spells;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

    void movem(int x, int y);

public:
    Player();

    Player(const Player &other);

    Player &operator=(const Player &other);

    ~Player() override;

    void move();

    void setSprite();

    void setDamage() {
        float weaponDamage = weapon.getDamageMultiplier();
        Player::Damage = (int) std::floor(baseDamage * weaponDamage);
    }

    void Spawn(float x, float y);

    void Attack(Enemy &enemy);

    const sf::Sprite &getSprite() const;

    void GetRandomSpellSet(const std::string &filename, int n);


    friend std::ostream &operator<<(std::ostream &os, const Player &player_) {
        os << "Nume: " << player_.name << " HP: " << player_.hp << " Damage: " << player_.Damage;
        return os;
    }

    int getHp() const;

    void setHp(int hp);

    void takeDamage(int _damage);

};



#endif //OOP_PLAYER_H
