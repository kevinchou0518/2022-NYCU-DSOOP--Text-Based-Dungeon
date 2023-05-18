#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
using namespace std;

class Boss : public GameCharacter
{
private:
public:
    Boss();
    Boss(string, int, int, int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    void printslime();
    void printslime2();
    void printdragon();
    bool triggerEvent(Object*);
};

#endif // BOSS_H_INCLUDED
