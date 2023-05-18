#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Equipment : public Object
{
private:
    string name;
    bool beingwear = false;
    int Health;
    int Attack;
    int Defense;
    char whichkind;
    int cost = 0;
public:
    Equipment();
    Equipment(string, int, int, int, char);
    Equipment(string, int, int, int, char, int);
    /* Set & Get function*/
    void setkind(char);
    void setwear(bool);
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setcost(int);
    int getcost();
    int getHealth();
    int getAttack();
    int getDefense();
    bool getwear();
    char getkind();
    virtual bool triggerEvent(Object*);
    virtual bool triggerBackpack(Object*);
};

#endif // EQUIPMENT_H_INCLUDED
