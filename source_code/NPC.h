#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Equipment.h"

using namespace std;

class NPC : public GameCharacter
{
private:
    string script;
    vector<Equipment*> commodity;
    int numofpotion = 5;
    int numofkey = 5;
public:
    NPC();
    NPC(string, string, vector<Equipment*>);
    NPC(string);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setpotion(int);
    void setkey(int);
    void setScript(string);
    void setCommodity(vector<Equipment*>);
    string getScript();
    vector<Equipment*> getCommodity();
    int getpotion();
    int getkey();
};

#endif // NPC_H_INCLUDED
