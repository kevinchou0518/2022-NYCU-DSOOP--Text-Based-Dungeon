#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Object.h"
using namespace std;

class Room
{
private:
    Room* upRoom = NULL;
    Room* downRoom = NULL;
    Room* leftRoom = NULL;
    Room* rightRoom = NULL;
    bool isExit;
    bool bossdead=false;
    bool havevisit = false;
    int index_x;
    int index_y;
    queue<Object*> objects;
    //vector<Object*> objects;
public:
    Room();
    Room(bool, int, int, queue<Object*>);
    void popobject();
    void pushobject(Object*);
    bool emptyobject();
    Object* frontobject();
    void setbossdead(bool);
    bool getbossdead();
    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex_x(int);
    void setIndex_y(int);
    bool getIsExit();
    int getIndex_x();
    int getIndex_y();
    queue<Object*> getqueue();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
};

#endif // ROOM_H_INCLUDED
