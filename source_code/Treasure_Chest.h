#ifndef TREASURE_CHEST_H_INCLUDED
#define TREASURE_CHEST_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Treasure_Chest : public GameCharacter
{
private:
    int numofgold;
    string script;
    vector<Equipment*> treasure;
    bool open = false;
public:
    Treasure_Chest();
    Treasure_Chest(string);
    Treasure_Chest(string, int);
    void setgold(int);
    void listtreasure();
    bool triggerEvent(Object*);
    void settreasure(vector<Equipment*>);
    vector<Equipment*> gettreasure();
    bool getopen();
    void setopen(bool);
    int getgold();
};

#endif // TREASURE_CHEST_H_INCLUDED
