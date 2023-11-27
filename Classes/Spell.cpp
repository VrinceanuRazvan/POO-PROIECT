#include "Spell.h"


Spell::Spell() {}

Spell::Spell(int damage, std::string type = "", std::string name = "", std::string description = "")
        : damage(damage),
          type(std::move(type)),
          name(std::move(name)),
          description(std::move(
                  description)) {}


Spell::Spell(const Spell &other) :damage(other.damage),type(other.type),name(other.name),description(other.description){
    std::cout<<"Constructor de copiere pentru clasa Spell";
}

Spell &Spell::operator=(const Spell &other) {
    name = other.name;
    damage = other.damage;
    type = other.type;
    description = other.description;
    std::cout<<"Operator = pentru clasa Spell";
    return *this;
}

Spell::~Spell() {
    std::cout<<"Distructor Spell";
}

bool Spell::operator==(const Spell &rhs) const {
    return damage == rhs.damage &&
           type == rhs.type &&
           name == rhs.name &&
           description == rhs.description;
}

bool Spell::operator!=(const Spell &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Spell &spell_) {
    os <<" Spell damage:"<< spell_.damage << " ";
    return os;
}

std::istream &operator>>(std::istream &is, Spell &spell_) {
    is >> spell_.damage >> spell_.type >> spell_.name;
    std::getline(is, spell_.description);

    return is;
}

int Spell::getDamage() const {
    return damage;
}

const std::string &Spell::getName() const {
    return name;
}

