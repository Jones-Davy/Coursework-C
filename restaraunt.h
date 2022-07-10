#ifndef restaurant_H
#define restaurant_H
#include <QString>
#include <bits/stdc++.h>
using namespace std;

class restaurant
{

    int id;
    QString worker;
    QString form;
    double salary;
    restaurant *next, *prev;
public:
    restaurant();
    restaurant(int &id1, QString &form1, double &salary1): id(id1), form(form1), salary(salary1){}
    virtual QString getworker() {return worker;}
    QString getid() {return QString::number(id);}
    QString getform() {return form;}
    QString getsalary() {return QString::number(salary);}
    virtual ~restaurant() {}
    void setNext(restaurant* Obj) {next = Obj;}
    void setPrev(restaurant* Obj) {prev = Obj;}
    restaurant* getNext() {return next;}
    restaurant* getPrev() {return prev;}
};

class waiter: public restaurant
{

    QString age;
public:
    waiter(int &id1, QString &form1, double &salary1,  QString &age1): restaurant(id1, form1, salary1), age(age1) {}
    waiter(): restaurant() {}
    QString getworker() {return "Официант";}
    QString getage() {return age;}
};

class schef: public restaurant
{
    QString stag;
public:
    schef();
    schef(int &id1, QString &form1, double &salary1,  QString &stag1): restaurant(id1, form1, salary1), stag(stag1) {}
    QString getworker() {return "Повар";}
    QString getstag() {return stag;}
};

class guard: public restaurant
{

    QString jeton;

public:
    guard();
    guard(int &id1, QString &form1, double &salary1, QString &jeton1): restaurant(id1, form1, salary1), jeton(jeton1) {}
    QString getworker() {return "Охранник";}
    QString getjeton() {return jeton;}
};




#endif // restaurant_H
