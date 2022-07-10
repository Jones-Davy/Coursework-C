#include "listS.h"

ListS::~ListS(){
    while(this->remove(this->Tail)){
    }
}

void ListS::append(restaurant *employee){
    if (count != 0)
    {
        employee->setPrev(Tail);
        employee->setNext(Head);
        Head->setPrev(employee);
        Tail->setNext(employee);
        Head = employee;
    }
    else
    {
        employee->setNext(employee);
        employee->setPrev(employee);
        Head = Tail = employee;
    }
    count++;
}

restaurant* ListS::remove(restaurant* employee){
    if(this->Head != this->Tail){
        if(this->Head) {
            if (employee == this->Head) {
                this->Head = employee->getNext();
                this->Head->setPrev(this->Tail);
                delete employee;
                this->count--;
                return this->Head;
            }
            if (employee == this->Tail) {
                this->Tail = employee->getPrev();
                this->Tail->setNext(this->Head);
                delete employee;
                this->count--;
                return this->Tail;
            }
            restaurant* A;
            employee->getPrev()->setNext(employee->getNext());
            employee->getNext()->setPrev(employee->getPrev());
            A = employee->getNext();
            delete employee;
            this->count--;
            return A;
        }
    }else{
        delete this->Head;
        this->Head = this->Tail = NULL;
        this->count--;
        return NULL;
    }
}

void ListS::Del(int id){
    restaurant *A = Head;
    while (A->getid() != QString::number(id))
    {
        A = A->getNext();
    }
    this->remove(A);
}
