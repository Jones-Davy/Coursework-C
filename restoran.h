#ifndef RESTORAN_H
#define RESTORAN_H

#include "listS.h"

struct Adress
{
    QString oblast;
    QString sity;
    QString street;
    int hause;
    int index;
};

class Restoran
{
private:
    ListS employee;
    struct Adress adress;
    QString tel;
    QString name;
    Restoran *prev;
    Restoran *next;
public:
    Restoran();
    Restoran(int &index1, QString &sity1, QString &oblast1, QString &street1, int &hause1, QString &tel1, QString &name1)
    {
        adress.oblast = oblast1;
        adress.street = street1;
        adress.hause = hause1;
        adress.index = index1;
        adress.sity = sity1;
        name = name1;
        tel = tel1;
    }
    QString getRestoran() {return name + ".\n" + QString::number(adress.index) + ", " + adress.oblast + " район,\nг." + adress.sity + ", ул." + adress.street + ", д." + QString::number(adress.hause) + ".\nтелефон: " + tel;}
    QString getName() {return name;}
    QString getTel() {return tel;}
    QString getOblast() {return adress.oblast;}
    QString getSity() {return adress.sity;}
    QString getStreet() {return adress.street;}
    QString getHause() {return QString::number(adress.hause);}
    QString getIndex() {return QString::number(adress.index);}
    void setNext(Restoran* Obj) {next = Obj;}
    void setPrev(Restoran* Obj) {prev = Obj;}
    ListS& getList(){return this->employee;}
    Restoran* getNext() {return next;}
    Restoran* getPrev() {return prev;}
};


#endif // RESTORAN_H
