/* data structure: homework 5 PQType.cpp
   author: Siyi He
   create on 2021-11-18
*/

#include <iostream>
#include "heap.h"
//#include "heap.cpp" 
using namespace std;

#ifndef PQTYPE_H
#define PQTYPE_H

class FullPQ{}; 
class EmptyPQ{}; 

//template<class ItemType> 
class PQType 
{ 
    public:
        PQType(int); 
        ~PQType(); 
        void MakeEmpty(); 
        bool IsEmpty() const; 
        bool IsFull() const; 
        void Enqueue(ItemType newItem); 
        /* Function: Adds newItem to the rear of the queue. 
        if (the priority queue is full) exception FullPQ is thrown; 
        else newItem is in the queue */ 

        void Dequeue(ItemType& item); 
        /* Function: Removes element with highest priority from the queue and returns it in item. 
        If (the priority queue is empty) exception EmptyPQ is thrown; 
        else highest priority element has been removed from queue. 
        item is a copy of removed element */

    private:
        int length; 
        HeapType items; 
        int maxItems; 
};

#endif