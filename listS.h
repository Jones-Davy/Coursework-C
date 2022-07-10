#ifndef LISTS_H
#define LISTS_H


#include "restaraunt.h"

class ListS
{
private:
    restaurant *Head, *Tail;
    int count;
public:

    void append(restaurant* employee);
    ListS():Head(NULL),Tail(NULL),count(0){}
    virtual ~ListS();
    restaurant* remove(restaurant* employee);
    void Del(int id);
    int getCount() {return this->count;}
    restaurant* getHead() {return this->Head;}
    restaurant* getTail() {return this->Tail;}
    void setCount(int count) {this->count = count;}
    void setHead(restaurant* Obj) {this->Head = Obj;}
    void setTail(restaurant* Obj) {this->Tail = Obj;}
};

#endif // LISTS_H
