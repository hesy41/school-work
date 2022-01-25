/* data structure: homework 5 PQType.cpp
   author: Siyi He
   create on 2021-11-18
*/

#include <iostream>
//#include "heap.h"
#include "pqtype.h"
using namespace std;

//template<class ItemType>
PQType::PQType(int max)
{
    maxItems = max;
    items.elements=new ItemType[max];
    length = 0;
}

//template<class ItemType>
PQType::~PQType()
{
    delete []items.elements;
}

//template<class ItemType>
void PQType::MakeEmpty()
{
    length=0;
}

//template<class ItemType>
bool PQType::IsEmpty()const
{
    return (length == 0);
}

//template<class ItemType>
bool PQType::IsFull()const
{
    return (length == maxItems);
}

//template<class ItemType>
void PQType::Enqueue(ItemType newItem)
{
    if (length == maxItems)
        throw FullPQ();
    else   
    {
        length++;
        items.elements[length-1]=newItem;
        items.ReheapUp(0,length-1);
    }
}

//template<class ItemType>
void PQType::Dequeue(ItemType& deletedItem)
{
    if (length==0)
        throw EmptyPQ();
    else
    {
        deletedItem=items.elements[0];
        items.elements[0]=items.elements[length-1];
        length--;
        items.ReheapDown(0, length-1);
    }
}