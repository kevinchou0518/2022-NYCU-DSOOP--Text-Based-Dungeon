#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Boss.h"
#include "Room.h"
#include "Weapon.h"
#include "armor.h"
#include "Helmet.h"
#include "Backpack.h"
#include "Lock.h"
#include "Treasure_Chest.h"
#include <fstream>
using namespace std;
class Dungeon {
private:
    Player player;
    vector<Room> rooms;
    Room* bossroom = NULL;
    Room* startroom = new Room;
    Boss boss;
    Weapon  allwea[100];
    int allweaindex = 0;
    Armor allarm[100];
    int allarmindex = 0;
    Helmet allhel[100];
    int allhelindex = 0;
    Monster allmon[100];
    int allmonindex = 0;
    NPC allnpc[100];
    int allnpcindex = 0;
    Treasure_Chest alltrea[100];
    int alltreaindex = 0;
    Lock alllock[100];
    int alllockindex = 0;

public:
    Room*** mapp = (Room***)calloc(7, sizeof(Room**) * 1);
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent(Object*);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction();

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();
    void showStatus();
    void showBackpack();
    void printMap();
};

#endif // DUNGEON_H_INCLUDED
