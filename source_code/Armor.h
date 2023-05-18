#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Equipment.h"

using namespace std;

class player;
class Armor : public Equipment
{
public:
    Armor();
    Armor(string name, int, int, int);
    Armor(string name, int, int, int, int);
    virtual bool triggerEvent(Object*);
    virtual bool triggerBackpack(Object*);
};

#endif // ARMOR_H_INCLUDED
