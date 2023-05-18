#include "Object.h"
#include "GameCharacter.h"

GameCharacter::GameCharacter() :Object() {}


GameCharacter::GameCharacter(string name, int maxhealth, int currenthealth, int attack, int defense) : Object(name, "GameCharacter"),
maxHealth(maxhealth), currentHealth(currenthealth), attack(attack), defense(defense) {}
bool GameCharacter::checkIsDead() {
    if (currentHealth > 0) {
        return false;
    }
    else return true;
}

void GameCharacter::takeDamage(int damage) {
    this->currentHealth -= damage;
}


int GameCharacter::getAttack() {
    return this->attack;
}
int GameCharacter::getCurrentHealth() {
    return this->currentHealth;
}
int GameCharacter::getMaxHealth() {
    return this->maxHealth;
}
int GameCharacter::getDefense() {
    return this->defense;
}
void GameCharacter::setAttack(int _attack) {
    this->attack = _attack;
}
void GameCharacter::setDefense(int _defense) {
    this->defense = _defense;
}
void GameCharacter::setMaxHealth(int _maxHealth) {
    this->maxHealth = _maxHealth;
}
void GameCharacter::setCurrentHealth(int _currentHealth) {
    this->currentHealth = _currentHealth;
}
