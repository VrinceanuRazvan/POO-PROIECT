#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

enum class Type{
    None = 0,Fire = 1 ,Water = 2,Earth = 3,Wind = 4
};

std::ostream& operator << (std::ostream& os, const Type& obj)
{
    if(Type::Fire == obj)
        os<<"Fire";
    if(Type::None == obj)
        os<<"None";
    if(Type::Water == obj)
        os<<"Water";
    if(Type::Earth == obj)
        os<<"Earth";
    if(Type::Wind == obj)
        os<<"Wind";
    return os;
}

class Tile{
    int type;
    bool isPlayer_on;
    bool Walkable;
    std::vector<int> Coordinates;
public:

    explicit Tile(int type_ = 0, bool isPlayerOn_ = false, bool walkable_ = false, const std::vector<int> &Coordinates_ = {0}) : type(type_),
                                                                                          isPlayer_on(isPlayerOn_),
                                                                                          Walkable(walkable_),
                                                                                          Coordinates(Coordinates_) {}
    Tile(const Tile& other) = default;

    Tile& operator=(const Tile & other) = default;

    friend std::ostream& operator<<(std::ostream& os, const Tile& tile_){
        os << "Tip: " << tile_.type << " Walkable " << tile_.Walkable << " Pozitia: (" << tile_.Coordinates[0] << ","<< tile_.Coordinates[1]<< ") ";
        return os;
    }



    void setType(int type_) {
        Tile::type = type_;
    }

    void setIsPlayerOn(bool isPlayerOn_) {
        isPlayer_on = isPlayerOn_;
    }

    void setWalkable(bool walkable_) {
        Walkable = walkable_;
    }

    void setCoordinates(const std::vector<int> &Coordinates_) {
        Coordinates = Coordinates_;
    }

    [[nodiscard]] int getType() const {
        return type;
    }

    [[nodiscard]] bool isPlayerOn() const {
        return isPlayer_on;
    }

    [[nodiscard]] bool isWalkable() const {
        return Walkable;
    }

    [[nodiscard]] const std::vector<int> &getCoordinates() const {
        return Coordinates;
    }

    bool operator==(const Tile &rhs) const {
        return type == rhs.type &&
               isPlayer_on == rhs.isPlayer_on &&
               Walkable == rhs.Walkable &&
               Coordinates == rhs.Coordinates;
    }

    bool operator!=(const Tile &rhs) const {
        return !(rhs == *this);
    }


    ~Tile(){
        std::cout<<"Tile Destroyed";
    }


};

class Spell{
    int damage;
    Type type;
    std::string name;
    std::string description;
public:

    explicit Spell(int damage_ = 0, Type type_ = Type::None, std::string name_ = "", std::string description_ = "") : damage(damage_), type(type_),
                                                                                                                                name(std::move(name_)),
                                                                                                                                description(std::move(description_)) {}

    Spell (const Spell &other) = default;

    Spell& operator=(const Spell & other) = default;

    friend std::ostream& operator<<(std::ostream& os,const Spell& spell_)
    {
        os << "Spell type: " << spell_.type << " Spell damage: "<< spell_.damage << " ";
    }

    void setDamage(int damage_) {
        Spell::damage = damage_;
    }

    void setType(Type type_) {
        Spell::type = type_;
    }

    void setName(const std::string &name_) {
        Spell::name = name_;
    }

    void setDescription(const std::string &description_) {
        Spell::description = description_;
    }

    [[nodiscard]] int getDamage() const {
        return damage;
    }

    [[nodiscard]] Type getType() const {
        return type;
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    [[nodiscard]] const std::string &getDescription() const {
        return description;
    }

    bool operator==(const Spell &rhs) const {
        return damage == rhs.damage &&
               type == rhs.type &&
               name == rhs.name &&
               description == rhs.description;
    }

    bool operator!=(const Spell &rhs) const {
        return !(rhs == *this);
    }

    ~Spell()
    {
        std::cout<<"Distructor Spell";
    }

};

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

class Weapon{
    float damageMultiplier;
    Type type;
public:
    
    explicit Weapon(float damageMultiplier_ = 0, Type type_ = Type::None) : damageMultiplier(damageMultiplier_), type(type_) {}

    void setdamageMultiplier(float damageMultiplier_) {
        Weapon::damageMultiplier = damageMultiplier_;
    }

    void setType(Type type_) {
        Weapon::type = type_;
    }

    [[nodiscard]] float getdamageMultiplier() const {
        return damageMultiplier;
    }

    [[nodiscard]] Type getType() const {
        return type;
    }

    bool operator==(const Weapon &rhs) const {
        return damageMultiplier == rhs.damageMultiplier &&
               type == rhs.type;
    }

    bool operator!=(const Weapon &rhs) const {
        return !(rhs == *this);
    }

    ~Weapon() = default;
};

class Player{
    std::string name;
    int hp;
    float baseDamage;
    int Damage;
    float movementSpeed;
    Type type;
    Weapon* weapon;
    std::vector<int> Position;
    bool isTurn = false;
public:
    explicit Player(std::string name_ = "", int hp_ = 0, float baseDamage_ = 0, int damage_ = 0, float movementSpeed_ = 0, Type type_ = Type::None, Weapon *weapon_ = nullptr,
           const std::vector<int> &Position_ = {0,0}, bool isTurn_ = false) : name(std::move(name_)), hp(hp_), baseDamage(baseDamage_), Damage(damage_),
                                                           movementSpeed(movementSpeed_), type(type_), weapon(weapon_),
                                                           Position(Position_), isTurn(isTurn_) {
        setDamage();
    }

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
        float weaponDamage = weapon->getdamageMultiplier();
        Player::Damage = (int) std::floor( baseDamage *  weaponDamage);
    }

    void setMovementSpeed(float movementSpeed_) {
        Player::movementSpeed = movementSpeed_;
    }

    void setType(Type type_) {
        Player::type = type_;
    }

    void setWeapon(Weapon *weapon_) {
        Player::weapon = weapon_;
    }

    void setPosition(const std::vector<int> &Position_) {
        Position = Position_;
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

    [[nodiscard]] Weapon *getWeapon() const {
        return weapon;
    }

    [[nodiscard]] const std::vector<int> &getPosition() const {
        return Position;
    }

    [[nodiscard]] bool isTurn1() const {
        return isTurn;
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& player_){
        os << "Nume: " << player_.name << " HP: " << player_.hp << " Damage: " << player_.Damage << " Pozitia: (" << player_.Position[0] << ","<< player_.Position[1]<< ") "<<player_.type;
        return os;
        }

    void moveRight()
    {

    }

    ~Player() = default;

};

Tile ** generateMap(int size){
    int i,j;
    Tile ** map;
    map = (Tile**) malloc(size * sizeof(Tile*));
    for(i= 0;i< size;++i)
    {
        map[i] = (Tile*) malloc(size * sizeof(Tile));
    }
    for(i=0;i<size;++i)
    {
        for(j=0;j<size;j++)
        {
            map[i][j].setIsPlayerOn(false);
            map[i][j].setWalkable(false);
            map[i][j].setType(0);
            map[i][j].setCoordinates({i,j});
        }
    }
    return map;
}

void consoleMap(Tile** map,int size){
    int i,j;
    for(i=0;i<size;++i)
    {
        for(j=0;j<size;j++)
        {
            std::cout<<map[i][j].getType()<< " ";
        }
        std::cout<<std::endl;
    }
}

int main() {
    Tile** map;
    int mapSize = 10;
    Weapon w(10,Type::None);
    Player p("nume",100,100,0,100,Type::None,&w,{0,1},true);

    std::cout<<p;

    map = generateMap(mapSize);
    consoleMap(map,mapSize);

    Tile t1(1,true,true,{0,0});
    Tile t2;

    t2 = t1;
    std::cout<<t2;
    std::cout<<t1;


    Spell s1(100,Type::Fire,"","");

    Enemy e;

    e.addSpell(s1);

    std::cout<<e.getSpells();

    e.removeSpell(s1);

    std::cout<<e.getSpells();

    std::cout<<s1;

    return 0;
}
