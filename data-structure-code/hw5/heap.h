/* data structure: homework 5 heap.h
   author: Siyi He
   create on 2021-11-18
*/

#include <iostream>
#include "ItemType.h"
using namespace std;

#ifndef HEAP_H
#define HEAP_H

//template <class ItemType> 
void swap(ItemType& one, ItemType& two); // it is a helper function but not member function 

//template<class ItemType> 
// Assumes ItemType is either a built-in simple type or a class // with overloaded relational operators.
struct HeapType{
    void ReheapDown(int root, int bottom); 
    void ReheapUp(int root, int bottom); 
    ItemType* elements; // Array to be allocated dynamically int numElements; 
};
#endif