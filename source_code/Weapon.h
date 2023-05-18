#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include "Equipment.h"


using namespace std;
class Backpack;
class Player;
class Weapon : public Equipment
{
public:
    Weapon();
    Weapon(string name, int, int, int);
    Weapon(string name, int, int, int, int);
    virtual bool triggerEvent(Object*);
    virtual bool triggerBackpack(Object*);
};


#endif // WEAPON_H_INCLUDED
