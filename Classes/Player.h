#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <cmath>
#include "Weapon.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player : public sf::Drawable, sf::Transformable {
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    int hp;
    float baseDamage;
    int Damage;
    float movementSpeed;
    Type type;
    Weapon weapon;
    bool isTurn = false;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const{
        target.draw(sprite, states);
}

    void move(int x, int y);

public:
    explicit Player(std::string name_ = "", int hp_ = 100, float baseDamage_ = 100, int damage_ = 0, float movementSpeed_ = 10, Type type_ = Type::None, Weapon *weapon_ = nullptr,
                     bool isTurn_ = false) : name(std::move(name_)), hp(hp_), baseDamage(baseDamage_), Damage(damage_),
                                                                                       movementSpeed(movementSpeed_), type(type_), weapon(*weapon_),
                                                                                        isTurn(isTurn_) {
        setSprite();
        setDamage();
    }

    void move();

    void setSprite();

    Player();

    Player(const Player& other) = default;

    Player& operator=(const Player & other) = default;

    void setName(const std::string &name_) {
        Player::name = name_;
    }

    void setHp(int hp_) {
        Player::hp = hp_;
    }

    void setBaseDamage(float baseDamage_) {
        Player::baseDamage = baseDamage_;
    }

    void setDamage(){
        float weaponDamage = weapon.getdamageMultiplier();
        Player::Damage = (int) std::floor( baseDamage *  weaponDamage);
    }

    void setMovementSpeed(float movementSpeed_) {
        Player::movementSpeed = movementSpeed_;
    }

    void setType(Type type_) {
        Player::type = type_;
    }

    void setIsTurn(bool isTurn_) {
        Player::isTurn = isTurn_;
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    [[nodiscard]] int getHp() const {
        return hp;
    }

    [[nodiscard]] float getBaseDamage() const {
        return baseDamage;
    }

    [[nodiscard]] int getDamage() const{
        return Damage;
    }

    [[nodiscard]] float getMovementSpeed() const {
        return movementSpeed;
    }

    [[nodiscard]] Type getType() const {
        return type;
    }

    [[nodiscard]] bool isTurn1() const {
        return isTurn;
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& player_){
        os << "Nume: " << player_.name << " HP: " << player_.hp << " Damage: " << player_.Damage<<player_.type;
        return os;
    }

    ~Player() = default;

};



#endif //OOP_PLAYER_H
