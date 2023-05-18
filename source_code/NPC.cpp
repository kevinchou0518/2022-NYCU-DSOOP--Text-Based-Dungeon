#include "NPC.h"

NPC::NPC() :GameCharacter() {}

NPC::NPC(string name, string script, vector<Equipment*> commodity) : GameCharacter(name,1,1,1,1), script(script), commodity(commodity) {}

NPC::NPC(string name) : GameCharacter(name, 1, 1, 1,1)
{
}

//to be done
void NPC::listCommodity() {
    cout << "(1). Potion:" << this->getpotion() << "   10$" << endl;
    cout << "(2). Key:" << this->getkey() << "   20$" << endl;
    for (int i = 0; i < this->getCommodity().size(); i++) {
        cout << "(" << i + 3 << ")" << "." << this->getCommodity()[i]->getName();
        cout << " +atk: " << this->getCommodity()[i]->getAttack() << " +def " << this->getCommodity()[i]->getDefense() << " +health " << this->getCommodity()[i]->getHealth() << "cost: " << this->getCommodity()[i]->getcost() << endl;
    }

}
//to be done
bool NPC::triggerEvent(Object* player) {
    Player* maincharacter = dynamic_cast<Player*>(player);
    cout << "You met a merchant called: " <<this->getName()<< endl;
    while (1) {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Do you want to buy anything?\n";
        cout << "You have " << maincharacter->getmoney() << " $ now\n";
        cout << "(0):leave\n";
        this->listCommodity();
        int act;
        cin >> act;
        if (act < 0 || act >= commodity.size() + 3) {
            cout << "wrong input\n";
            continue;
        }
        if (act == 0) {
            return false;
        }
        else if (act == 1) {
            if (this->numofpotion > 0) {
                if (maincharacter->getmoney() >= 10) {
                    maincharacter->getBackpack()->setpotion(maincharacter->getBackpack()->getpotion() + 1);
                    cout << "You have " << maincharacter->getBackpack()->getpotion() << " potions now." << endl;
                    this->numofpotion--;
                    maincharacter->addmoney(-10);
                    continue;
                }
                else {
                    cout << "you don't have enough money!!\n";
                    continue;
                }

            }
            else {
                cout << "no more potion!!!\n";
                continue;
            }

        }
        else if (act == 2) {

            if (this->numofkey > 0) {
                if (maincharacter->getmoney() >= 20) {
                    maincharacter->getBackpack()->setkey(maincharacter->getBackpack()->getkey() + 1);
                    cout << "You have " << maincharacter->getBackpack()->getkey() << " keys now." << endl;
                    this->numofpotion--;
                    maincharacter->addmoney(-20);
                    continue;
                }
                else {
                    cout << "you don't have enough money!!\n";
                    continue;
                }
            }
            else {
                cout << "no more key!!!\n";
                continue;
            }
        }
        else {
            if (maincharacter->getmoney() >= this->getCommodity()[act - 3]->getcost()) {
                this->getCommodity()[act - 3]->triggerBackpack(maincharacter);
                int a = act - 3;
                this->commodity.erase(commodity.begin() + a);
                continue;
            }
            else {
                cout << "you don't have enough money!!\n";
                continue;
            }
        }
    }

}

void NPC::setpotion(int p)
{
    this->numofpotion = p;
}

void NPC::setkey(int k)
{
    this->numofkey = k;
}

void NPC::setScript(string _script) {
    this->script = _script;
}
void NPC::setCommodity(vector<Equipment*> item) {
    this->commodity = item;
}
string NPC::getScript() {
    return script;
}
vector<Equipment*> NPC::getCommodity() {
    return commodity;
}

int NPC::getpotion()
{
    return this->numofpotion;
}

int NPC::getkey()
{
    return this->numofkey;
}
