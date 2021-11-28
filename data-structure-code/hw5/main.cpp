/* data structure: homework 5 main.cpp
   author: Siyi He
   create on 2021-11-18
*/

#include <iostream>
#include "pqtype.h"
using namespace std;

//template<class ItemType> 
int main(){
    
    PQType pq(4);

    ItemType a, b, c, d;

    a.Initialize(9);
    b.Initialize(3);
    c.Initialize(40);
    d.Initialize(1);

    pq.Enqueue(a);
    pq.Enqueue(b); 
    pq.Enqueue(c);
    pq.Enqueue(d); 
    try
    {
        pq.Enqueue(d);
    }
    catch(FullPQ& e)
    {
        cout<< "dont enqueue a full  heap\n";
    }

    if (pq.IsFull())
        cout<< "is full" << endl;
    else
        cout<< "not full" << endl;

    pq.Dequeue(a);
    pq.Dequeue(b);
    pq.Dequeue(c);
    pq.Dequeue(d);

    if (pq.IsEmpty())
        cout<< "is empty" << endl;
    else
        cout<< "not empty" << endl;

    return 0;
}