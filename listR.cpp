#include "listR.h"

ListR::ListR()
{
    Head = Tail = NULL;
    count = 0;
}
ListR::~ListR(){
    while(this->remove(this->Tail))
    {
    }
}
Restoran* ListR::remove(Restoran* restoran){
    if (!this->Head)
        return NULL;
    if(this->Head != this->Tail){

            if (restoran == this->Head) {
                this->Head = restoran->getNext();
                this->Head->setPrev(this->Tail);
                delete restoran;
                this->count--;
                return this->Head;
            }
            if (restoran == this->Tail) {
                this->Tail = restoran->getPrev();
                this->Tail->setNext(this->Head);
                delete restoran;
                this->count--;
                return this->Tail;
            }
            Restoran* A;
            restoran->getPrev()->setNext(restoran->getNext());
            restoran->getNext()->setPrev(restoran->getPrev());
            A = restoran->getNext();
            delete restoran;
            this->count--;
            return A;

    }else{
        delete this->Head;
        this->Head = this->Tail = NULL;
        this->count--;
        return NULL;
    }
    return NULL;
}
void ListR::append(Restoran *A)
{
  if (count != 0)
   {
     A->setPrev(Tail);
     A->setNext(Head);
     Head->setPrev(A);
     Tail->setNext(A);
     Head = A;
   }
   else
   {
     A->setNext(A);
     A->setPrev(A);
     Head = Tail = A;
   }
   count++;
}
void ListR::Del(int n){
    int i = 0;
    Restoran *A = Tail;
    while (i < n)
    {
        A = A->getPrev();
        i++;
    }
    this->remove(A);
}
