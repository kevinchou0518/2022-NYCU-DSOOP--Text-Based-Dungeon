#include "Dungeon.h"
#include <time.h>
#include <vector>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
Dungeon::Dungeon() {};
Backpack _backpack = Backpack();
void Dungeon::createPlayer() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Enter your name:";
    string _name;
    cin >> _name;
    Backpack* backpack = &_backpack;
    this->player.setBackpack(backpack);
    this->player.setName(_name);
    this->player.setAttack(10);
    this->player.setMaxHealth(100);
    this->player.setCurrentHealth(100);
    this->player.setDefense(0);
    this->player.setCurrentRoom(this->startroom) ;
    Weapon osword;
    osword = Weapon("old_sword", 0, 0, 0);
    this->player.getBackpack()->addweapon(&osword);
    this->player.getBackpack()->initialwrightweapon();
    Weapon oshield;
    oshield = Weapon("old_shield", 0, 0, 0);
    this->player.getBackpack()->addweapon(&oshield);
    this->player.getBackpack()->initialwleftweapon();
    Armor oclothes;
    oclothes = Armor("old_clothes", 0, 0, 0);
    this->player.getBackpack()->addarmor(&oclothes);
    this->player.getBackpack()->initialwarmor();
    Helmet rhat;
    rhat = Helmet("round_hat", 0, 0, 0);
    this->player.getBackpack()->addhelmet(&rhat);
    this->player.getBackpack()->initialwhelmet();
}
void Dungeon::createMap() {
    for (int i = 0; i < 7; i++) {
        *(mapp + i) = (Room**)calloc(7, sizeof(Room*) * 1);
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            mapp[i][j] = NULL;
        }
    }
    mapp[0][3] = new Room;
    this->startroom = mapp[0][3];
    this->startroom->setIndex_x(0);
    this->startroom->setIndex_y(3);
    fstream file;
    cout << "choose a map:" << endl;
    cout << "(a)small map for test\n";
    cout << "(b)normal map\n";
    cout << "(c)super big map\n";
    char choose;
    while (1) {
        cin >> choose;
        if (choose == 'a' || choose == 'A') {
            //fptr = fopen("smallmap.txt", "r");
            file.open("smallmap.txt", ios::in);
            break;
        }
        else if (choose == 'b' || choose == 'B') {
            //fptr = fopen("normalmap.txt", "r");
            file.open("normalmap.txt", ios::in);
            break;
        }
        else if (choose == 'c' || choose == 'C') {
            //fptr = fopen("bigmap.txt", "r");
            file.open("bigmap.txt", ios::in);
            break;
        }
        else {
            cout << "wrong input!!!\n";
            continue;
        }
    }
    if (!file) {
        cout << "file error\n";
        exit(1);
    }
    int num;                            //cin num of room
    file >> num;
    int x, y;
    for (int i = 0; i < num; i++) {
        file >> x;
        file >> y;
        mapp[x][y] = new Room;
        mapp[x][y]->setIndex_x(x);
        mapp[x][y]->setIndex_y(y);
        int numofobj;                      //cin num of item in the room
        file >> numofobj;
        for (int j = 0; j < numofobj; j++) {
            char type;
            string _name;
            file >> type;
            if (type == 'm') {  //constuct monster
                file >> _name;
                int hp;
                int atk;
                int def;
                file >> hp >> atk >> def;
                Monster monster(_name, hp, atk, def);
                allmon[allmonindex] = monster;
                mapp[x][y]->pushobject(&allmon[allmonindex]);
                allmonindex++;
            }
            else if (type == 'n') {   //construct npc
                file >> _name;
                NPC npc(_name);
                int numofitem;          //number of item
                file >> numofitem;
                vector<Equipment*> item;
                for (int i = 0; i < numofitem; i++) {
                    char type;              //item type   name hp atk def cost
                    file >> type;
                    file >> _name;
                    int hp, atk, def, cost;
                    file >> hp >> atk >> def >> cost;
                    if (type == 'w') {
                        Weapon wea(_name, hp, atk, def, cost);
                        allwea[allweaindex] = wea;
                        item.push_back(&allwea[allweaindex]);
                        allweaindex++;
                    }
                    else if (type == 'a') {
                        Armor arm(_name, hp, atk, def, cost);
                        allarm[allarmindex] = arm;
                        item.push_back(&allarm[allarmindex]);
                        allarmindex++;
                    }
                    else if (type == 'h') {
                        Helmet hel(_name, hp, atk, def, cost);
                        allhel[allhelindex] = hel;
                        item.push_back(&allhel[allhelindex]);
                        allhelindex++;
                    }
                }
                npc.setCommodity(item);
                allnpc[allnpcindex] = npc;
                mapp[x][y]->pushobject(&allnpc[allnpcindex]);
                allnpcindex++;
            }
            else if (type=='c') {
                file >> _name;
                int gold;
                file >> gold;
                int numofitem;
                file >> numofitem;
                Treasure_Chest trea(_name, gold);
                vector<Equipment*> item;
                for (int i = 0; i < numofitem; i++) {
                    char type;              //item type             name  hp atk def cost
                    file >> type;
                    file >> _name;
                    int hp, atk, def;
                    file >> hp >> atk >> def;
                    if (type == 'w') {
                        Weapon wea(_name, hp, atk, def);
                        allwea[allweaindex] = wea;
                        item.push_back(&allwea[allweaindex]);
                        allweaindex++;
                    }
                    else if (type == 'a') {
                        Armor arm(_name, hp, atk, def);
                        allarm[allarmindex] = arm;
                        item.push_back(&allarm[allarmindex]);
                        allarmindex++;
                    }
                    else if (type == 'h') {
                        Helmet hel(_name, hp, atk, def);
                        allhel[allhelindex] = hel;
                        item.push_back(&allhel[allhelindex]);
                        allhelindex++;
                    }
                }
                trea.settreasure(item);
                alltrea[alltreaindex] = trea;
                mapp[x][y]->pushobject(&alltrea[alltreaindex]);
                alltreaindex++;
            }
            else if (type == 'e') {
                char equiptype;
                file >> equiptype;
                file >> _name;
                int hp, atk, def;
                file >> hp >> atk >> def;
                if (equiptype == 'w') {
                    Weapon wea(_name, hp, atk, def);
                    allwea[allweaindex] = wea;
                    mapp[x][y]->pushobject(&allwea[allweaindex]);
                    allweaindex++;
                }
                else if (equiptype == 'h') {
                    Helmet hel(_name, hp, atk, def);
                    allhel[allhelindex] = hel;
                    mapp[x][y]->pushobject(&allhel[allhelindex]);
                    allhelindex++;
                }
                else if (equiptype == 'a') {
                    Armor arm(_name, hp, atk, def);
                    allarm[allarmindex] = arm;
                    mapp[x][y]->pushobject(&allarm[allarmindex]);
                    allarmindex++;
                }
            }
            else if (type == 'l') {
            Lock lock;
            alllock[alllockindex] = lock;
            mapp[x][y]->pushobject(&alllock[alllockindex]);
            alllockindex++;
            }
        }
        if (x > 0) {
            if (mapp[x - 1][y] != NULL) {
                //set pointer
                mapp[x][y]->setUpRoom(mapp[x - 1][y]);
                mapp[x][y]->getUpRoom()->setDownRoom(mapp[x][y]);
            }
        }
        if (x < 4) {
            if (mapp[x + 1][y] != NULL) {
                mapp[x][y]->setDownRoom(mapp[x + 1][y]);
                mapp[x][y]->getDownRoom()->setUpRoom(mapp[x][y]);
            }
        }
        if (y > 0) {
            if (mapp[x][y - 1] != NULL) {
                mapp[x][y]->setLeftRoom(mapp[x][y - 1]);
                mapp[x][y]->getLeftRoom()->setRightRoom(mapp[x][y]);
            }
        }
        if (y < 4) {
            if (mapp[x][y + 1] != NULL) {
                mapp[x][y]->setRightRoom(mapp[x][y + 1]);
                mapp[x][y]->getRightRoom()->setLeftRoom(mapp[x][y]);
            }
        }
    }
    bossroom = new Room;
    Boss _boss("dungeon_king", 100, 10, 10);
    boss = _boss;
    Lock lck;
    alllock[alllockindex] = lck;
    bossroom->pushobject(&alllock[alllockindex]);
    alllockindex++;
    bossroom->pushobject(&boss);
    mapp[x + 1][y] = new Room;
    mapp[x + 1][y] = bossroom;
    mapp[x][y]->setDownRoom(mapp[x + 1][y]);
    mapp[x][y]->getDownRoom()->setUpRoom(mapp[x][y]);
    printMap();
}


void Dungeon::handleMovement() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "go which way?" << endl;
    vector<char> order(6);
    int index = 0;
    char a = 'a';
    if (this->player.getCurrentRoom()->getUpRoom() != NULL) {
        cout << a << ":go up\n";
        a++;
        order[index] = 'u';
        index++;
    }
    if (this->player.getCurrentRoom()->getDownRoom() != NULL) {
        cout << a << ":go down\n";
        a++;
        order[index] = 'd';
        index++;
    }
    if (this->player.getCurrentRoom()->getLeftRoom() != NULL) {
        cout << a << ":go left\n";
        a++;
        order[index] = 'l';
        index++;
    }
    if (this->player.getCurrentRoom()->getRightRoom() != NULL) {
        cout << a << ":go right\n";
        a++;
        order[index] = 'r';
        index++;
    }
    char inptr;
    cin >> inptr;
    int num = 0;
    if (inptr >= 'a') {
        num = inptr - 'a';
    }
    else num = inptr - 'A';
    if (order[num] == 'u') {
        this->player.changeRoom(player.getCurrentRoom()->getUpRoom());
        this->player.setprex(player.getx());
        this->player.setprey(player.gety());
        this->player.setx(player.getx() - 1);
    }
    else if (order[num] == 'd') {
        this->player.changeRoom(player.getCurrentRoom()->getDownRoom());
        this->player.setprex(player.getx());
        this->player.setprey(player.gety());
        this->player.setx(player.getx() + 1);
    }
    else if (order[num] == 'l') {
        this->player.changeRoom(player.getCurrentRoom()->getLeftRoom());
        this->player.setprex(player.getx());
        this->player.setprey(player.gety());
        this->player.sety(player.gety() - 1);
    }
    else if (order[num] == 'r') {
        this->player.changeRoom(player.getCurrentRoom()->getRightRoom());
        this->player.setprex(player.getx());
        this->player.setprey(player.gety());
        this->player.sety(player.gety() + 1);
    }
    else cout << "wrong input\n";
}

void Dungeon::handleEvent(Object* event) {
    if (!this->player.getCurrentRoom()->emptyobject()) {
        while (!this->player.getCurrentRoom()->emptyobject()) {
            if (this->player.getCurrentRoom()->getqueue().front()->triggerEvent(event)) {
                this->player.getCurrentRoom()->popobject();
            }
            else {
                //checkGameLogic();
                break;
            }
        }
    }
    else {
        cout << "-----------------------------------------------------------" << endl;
        cout << "nothing is in the room\n";
    }
}


void Dungeon::startGame() {
    this->createMap();
    this->createPlayer();
    this->runDungeon();
}

void Dungeon::chooseAction() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "What you want to do:" << endl;
    cout << "a:move" << endl;
    cout << "b:show status" << endl;
    cout << "c:show backpack" << endl;
    cout << "d:show the map" << endl;
    char _input;
    cin >> _input;
    switch (_input) {
    case 'a':
    case 'A':
        this->handleMovement();
        this->handleEvent(&this->player);
        break;
    case 'b':
    case 'B':
        this->player.triggerEvent(&this->player);
        break;
    case 'c':
    case 'C':
        this->showBackpack();
        break;
    case 'd':
    case 'D':
        this->printMap();
        break;
    default:
        cout << "wrong input!!!\n";
        break;
    }
}

bool Dungeon::checkGameLogic() {
    if (this->player.getCurrentRoom()->getbossdead()) {
        cout << "*****************************************************************" << endl;
        cout << "Congratualation !! You defeated the final boss and escaped from the dungeon.\n\n";
        cout << "*****************************************************************" << endl;
        cout << "-----------------VICTORY-------------\n\n";
        cout << "*****************************************************************" << endl;
        return true;
    }
    else if(player.checkIsDead()){
        cout << "*****************************************************************" << endl;
        cout << "----------------You_Dead------------\n\n";
        cout << "*****************************************************************" << endl;
        cout << "---------------GAME_OVER------------\n\n";
        cout << "*****************************************************************" << endl;
        return true;
    }
    else {
        return false;
    }
}

void Dungeon::runDungeon() {
    while (1) {
        this->chooseAction();
        if (this->checkGameLogic()) {
            exit(0);
        }
    }
}

void Dungeon::showStatus() {    //useless due to we have the virtual func of Player
    cout << "-----------------------------------------------------------" << endl;
    cout << "Name: " << this->player.getName() << endl;
    cout << "Hp: " << this->player.getCurrentHealth() << "/" << this->player.getMaxHealth() << endl;
    cout << "ATK: " << this->player.getAttack() << endl;
    cout << "DEF: " << this->player.getDefense() << endl;
    cout << "Money: " << this->player.getmoney() << "$" << endl;
    cout << "Helmet:" << this->player.getBackpack()->getwhelmet()->getName()<<   endl;
    cout << "Armor:" << this->player.getBackpack()->getwarmor()->getName() << endl;
    cout << "LeftWeapon:" << this->player.getBackpack()->getwleftweapon()->getName() << endl;
    cout << "RightWeapon:" << this->player.getBackpack()->getwrightweapon()->getName() << endl;
}

void Dungeon::showBackpack()
{
    cout << "-----------------------------------------------------------" << endl;
    this->player.getBackpack()->changeequip(&this->player);
}

void Dungeon::printMap()
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "MAP:\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (mapp[i][j] == NULL) {
                cout << "   ";
            }
            else {
                if (i == player.getx() && j == player.gety()) {
                    cout << "[*]";
                }
                else cout << "[ ]";
            }
        }
        cout << endl;
    }
}









