#include "Lock.h"
#include "Player.h"

Lock::Lock():Object()
{
}

bool Lock::triggerEvent(Object* player)
{
	Player* maincharacter = dynamic_cast<Player*>(player);
	cout << "-----------------------------------------------------------" << endl;
	cout << "This room is locked!\n";
	cout << "(a)use a key to open the door\n";
	cout << "(b)go back to previous room\n";
	while (1) {
		char c;
		cin >> c;
		if (c == 'a' || c == 'A') {
			if (maincharacter->getBackpack()->getkey() > 0) {
				maincharacter->getBackpack()->setkey(maincharacter->getBackpack()->getkey() - 1);
				cout << "The door is open\n";
				return true;
			}
			else {
				cout << "You don't have any key\n";
				cout << "Come back here when you have the key\n";
				maincharacter->changeRoom(maincharacter->getPreviousRoom());
				maincharacter->setx(maincharacter->getprex());
                maincharacter->sety(maincharacter->getprey());
				return false;
			}
		}
		else if (c == 'b' || c == 'B') {
			maincharacter->changeRoom(maincharacter->getPreviousRoom());
			maincharacter->setx(maincharacter->getprex());
            maincharacter->sety(maincharacter->getprey());
            //cout<<"prex: "<<maincharacter->getprex()<<endl;
            //cout<<"prey: "<<maincharacter->getprey()<<endl;
            //cout<<"x: "<<maincharacter->getx()<<endl;
            //cout<<"y: "<<maincharacter->gety()<<endl;
			return false;
		}
		else {
			cout << "wrong input ->input your decision again\n";
		}
	}
	return false;
}
