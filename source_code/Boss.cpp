#include "Boss.h"
using namespace std;
Boss::Boss():GameCharacter()
{
}

Boss::Boss(string name, int health, int atk, int def) : GameCharacter(name, health, health, atk, def) {}

void Boss::printslime()
{
	cout << "      	* " << endl;
	cout << "      ** " << endl;
	cout << "    *****" << endl;
	cout << "  ***O**O**" << endl;
	cout << "**************" << endl;
	cout << "**************" << endl;
	cout << "  **********" << endl;
}

void Boss::printslime2()
{
	cout << "      	     * " << endl;
	cout << "      	  **** " << endl;
	cout << "       ******" << endl;
	cout << "    *************" << endl;
	cout << "  ******@**@*******" << endl;
	cout << "********************" << endl;
	cout << "********************" << endl;
	cout << "  ***************" << endl;
}

void Boss::printdragon()
{
	cout << "                                                     ***" << endl;
	cout << "                                                    *****" << endl;
	cout << "                                  **               *******" << endl;
	cout << "                               DD****            **********" << endl;
	cout << "                            \"\"\"\")****            ************" << endl;
	cout << "************                \"\"******             ************" << endl;
	cout << " **************                ****              ************" << endl;
	cout << "   ***************               **           ***************" << endl;
	cout << "      ******************        ****     *******************" << endl;
	cout << "        ********************    ******  *******************" << endl;
	cout << "           **********************************************" << endl;
	cout << "               *********         *****      ***********" << endl;
	cout << "                                 **   **" << endl;
	cout << "                                **      **" << endl;
	cout << "                               **        **" << endl;
	cout << "                             ****        ****" << endl;
	cout << "                            ( ( (         ( | )" << endl;
	cout << "" << endl;
}

bool Boss::triggerEvent(Object* player)
{
	Player* maincharacter = dynamic_cast<Player*>(player);
	//like monster's
	cout << "-----------------------------------------------------------" << endl;
	cout << "!\n";
	cout << "!!!\n";
	cout << "!!!!!\n";
	cout << "!!!!!!!\n";
	cout << endl;
	cout << "A small green jelly is in the room...\n";
	cout << endl;
	cout << "This monster look quite different from those you counter before\n";
	cout << endl;
	cout << "To escape from this fatal dungeon!!!    Without hesitation!!!     You fight with it!!" << endl;
	while (1) {
		printslime();
		cout << "-----------------------------------------------------------" << endl;
		cout << "the slime have: " << this->getCurrentHealth() << " hp\n";
		cout << "you have: " << maincharacter->getCurrentHealth() << " hp\t" << maincharacter->getBackpack()->getpotion() << " potions\n";
		cout << "-----------------------------------------------------------" << endl;
		cout << "choose action:" << endl;
		cout << "a:hit the monster" << endl;
		cout << "b:use the potion for heal" << endl;
		cout << "c:use the potion on monster" << endl;
		cout << "d:retreat to the previous room" << endl;
		char inptr;
		int damage = 0;
		cin >> inptr;
		switch (inptr) {
		case 'a':
		case 'A':
			damage = maincharacter->getAttack() - this->getDefense();
			if (damage > 0) {
				this->takeDamage(damage);
				cout << "you caused " << damage << " on the slime.\n";
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
				maincharacter->getBackpack()->setpotion(maincharacter->getBackpack()->getpotion() - 1);
				break;
			}
			else {
				cout << "you don't have any potion\n";
				break;
			}
		case 'd':
		case 'D':
			maincharacter->changeRoom(maincharacter->getPreviousRoom());
			maincharacter->setx(maincharacter->getprex());
			maincharacter->sety(maincharacter->getprey());
			return false;
		default:
			cout << "wrong input\n";
			break;
		}
		if (this->checkIsDead()) {
			break;
		}
		int _damage = this->getAttack() - maincharacter->getDefense();
		if (_damage < 0) {
			_damage = 0;
		}
		maincharacter->takeDamage(_damage);
		cout << "the slime done " << _damage << " on you\n";
		if (maincharacter->checkIsDead()) {
			return false;
		}
		continue;
	}
	cout << "*****************************************************************" << endl;
	printslime2();
	cout << endl;
	cout << "The slime are changing!!!\n";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "a big dragon is standing in front you now!!!" << endl;
	cout << endl;
	cout << "I'm the the king of the dungeon,defeat me or dead here!!     said by the dragon" << endl;
	this->setMaxHealth(200);
	this->setCurrentHealth(200);
	this->setAttack(20);
	while (1) {
		printdragon();
		cout << "-----------------------------------------------------------" << endl;
		cout << "the dungeon king have: " << this->getCurrentHealth() << " hp\n";
		cout << "you have: " << maincharacter->getCurrentHealth() << " hp\t" << maincharacter->getBackpack()->getpotion() << " potions\n";
		cout << "-----------------------------------------------------------" << endl;
		cout << "choose action:" << endl;
		cout << "a:hit the monster" << endl;
		cout << "b:use the potion for heal" << endl;
		cout << "c:use the potion on monster" << endl;
		cout << "d:retreat to the previous room" << endl;
		char inptr;
		int damage = 0;
		cin >> inptr;
		switch (inptr) {
		case 'a':
		case 'A':
			damage = maincharacter->getAttack() - this->getDefense();
			if (damage > 0) {
				this->takeDamage(damage);
				cout << "you caused " << damage << " on the king.\n";
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
				cout << "you caused 50 on the king.\n";
				maincharacter->getBackpack()->setpotion(maincharacter->getBackpack()->getpotion() - 1);
				break;
			}
			else {
				cout << "you don't have any potion\n";
				break;
			}
		case 'd':
		case 'D':
			maincharacter->changeRoom(maincharacter->getPreviousRoom());
			maincharacter->setx(maincharacter->getprex());
			maincharacter->sety(maincharacter->getprey());
			return false;
		default:
			cout << "wrong input\n";
			break;
		}
		if (this->checkIsDead()) {
            maincharacter->getCurrentRoom()->setbossdead(true);
			return false;
		}
		int _damage = this->getAttack() - maincharacter->getDefense();
		if (_damage < 0) {
			_damage = 0;
		}
		maincharacter->takeDamage(_damage);
		cout << "the dungeon king done " << _damage << " on you\n";
		if (maincharacter->checkIsDead()) {
			return false;
		}
		continue;
	}
	cout << "" << endl;
	return false;
}
