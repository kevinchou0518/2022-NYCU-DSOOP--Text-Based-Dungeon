#ifndef LOCK_H_INCLUDED
#define LOCK_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Lock : public Object
{
private:

public:
    Lock();
    virtual bool triggerEvent(Object*);
};

#endif // LOCK_H_INCLUDED
