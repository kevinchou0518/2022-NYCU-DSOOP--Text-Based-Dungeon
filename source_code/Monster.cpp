#include "Monster.h"

Monster::Monster() :GameCharacter() {}


Monster::Monster(string name, int health, int atk, int def) : GameCharacter(name, health, health, atk, def) {}

//to be done  combat system
bool Monster::triggerEvent(Object* player) {
	Player* maincharacter = dynamic_cast<Player*>(player);
	cout << "-----------------------------------------------------------" << endl;
	cout << "You met a monster:"<<this->getName()<<endl;
	while (1) {
		cout << "-----------------------------------------------------------" << endl;
		cout << this->getName() <<" have: " << this->getCurrentHealth() << " hp\n";
		cout << "you have: " << maincharacter->getCurrentHealth() << " hp\t" << maincharacter->getBackpack()->getpotion() << " potions\n";
		cout << "choose action:" << endl;
		cout << "a:hit the monster" << endl;
		cout << "b:use the potion for heal" << endl;
		cout << "c:use the potion on monster" << endl;
		cout << "d:do nothing" << endl;
		cout << "e:retreat to the previous room" << endl;
		char inptr;
		int damage = 0;
		cin >> inptr;
		cout << "-----------------------------------------------------------" << endl;
		switch (inptr) {
		case 'a':
		case 'A':
			damage = maincharacter->getAttack() - this->getDefense();
			if (damage > 0) {
				this->takeDamage(damage);
				cout << "you caused " << damage << " on the monster.\n";
			}
			else {
				cout << "you caused 0 damage\n";
			}
			break;
		case 'b':
		case 'B':
			if (maincharacter->getBackpack()->getpotion() > 0) {
				cout << "your Hp +50\n";
				if (maincharacter->getCurrentHealth() + 50 >= maincharacter->getMaxHealth()) {
					maincharacter->setCurrentHealth(maincharacter->getMaxHealth());
					maincharacter->getBackpack()->setpotion(maincharacter->getBackpack()->getpotion() - 1);
					break;
				}
				else {
					maincharacter->setCurrentHealth(maincharacter->getCurrentHealth() + 50);
					maincharacter->getBackpack()->setpotion(maincharacter->getBackpack()->getpotion() - 1);
					break;
				}
			}
			else {
				cout << "you don't have any potion\n";
				break;
			}
		case 'c':
		case 'C':
			if (maincharacter->getBackpack()->getpotion() > 0) {
				this->takeDamage(50);
				cout << "you caused 50 on the monster.\n";
				maincharacter->getBackpack()->setpotion(maincharacter->getBackpack()->getpotion()-1);
				break;
			}
			else {
				cout << "you don't have any potion\n";
				break;
			}

		case 'd':
		case 'D':
			cout << "you didn't do any action\n";
			break;
		case 'e':
		case 'E':
			maincharacter->changeRoom(maincharacter->getPreviousRoom());
			maincharacter->setx(maincharacter->getprex());
			maincharacter->sety(maincharacter->getprey());
			return false;
		default:
			"wrong input\n";
			break;
		}
		if (this->checkIsDead()) {
			cout << "the monster dead\n";
			int getgold = this->getMaxHealth() / 2;
			maincharacter->addmoney(getgold);
			return true;
		}
		int _damage = this->getAttack() - maincharacter->getDefense();
		if (_damage < 0) {
			_damage = 0;
		}
		maincharacter->takeDamage(_damage);
		cout << "the monster done " << _damage << " on you\n";
		if (maincharacter->checkIsDead()) {
            return false;
		}
		continue;
	}
}

