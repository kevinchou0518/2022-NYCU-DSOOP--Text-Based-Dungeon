#include "Room.h"
#include <queue>
using namespace std;
Room::Room() {}

Room::Room(bool _isexit, int _index_x, int _index_y, queue<Object*> _objects) :isExit(_isexit), index_x(_index_x), index_y(_index_y),
                                                                                objects(_objects) {}

void Room::popobject()
{
    this->objects.pop();
}
void Room::pushobject(Object* obj)
{
    objects.push(obj);
}
bool Room::emptyobject()
{
    return this->objects.empty();
}
Object* Room::frontobject()
{
    return this->objects.front();
}
void Room::setUpRoom(Room* _room) {
    this->upRoom = _room;
}
void Room::setDownRoom(Room* _room) {
    this->downRoom = _room;
}
void Room::setLeftRoom(Room* _room) {
    this->leftRoom = _room;
}
void Room::setRightRoom(Room* _room) {
    this->rightRoom = _room;
}
void Room::setIsExit(bool _exit) {
    this->isExit = _exit;
}
void Room::setIndex_x(int _index) {
    this->index_x = _index;
}
void Room::setIndex_y(int _index) {
    this->index_y = _index;
}
bool Room::getIsExit() {
    return isExit;
}
int Room::getIndex_x() {
    return index_x;
}
int Room::getIndex_y() {
    return index_y;
}

Room* Room::getUpRoom() {
    return upRoom;
}
Room* Room::getDownRoom() {
    return downRoom;
}
Room* Room::getLeftRoom() {
    return leftRoom;
}
Room* Room::getRightRoom() {
    return rightRoom;
}
queue <Object*> Room::getqueue() {
    return this->objects;
}

void Room::setbossdead(bool dead){
    this->bossdead=dead;
}
bool Room::getbossdead(){
    return this->bossdead;
}
