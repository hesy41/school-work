/* data structure: homework 5 heap.cpp
   author: Siyi He
   create on 2021-11-18
*/

#include <iostream>
#include "heap.h"
using namespace std;

//template <class ItemType> 
void swap(ItemType& one, ItemType& two) 
{ 
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}

//template<class ItemType> 
void HeapType::ReheapUp(int root, int bottom) 
{
    int parent;

    if (bottom>root)
    {
        parent=(bottom-1)/2;
        if (elements[parent].ComparedTo(elements[bottom])== LESS)
        {
            swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }

}

//template<class ItemType> 
void HeapType::ReheapDown(int root, int bottom) 
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root*2 + 1;
    rightChild = root*2 + 2;

    if (leftChild <= bottom) // did not reach the end--> reheap down continute
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if(elements[leftChild].ComparedTo(elements[rightChild]) == LESS 
                || elements[leftChild].ComparedTo(elements[rightChild]) == EQUAL)
                maxChild=rightChild;
            else
                maxChild=leftChild;
        }
        if (elements[root].ComparedTo(elements [maxChild])==LESS)
        {
            swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }

}