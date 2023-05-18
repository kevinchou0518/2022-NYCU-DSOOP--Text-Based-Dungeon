#include "Equipment.h"

Equipment::Equipment():Object(){}

Equipment::Equipment(string name,int hth,int atk,int def, char kind):Object(name,"Equipment"),Health(hth),Attack(atk),Defense(def),whichkind(kind){}

Equipment::Equipment(string name, int hth, int atk, int def, char kind, int cost): Object(name, "Equipment"), Health(hth), Attack(atk), Defense(def), whichkind(kind) ,cost(cost)
{
}

void Equipment::setAttack(int num) {
	this->Health = num;
}
void Equipment::setDefense(int num) {
	this->Defense = num;
}
void Equipment::setcost(int c)
{
	this->cost = c;
}
int Equipment::getcost()
{
	return this->cost;
}
void Equipment::setkind(char kind)
{
	this->whichkind = kind;
}
void Equipment::setwear(bool b)
{
	this->beingwear = b;
}
void Equipment::setHealth(int num) {
	this->Health = num;
}
int Equipment::getHealth() {
	return this->Health;
}
int Equipment::getAttack() {
	return this->Attack;
}
int Equipment::getDefense() {
	return this->Defense;
}
bool Equipment::getwear()
{
	return this->beingwear;
}
char Equipment::getkind()
{
	return this->whichkind;
}
bool Equipment::triggerEvent(Object*)
{
	return false;
}
bool Equipment::triggerBackpack(Object*)
{
	return false;
}

