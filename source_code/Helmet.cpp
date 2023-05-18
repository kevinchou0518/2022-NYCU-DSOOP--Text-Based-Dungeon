#include "Helmet.h"
#include "Player.h"
Helmet::Helmet(string name, int hth, int atk, int def) :Equipment(name, hth, atk, def,'h') {}
Helmet::Helmet(string name, int hth, int atk, int def, int cost) : Equipment(name, hth, atk, def, 'h', cost) {}
Helmet::Helmet():Equipment(){}
bool Helmet::triggerEvent(Object* player)
{
	cout << "-----------------------------------------------------------" << endl;
	Player* maincharacter = dynamic_cast<Player*>(player);
	cout << "A helmet is on the floor" << endl;
	cout << "[ " << this->getName() << " +ATK " << this->getAttack() << " +DEF " << this->getDefense() << " +HP " << this->getHealth() << " ]\n";
	cout << "(a).pick up\n";
	cout << "(b).throw it away\n";
	char deci;
	while (1) {
		cin >> deci;
		if (deci == 'a' || deci == 'A') {
			maincharacter->getBackpack()->addhelmet(this);
			cout << "It is in your backpack now\n";
			break;
		}
		else if (deci == 'b' || deci == 'B') {
			break;
		}
		else {
			cout << "wrong input -> input your decision again\n";
		}
	}
	return true;
}

bool Helmet::triggerBackpack(Object* player)
{
	Player* maincharacter = dynamic_cast<Player*>(player);
	maincharacter->getBackpack()->addhelmet(this);
	maincharacter->addmoney(-this->getcost());
	return false;
}
