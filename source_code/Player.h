#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Backpack.h"
#include "Equipment.h"


using namespace std;
class Equipment;
class Room;
class Backpack;
class Player : public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    Backpack* backpack;
    int money = 100;
    int x=0;
    int y=3;
    int prex=0;
    int prey=3;
public:
    Player();
    Player(string, int, int, int);   //name maxh atk def
    void setx(int);
    void sety(int);
    void setprex(int);
    void setprey(int);
    int getx();
    int gety();
    int getprex();
    int getprey();
    void increaseStates(int, int, int);
    void increaseStates(Equipment*);
    void decreaseStates(Equipment*);
    void changeRoom(Room*);
    void addmoney(int);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setmoney(int);
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setBackpack(Backpack*);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    Backpack* getBackpack();
    int getmoney();
};

#endif // PLAYER_H_INCLUDED
