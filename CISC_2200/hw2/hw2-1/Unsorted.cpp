// Implementation file for Unsorted.h

#include "Unsorted.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType()
{
  info=new ItemType[10];
  length = 0; //the length is the current length of list 
}

UnsortedType::UnsortedType(int size)
{
    //We need this destructor to free up the dynamically allocated memory 
    // To avoid memory error 
    info=new ItemType[size];
    length = 0;//the length is the current length of list 
}

UnsortedType::~UnsortedType()
{
    delete info;
}

bool UnsortedType::IsFull() const
{
    int arrSize = *(&info + 1) - info;
    if (arrSize == length)
        return true;
    else 
        return false;
}

ItemType& UnsortedType::operator[](int index)
{
   int arrSize = *(&info + 1) - info; //get the current size of info
   ItemType a;//with default constructor a.value=0
   ItemType* NewArrPtr; // create a pointer for the new array
   if (index >=arrSize)
   {
       //allocate a larger size for the new array to contain the index
       NewArrPtr = new ItemType [index+5]; 
       for (int i=0; i<arrSize; i++)
       {
           NewArrPtr[i]=(*this).info[i];//copy info[] to NewArrPtr
       }
       for (int j=arrSize; j<index+5; j++)
       {
           NewArrPtr[j]= a;//set all empty array to 0
       }
       delete []info; //delete the old array
       info = NewArrPtr;//reassign the new pointer 
   }
   return *(info+index);
}

int UnsortedType::GetLength() const
{
  return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been returned;
//       otherwise, item is returned.
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found)
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    :
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
  return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
    if ((*this).IsFull())
    {
        int arrSize = *(&info + 1) - info; //get the current size of info
        ItemType* NewArrPtr; // create a pointer for the new array 
        NewArrPtr = new ItemType [arrSize+1]; 
        for (int i=0; i<arrSize; i++)
        {
           NewArrPtr[i]=(*this).info[i];//copy info[] to NewArrPtr
        }
        NewArrPtr[arrSize]=item;//put item to the last seat of array
        delete[] info;
        info = NewArrPtr;
        length++;
    }
    else
    {
        info[length] = item;
        length++;
    }
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}