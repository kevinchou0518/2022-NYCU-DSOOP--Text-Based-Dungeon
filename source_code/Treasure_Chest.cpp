#include "Treasure_Chest.h"

Treasure_Chest::Treasure_Chest():GameCharacter()
{
}

Treasure_Chest::Treasure_Chest(string name):GameCharacter(name,1,1,1,1)
{
}

Treasure_Chest::Treasure_Chest(string name, int gold) : GameCharacter(name, 1, 1, 1, 1),numofgold(gold)
{
}

void Treasure_Chest::setgold(int gold)
{
	numofgold = gold;
}

void Treasure_Chest::listtreasure()
{
	if (!this->treasure.empty()) {
		cout << "-----------------------------------------------------------" << endl;
		cout << this->numofgold << " $ \n";
		for (int i = 0; i < this->treasure.size(); i++) {
			cout<<i<<"."<<this->treasure[i]->getName()<< " +atk " << this->treasure[i]->getAttack() << " +def " << this->treasure[i]->getDefense() << " +health " << this->treasure[i]->getHealth() << endl;
		}
	}
	else {
		cout << "-----------------------------------------------------------" << endl;
		cout << "nothing is in the box\n";
	}
}

bool Treasure_Chest::triggerEvent(Object* player)
{
	Player* maincharacter = dynamic_cast<Player*>(player);
	cout << "-----------------------------------------------------------" << endl;
	cout << "a big box place in front of you\n";
	cout << "(a)use a key to open the box\n";
	cout << "(b)just ignore it\n";
	//tobe done
	char deci;
	cin >> deci;
	if (this->open) {
		cout << "a opened empty box in the room\n";
		return false;
	}
	else {
		if (deci == 'a' || deci == 'A') {
			if (maincharacter->getBackpack()->getkey() > 0) {
				listtreasure();
				cout << "all the equipment and money is in your backpack now\n";
				for (int i = 0; i < treasure.size(); i++) {
					this->treasure[i]->triggerBackpack(maincharacter);
				}
				while (!treasure.empty()) {
					this->treasure.erase(treasure.begin());
				}
			}
			else {
				cout << "you don't have any key\n";
				cout << "come back here whem you have any key.\n";
			}
			return true;

		}
		else if (deci == 'b' || deci == 'B') {
			return false;
		}
		else {
			cout << "wrong input\n";
		}
	}

}

void Treasure_Chest::settreasure(vector<Equipment*> trea)
{
	this->treasure = trea;
}

vector<Equipment*> Treasure_Chest::gettreasure()
{
	return this->treasure;
}

bool Treasure_Chest::getopen()
{
	return this->open;
}

void Treasure_Chest::setopen(bool o)
{
	this->open = o;
}

int Treasure_Chest::getgold()
{
	return numofgold;
}
