#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class Tile
{
    int type;
    bool isPlayer_on;
    bool Walkable;
    std::vector<int> Coordinates;
public:

    explicit Tile(int type_ = 0, bool isPlayerOn_ = false, bool walkable_ = false, const std::vector<int> &Coordinates_ = {0}) : type(type_),
                                                                                          isPlayer_on(isPlayerOn_),
                                                                                          Walkable(walkable_),
                                                                                          Coordinates(Coordinates_) {}

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

    int getType() const {
        return type;
    }

    bool isPlayerOn() const {
        return isPlayer_on;
    }

    bool isWalkable() const {
        return Walkable;
    }

    const std::vector<int> &getCoordinates() const {
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


    ~Tile() {
    }

};

class Enemy
{
    int hp;
    bool isTurn;
    int baseDamage;
    int type;
public:
    
    explicit Enemy(int hp_ = 0, bool isTurn_ = false, int baseDamage_ = 0, int type_ = 0) : hp(hp_), isTurn(isTurn_), baseDamage(baseDamage_), type(type_) {}


    void setHp(int hp_) {
        Enemy::hp = hp_;
    }

    void setIsTurn(bool isTurn_) {
        Enemy::isTurn = isTurn_;
    }

    void setBaseDamage(int baseDamage_) {
        Enemy::baseDamage = baseDamage_;
    }

    void setType(int type_) {
        Enemy::type = type_;
    }

    int getHp() const {
        return hp;
    }

    bool isTurn1() const {
        return isTurn;
    }

    int getBaseDamage() const {
        return baseDamage;
    }

    int getType() const {
        return type;
    }

    ~Enemy()
        {

        }
};

class Weapon
{
    float damageMultiplier;
    int type;
public:
    
    explicit Weapon(float damageMultiplier_ = 0, int type_ = 0) : damageMultiplier(damageMultiplier_), type(type_) {}

    void setdamageMultiplier(float damageMultiplier_) {
        Weapon::damageMultiplier = damageMultiplier_;
    }

    void setType(int type_) {
        Weapon::type = type_;
    }

    float getdamageMultiplier() const {
        return damageMultiplier;
    }

    int getType() const {
        return type;
    }

    bool operator==(const Weapon &rhs) const {
        return damageMultiplier == rhs.damageMultiplier &&
               type == rhs.type;
    }

    bool operator!=(const Weapon &rhs) const {
        return !(rhs == *this);
    }

    ~Weapon() {

    }
};

class Player
{
    std::string name;
    int hp;
    float baseDamage;
    int Damage;
    float movementSpeed;
    int type;
    Weapon* weapon;
    std::vector<int> Position;
    bool isTurn = false;
public:
    explicit Player(const std::string &name_ = "", int hp_ = 0, float baseDamage_ = 0, int damage_ = 0, float movementSpeed_ = 0, int type_ = 0, Weapon *weapon_ = nullptr,
           const std::vector<int> &Position_ = {0,0}, bool isTurn_ = 0) : name(name_), hp(hp_), baseDamage(baseDamage_), Damage(damage_),
                                                           movementSpeed(movementSpeed_), type(type_), weapon(weapon_),
                                                           Position(Position_), isTurn(isTurn_) {}

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
        Player::Damage = (int) floor( baseDamage *  weaponDamage);
    }

    void setMovementSpeed(float movementSpeed_) {
        Player::movementSpeed = movementSpeed_;
    }

    void setType(int type_) {
        Player::type = type_;
    }

    void setWeapon(Weapon *weapon) {
        Player::weapon = weapon;
    }

    void setPosition(const std::vector<int> &Position_) {
        Position = Position_;
    }

    void setIsTurn(bool isTurn_) {
        Player::isTurn = isTurn_;
    }

    const std::string &getName() const {
        return name;
    }

    int getHp() const {
        return hp;
    }

    float getBaseDamage() const {
        return baseDamage;
    }

    int getDamage() const{
        return Damage;
    }

    float getMovementSpeed() const {
        return movementSpeed;
    }

    int getType() const {
        return type;
    }

    Weapon *getWeapon() const {
        return weapon;
    }

    const std::vector<int> &getPosition() const {
        return Position;
    }

    bool isTurn1() const {
        return isTurn;
    }

    bool operator==(const Player &rhs) const {
        return hp == rhs.hp &&
               baseDamage == rhs.baseDamage &&
               Damage == rhs.Damage &&
               movementSpeed == rhs.movementSpeed &&
               type == rhs.type &&
               weapon == rhs.weapon &&
               Position == rhs.Position &&
               isTurn == rhs.isTurn;
    }

    bool operator!=(const Player &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& player_){
        os << "Nume: " << player_.name << " HP: " << player_.hp << " Damage: " << player_.Damage << " Pozitia: (" << player_.Position[0] << ","<< player_.Position[1]<< ") ";
        if(player_.type == 1)
        {
            os<<"Type: Fire";
        }
        if(player_.type == 2)
        {
            os<<"Type: Wind";
        }
        if(player_.type == 3)
        {
            os<<"Type: Earth";
        }
        if(player_.type == 4)
        {
            os<<"Type: Water";
        }
        return os;
    }

    ~Player() {

    }

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
            map[i][j].setIsPlayerOn(0);
            map[i][j].setWalkable(0);
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
    Weapon w(10,5);
    Player p("nume",100,100,0,100,1,&w,{0,1},true);
    p.setDamage();
    std::cout<<p;

    map = generateMap(mapSize);
    consoleMap(map,mapSize);

    return 0;
}
