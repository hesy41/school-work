/* data structure: homework 5 main.cpp
   author: Siyi He
   create on 2021-11-18
*/

#include <iostream>
#include "pqtype.h"
using namespace std;

//template<class ItemType> 
int main(){
    
    PQType pq(6);

    ItemType a, b, c, d,e,f;

    a.Initialize(30);
    b.Initialize(240);
    c.Initialize(20);
    d.Initialize(150);
    e.Initialize(230);
    f.Initialize(40);

    pq.Enqueue(a);
    pq.Enqueue(b); 
    pq.Enqueue(c);
    pq.Enqueue(d); 
    pq.Enqueue(e); 
    pq.Enqueue(f);
    /* try
    {
        pq.Enqueue(d);
    }
    catch(FullPQ& e)
    {
        cout<< "dont enqueue a full  heap\n";
    } */

    if (pq.IsFull())
        cout<< "is full" << endl;
    else
        cout<< "not full" << endl;

    /* pq.Dequeue(a);
    pq.Dequeue(b);
    pq.Dequeue(c);
    pq.Dequeue(d); */

    if (pq.IsEmpty())
        cout<< "is empty" << endl;
    else
        cout<< "not empty" << endl;

    return 0;
}