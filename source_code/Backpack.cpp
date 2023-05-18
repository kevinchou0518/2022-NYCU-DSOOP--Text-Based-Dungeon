#include "Backpack.h"

Backpack::Backpack()
{
}

void Backpack::showbackpack()
{
	cout << "You have:\n    " << numofpotion << " potions.\n";
	cout << "    " << numofkey << " keys.\n";
	cout << "Helmet:\n";
	for (int i = 0; i < helindex ; i++) {
		if (this->helmet[i].getwear()) {
			cout << "(" << i << ")" <<". " << this->helmet[i].getName() << " +ATK " << this->helmet[i].getAttack() << " +DEF " << this->helmet[i].getDefense() << " +HP " << this->helmet[i].getHealth() << " (equiped)\n";
		}
		else {
			cout << "(" << i << ")" <<  ". " << this->helmet[i].getName() << " +ATK " << this->helmet[i].getAttack() << " +DEF " << this->helmet[i].getDefense() << " +HP " << this->helmet[i].getHealth() << endl;
		}
	}
	cout << "Armor:\n";
	for (int i = 0; i < armindex; i++) {
		if (this->armor[i].getwear()) {
			cout << "(" << i << ")" << ". " << this->armor[i].getName() << " +ATK " << this->armor[i].getAttack() << " +DEF " << this->armor[i].getDefense() << " +HP " << this->armor[i].getHealth() << " (equiped)\n";
		}
		else {
			cout << "(" << i << ")" << ". " << this->armor[i].getName() << " +ATK " << this->armor[i].getAttack() << " +DEF " << this->armor[i].getDefense() << " +HP " << this->armor[i].getHealth() << endl;
		}
	}
	cout << "Weapon:\n";
	for (int i = 0; i < weaindex; i++) {
		if (this->weapon[i].getwear()) {
			cout << "(" << i << ")" <<". "<< this->weapon[i].getName() << " +ATK " << this->weapon[i].getAttack() << " +DEF " << this->weapon[i].getDefense() << " +HP " << this->weapon[i].getHealth() << " (equiped)\n";
		}
		else {
			cout << "(" << i << ")" << ". " << this->weapon[i].getName() << " +ATK " << this->weapon[i].getAttack() << " +DEF " << this->weapon[i].getDefense() << " +HP " << this->weapon[i].getHealth() << endl;
		}
	}
}

void Backpack::changeequip(Player* player){
    Player* maincharacter = dynamic_cast<Player*>(player);
	while (1) {
		this->showbackpack();
		cout << "-----------------------------------------------------------" << endl;
		cout << "(a)change helmet\n" << "(b)change armor\n" << "(c)change lefthand weapon\n" << "(d)change righthand weapon\n" << "(e)closed backpack\n";
		char in;
		cin >> in;
		if (in == 'a' || in == 'A') {
            cout << "Wearing Helmet: "<< maincharacter->getBackpack()->getwhelmet()->getName()<<endl;
			for (int i = 0; i < helindex; i++) {
				if (this->helmet[i].getwear()) {
					cout <<"(" <<  i << ")" << ". " << this->helmet[i].getName() << " +ATK" << this->helmet[i].getAttack() << " +DEF" << this->helmet[i].getDefense() << " +HP" << this->helmet[i].getHealth() << " (equiped)\n";
				}
				else {
					cout <<"(" <<  i << ")" << ". " << this->helmet[i].getName() << " +ATK" << this->helmet[i].getAttack() << " +DEF" << this->helmet[i].getDefense() << " +HP" << this->helmet[i].getHealth() << endl;
				}
			}
			cout << "input the index of helmet:\n";
			int index;
			cin >> index;
			if(index<0||index>=helindex){
                cout<<"wrong input!!!\n";
                continue;
			}
			maincharacter->decreaseStates(wearinghelmet);
			setwhelmet(index);
			maincharacter->increaseStates(wearinghelmet);
			continue;
		}
		else if (in == 'b' || in == 'B') {
            cout << "Wearing Armor: "<< maincharacter->getBackpack()->getwarmor()->getName()<<endl;
			for (int i = 0; i < armindex; i++) {
				if (this->armor[i].getwear()) {
					cout <<"(" <<  i << ")" << ". " << this->armor[i].getName() << " +ATK" << this->armor[i].getAttack() << " +DEF" << this->armor[i].getDefense() << " +HP" << this->armor[i].getHealth() << " (equiped)\n";
				}
				else {
					cout <<"(" <<  i << ")" << ". " << this->armor[i].getName() << " +ATK" << this->armor[i].getAttack() << " +DEF" << this->armor[i].getDefense() << " +HP" << this->armor[i].getHealth() << endl;
				}
			}
			cout << "input the index of armor:\n";
			int index;
			cin >> index;
			if(index < 0 ||index >= armindex){
                cout<<"wrong input!!!\n";
                continue;
			}
			maincharacter->decreaseStates(wearingarmor);
			setwarmor(index);
			maincharacter->increaseStates(wearingarmor);
			continue;
		}
		else if (in == 'c' || in == 'C') {
		    cout << "Wearing LeftWeapon: "<< maincharacter->getBackpack()->getwleftweapon()->getName()<<endl;
			for (int i = 0; i < weaindex; i++) {
				if (this->weapon[i].getwear()) {
					cout <<"(" <<  i << ")" << ". " << this->weapon[i].getName() << " +ATK" << this->weapon[i].getAttack() << " +DEF" << this->weapon[i].getDefense() << " +HP" << this->weapon[i].getHealth() << " (equiped)\n";
				}
				else {
					cout <<"(" <<  i << ")" << ". " << this->weapon[i].getName() << " +ATK" << this->weapon[i].getAttack() << " +DEF" << this->weapon[i].getDefense() << " +HP" << this->weapon[i].getHealth() << endl;
				}
			}
			cout << "input the index of weapon:\n";
			int index;
			cin >> index;
			if(index < 0 ||index >= weaindex){
                cout<<"wrong input!!!\n";
                continue;
			}
			maincharacter->decreaseStates(wearing_leftweapon);
			setwleftweapon(index);
			maincharacter->increaseStates(wearing_leftweapon);
			continue;
		}
		else if (in == 'd' || in == 'D') {
		    cout << "Wearing RightWeapon: "<< maincharacter->getBackpack()->getwrightweapon()->getName()<<endl;
			for (int i = 0; i < weaindex; i++) {
				if (this->weapon[i].getwear()) {
					cout << i << ". " << this->weapon[i].getName() << " +ATK" << this->weapon[i].getAttack() << " +DEF" << this->weapon[i].getDefense() << " +HP" << this->weapon[i].getHealth() << " (equiped)\n";
				}
				else {
					cout << i << ". " << this->weapon[i].getName() << " +ATK" << this->weapon[i].getAttack() << " +DEF" << this->weapon[i].getDefense() << " +HP" << this->weapon[i].getHealth() << endl;
				}
			}
			cout << "input the index of weapon:\n";
			int index;
			cin >> index;
			if(index < 0 ||index >= weaindex){
                cout<<"wrong input!!!\n";
                continue;
			}
			maincharacter->decreaseStates(wearing_rightweapon);
			setwrightweapon(index);
			maincharacter->increaseStates(wearing_rightweapon);
			continue;
		}
		else if (in == 'e' || in == 'E') {
			cout << "closed the backpack\n";
			break;
		}
		else {
			cout << "wrong input\n";
			continue;
		}
	}

}



void Backpack::addhelmet(Equipment* equip)
{
	Helmet* hel = dynamic_cast<Helmet*>(equip);
	helmet[helindex] = *hel;
	helindex++;
}

void Backpack::addarmor(Equipment* equip)
{
	Armor* arm = dynamic_cast<Armor*>(equip);
	armor[armindex] = *arm;
	armindex++;
}

void Backpack::addweapon(Equipment* equip)
{
	Weapon* wea = dynamic_cast<Weapon*>(equip);
	weapon[weaindex] = *wea;
	weaindex++;
}

void Backpack::setpotion(int potion)
{
	this->numofpotion = potion;
}

void Backpack::setkey(int key)
{
	this->numofkey = key;
}



void Backpack::setwhelmet(Helmet* hel)
{
	if (hel->getwear()) {
		cout << "the helmet have been equiped\n";
	}
	else {
		hel->setwear(true);
		this->wearinghelmet->setwear(false);
		this->wearinghelmet = hel;
	}

}

void Backpack::setwarmor(Armor* arm)
{
	if (arm->getwear()) {
		cout << "the armor have been equiped\n";
	}
	else {
		arm->setwear(true);
		this->wearingarmor->setwear(false);
		this->wearingarmor = arm;
	}

}

void Backpack::setwleftweapon(Weapon* wea)
{
	if (wea->getwear()) {
		cout << "the weapon have been equiped\n";
	}
	else {
		wea->setwear(true);
		this->wearing_leftweapon->setwear(false);
		this->wearing_leftweapon = wea;
	}

}

void Backpack::setwrightweapon(Weapon* wea)
{
	if (wea->getwear()) {
		cout << "the weapon have been equiped\n";
	}
	else {
		wea->setwear(true);
		this->wearing_rightweapon->setwear(false);
		this->wearing_rightweapon = wea;
	}

}

void Backpack::setwhelmet(int index)
{
	if (this->helmet[index].getwear()) {
		cout << "the helmet have been equiped\n";
	}
	else {
		this->helmet[index].setwear(true);
		this->wearinghelmet->setwear(false);
		this->wearinghelmet = &(helmet[index]);
		cout << "the helmet have beem change\n";
	}
}


void Backpack::setwarmor(int index)
{
	if (this->armor[index].getwear()) {
		cout << "the armor have been equiped\n";
	}
	else {
		this->armor[index].setwear(true);
		this->wearingarmor->setwear(false);
		this->wearingarmor = &(armor[index]);
		cout << "the armor have beem change\n";
	}
}

void Backpack::setwleftweapon(int index)
{
	if (this->weapon[index].getwear()) {
		cout << "the weapon have been equiped\n";
	}
	else{
		this->weapon[index].setwear(true);
		this->wearing_leftweapon->setwear(false);
		this->wearing_leftweapon = &(weapon[index]);
		cout << "the lefthand weapon have beem change\n";
	}
}

void Backpack::setwrightweapon(int index)
{
	if (this->weapon[index].getwear()) {
		cout << "the weapon have been equiped\n";

	}
	else {
		this->weapon[index].setwear(true);
		this->wearing_rightweapon->setwear(false);
		this->wearing_rightweapon = &(weapon[index]);
		cout << "the righthand weapon have beem change\n";
	}

}

int Backpack::getpotion()
{
	return this->numofpotion;
}

int Backpack::getkey()
{
	return this->numofkey;
}





Helmet* Backpack::getwhelmet()
{
	return this->wearinghelmet;
}

Armor* Backpack::getwarmor()
{
	return this->wearingarmor;
}

Weapon* Backpack::getwrightweapon()
{
	return this->wearing_rightweapon;
}

Weapon* Backpack::getwleftweapon()
{
	return this->wearing_leftweapon;
}

void Backpack::initialwhelmet()
{
	wearinghelmet = &helmet[0];
	wearinghelmet->setwear(true);
}

void Backpack::initialwarmor()
{
	wearingarmor = &armor[0];
	wearingarmor->setwear(true);
}

void Backpack::initialwleftweapon()
{
	wearing_leftweapon = &weapon[1];
	wearing_leftweapon->setwear(true);
}

void Backpack::initialwrightweapon()
{
	wearing_rightweapon = &weapon[0];
	wearing_rightweapon->setwear(true);
}
