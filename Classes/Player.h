#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Entity.h"
#include "Weapon.h"

class Player : public Entity {
    Weapon weapon;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

public:
    Player();

    ~Player() override = default;

    Player &operator=(const Player &other);

    void move() override;

    void Attack(Entity &entity, int spellIndex) override;

    void setWeapon(const Weapon &weapon);

    friend std::ostream &operator<<(std::ostream &os, const Player &player_) {
        os << "Nume: " << player_.name << " HP: " << player_.hp;
        return os;
    }

    int getSpellCount();
};

#endif //OOP_PLAYER_H
