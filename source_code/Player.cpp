#include "Player.h"


Player::Player() :GameCharacter() {}

Player::Player(string name, int maxhealth, int attack, int defense) : GameCharacter(name, maxhealth, maxhealth, attack, defense) {}


void Player::increaseStates(int health, int atk, int def)
{
    this->setMaxHealth(this->getMaxHealth() + health);
    this->setCurrentHealth(this->getCurrentHealth() + health);
    this->setAttack(this->getAttack() + atk);
    this->setDefense(this->getDefense() + def);
}

void Player::increaseStates(Equipment* a)
{
    this->setMaxHealth(this->getMaxHealth() + a->getHealth());
    this->setCurrentHealth(this->getCurrentHealth() + a->getHealth());
    this->setAttack(this->getAttack() + a->getAttack());
    this->setDefense(this->getDefense() + a->getDefense());
}

void Player::decreaseStates(Equipment* a)
{
    this->setMaxHealth(this->getMaxHealth() - a->getHealth());
    this->setCurrentHealth(this->getCurrentHealth() - a->getHealth());
    this->setAttack(this->getAttack() - a->getAttack());
    this->setDefense(this->getDefense() - a->getDefense());
}

int Player::gety()
{
    return y;
}
int Player::getx()
{
    return x;
}
int Player::getprex(){
    return prex;
}
int Player::getprey(){
    return prey;
}
void Player::setx(int _x) {
    x = _x;
}
void Player::sety(int _y) {
    y = _y;
}
void Player::setprex(int y){
    prex=y;
}
void Player::setprey(int y){
    prey=y;
}
void Player::changeRoom(Room* current) {
    this->previousRoom = this->currentRoom;
    this->currentRoom = current;
}
void Player::addmoney(int mon)
{
    this->money += mon;
}
//to be done
bool Player::triggerEvent(Object* player) {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Hp: " << this->getCurrentHealth() << "/" << this->getMaxHealth() << endl;
    cout << "ATK: " << this->getAttack() << endl;
    cout << "DEF: " << this->getDefense() << endl;
    cout << "Money: " << this->getmoney() << "$" << endl;
    cout << "Helmet:" << this->getBackpack()->getwhelmet()->getName()<<   endl;
    cout << "Armor:" << this->getBackpack()->getwarmor()->getName() << endl;
    cout << "LeftWeapon:" << this->getBackpack()->getwleftweapon()->getName() << endl;
    cout << "RightWeapon:" << this->getBackpack()->getwrightweapon()->getName() << endl;
    return true;
}


void Player::setCurrentRoom(Room* current) {
    this->currentRoom = current;
}
void Player::setPreviousRoom(Room* prev) {
    this->previousRoom = prev;
}

void Player::setmoney(int mon)
{
    this->money = mon;
}

void Player::setBackpack(Backpack* _backpack)
{
    this->backpack = _backpack;
}


Room* Player::getCurrentRoom() {
    return currentRoom;
}
Room* Player::getPreviousRoom() {
    return previousRoom;
}

Backpack* Player::getBackpack()
{
    return this->backpack;
}

int Player::getmoney()
{
    return this->money;
}
