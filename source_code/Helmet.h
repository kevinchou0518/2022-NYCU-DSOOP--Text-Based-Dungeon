#ifndef HELMET_H_INCLUDED
#define HELMET_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Equipment.h"

using namespace std;
class Player;

class Helmet : public Equipment
{
public:
    Helmet();
    Helmet(string name, int, int, int);
    Helmet(string, int, int, int, int);
    virtual bool triggerEvent(Object*);
    virtual bool triggerBackpack(Object*);

};

#endif // HELMET_H_INCLUDED
