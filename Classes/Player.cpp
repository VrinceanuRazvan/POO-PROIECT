#include "Player.h"
#include "Enemy.h"


void Player::setSprite() {
    if (!texture.loadFromFile("Assets/Player.png"))
    {
        std::cout<<"Erorr";
    }
    sprite.setTexture(texture);
}

void Player::movem(int x, int y) {
    this->sprite.move((float)x * movementSpeed,(float) y * movementSpeed);
}

void Player::move() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->movem(0,-1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->movem(0,1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->movem(1,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->movem(-1,0);
}

Player::Player() {
    this->movementSpeed=10;
    setSprite();
    setDamage();
}

Player::Player(const Player &other): name(other.name),sprite(other.sprite),texture(other.texture),hp(other.hp),baseDamage(other.baseDamage),Damage(other.Damage),
movementSpeed(other.movementSpeed),type(other.type), weapon(other.weapon),isTurn(other.isTurn){

    std::cout<<"Constructor de copiere pentru clasa Player";
}

Player &Player::operator=(const Player &other) {
    name = other.name;
    sprite = other.sprite;
    texture = other.texture;
    hp = other.hp;
    baseDamage = other.baseDamage;
    Damage = other.Damage;
    movementSpeed = other.movementSpeed;
    type = other.type;
    weapon = other.weapon;
    isTurn = other.isTurn;
    std::cout<<"Operator = pentru clasa Player";
    return *this;
}

Player::~Player() {
    std::cout<<"Deconstructor player";
}

void Player::Spawn(float x, float y) {
    sprite.setPosition(x, y);
}

void Player::Attack(Enemy &enemy) {
    std::cout << "Player's turn! Choose a spell:" << std::endl;

    for (size_t i = 0; i < Spells.size(); ++i) {
        std::cout << i + 1 << ". " << Spells[i] << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the spell you want to use: ";
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= Spells.size()) {
        Spell playerSpell = Spells[choice - 1];

        std::cout << "Player casts " << playerSpell.getName() << std::endl;

        int damageDealt = playerSpell.getDamage();
        enemy.takeDamage(damageDealt);
    } else {
        std::cout << "Invalid choice. Player skips turn." << std::endl;
    }
}


const sf::Sprite &Player::getSprite() const {
    return sprite;
}

void Player::GetRandomSpellSet(const std::string &filename, int n) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cout << "Error opening the file." << std::endl;
        return;
    }

    std::vector<Spell> allSpells;
    Spell tempSpell;
    while (inputFile >> tempSpell) {
        allSpells.push_back(tempSpell);
    }

    inputFile.close();

    if ((int) allSpells.size() < n) {
        std::cout << "Not enough spells in the file." << std::endl;
        Spells = allSpells;
    }

    std::shuffle(allSpells.begin(), allSpells.end(), std::mt19937(std::random_device()()));

    std::vector<Spell> randomSpells(allSpells.begin(), allSpells.begin() + n);

    Spells = randomSpells;

}

int Player::getHp() const {
    return hp;
}

void Player::setHp(int _hp) {
    this->hp = _hp;
}

void Player::takeDamage(int _damage) {
    if (_damage >= 0) {
        this->hp -= _damage;
    }
}
