#ifndef BACKPACK_H_INCLUDED
#define BACKPACK_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

#include "Equipment.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"

using namespace std;
class Player;
class Equipment;
class Armor;
class Weapon;
class Helmet;

class Backpack
{
private:
    int numofpotion = 5;
    int numofkey = 3;
    Helmet* wearinghelmet = NULL;
    Armor* wearingarmor = NULL;
    Weapon* wearing_leftweapon = NULL;
    Weapon* wearing_rightweapon = NULL;
    Helmet helmet[100];
    Armor armor[100];
    Weapon weapon[100];
    int helindex = 0;
    int armindex = 0;
    int weaindex = 0;
public:
    Backpack();
    void showbackpack();
    void changeequip(Player*);

    void addhelmet(Equipment*);
    void addarmor(Equipment*);
    void addweapon(Equipment*);



    //setter getter
    void setpotion(int);
    void setkey(int);

    void setwhelmet(Helmet*);
    void setwarmor(Armor*);
    void setwleftweapon(Weapon*);
    void setwrightweapon(Weapon*);
    void setwhelmet(int);
    void setwarmor(int);
    void setwleftweapon(int);
    void setwrightweapon(int);
    int getpotion();
    int getkey();
    Helmet* getwhelmet();
    Armor* getwarmor();
    Weapon* getwrightweapon();
    Weapon* getwleftweapon();

    void initialwhelmet();
    void initialwarmor();
    void initialwleftweapon();
    void initialwrightweapon();

};

#endif // BACKPACK_H_INCLUDED
