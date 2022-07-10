#ifndef LISTR_H
#define LISTR_H

#include "restoran.h"

class ListR
{
private:
    Restoran *Head, *Tail;
    int count;

public:
    ListR();
    virtual ~ListR();
    Restoran* remove(Restoran* restoran);
    void append(Restoran*A);
    void Del(int n);
    int getCount() {return count;}
    Restoran* getHead() {return Head;}
    Restoran* getTail() {return Tail;}
    void setCount(int count1) {count = count1;}
    void setHead(Restoran* Obj) {Head = Obj;}
    void setTail(Restoran* Obj) {Tail = Obj;}
};

#endif // LISTR_H
