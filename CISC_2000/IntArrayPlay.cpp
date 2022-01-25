/* Working with arrays and functions
 * Author: Siyi He 
 * Last modified on: Mar 4 (Thu) 
 * Known bug
 */ 
#include <iostream>

using namespace std;

const int CAPACITY=20;

// displayArray - display the array on a single line separated by blanks.
// @param: int array[] is an unordered array of integers
// @param: int numberOfElements
// [Already implemented]                            [Already implemented]
void displayArray(int array[], int numElements);

//ToDo: Declare a function fillArray that fills an int array with values entered
// by the user. Stop reading when the user inputs -1 or you reach CAPACITY.
// @param: int array[] is an unordered array of integers when leaving this function
// @param: int& numberElements is the number of Elements in the array after function
// @returns void.
void fillArray(int array[], int& numElements);

//ToDo: Declare a function that removes (i.e., deletes) the element
// removeElement - removes the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int numberElements
// @param: int position of element to delete
// @returns: true if delete was successful, false otherwise
bool removeElement(int array[], int numElements, int positionD);

//ToDo: Delcare a function that inserts the element in the given position
// insertElement - insert the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int numberElements
// @param: int position to insert into
// @param: int target to insert.
// @returns: true if insert was successful, false otherwise
bool insertElement(int array[], int numElements, int positionIn, int target);

//ToDo: Declare a function that searches for an element in the given array
// searchElement - searches for the element in the given array.
// @param int array[] is an unordered array of integers
// @param int numberOfElements
// @param int target
// @returns index of element or -1 if not found.
int searchElement(int array[], int numElement, int target);

int main()
{
  // The NumArray can be partially filled, we use variable NumArrayElems to keep track of how many numbers
  // have been stored in the array. 
  int NumArray[CAPACITY];	// an int array with a given CAPACITY
  int NumArrayElems=0, valueInsert, positionInsert;
  int valueDelete, foundPosition, valueAppend, positionAppend;   // the array is initially empty, i.e., contains 0 elements
  bool station;

  // 1. ToDo: Call your fillArray function to read in a sequence of integer values,
  // separated by space, and ending with -1. Store the values in the NumArray array 
  // and the number of elements in NumArrayElems.
  // Display the contents of the array afterwards 
  fillArray(NumArray, NumArrayElems);
  displayArray(NumArray,NumArrayElems);

  // 2. ToDo: Read in a value and position from the user. Call your insertElement function
  // to insert the given value into the given position of the array 
  // Display the contents of the array afterwards 
  cout << "Enter a value and a position to insert: ";
  cin  >> valueInsert >> positionInsert;
  NumArrayElems = NumArrayElems +1;
  station = insertElement(NumArray, NumArrayElems, positionInsert, valueInsert);
  if (station == false)
  {
    NumArrayElems = NumArrayElems -1;
  }
  displayArray(NumArray,NumArrayElems);

  // 3. ToDo: Read in a value and call your searchElement function.
  // if the value is  found, delete it from the array using your function
  // if the value not found, print "Value not found in array"
  // Display the contents of the array afterwards 
  cout << "Enter a value to delete from the array: ";
  cin  >> valueDelete;
  foundPosition = searchElement(NumArray, NumArrayElems, valueDelete);
  /* cout << foundPosition << endl; */
  if (foundPosition == -1)
  {
    cout << "Value not found!" << endl; 
  }
  else 
  {
    station = removeElement (NumArray, NumArrayElems, foundPosition);
    if (station == true)
    {
      NumArrayElems = NumArrayElems -1;
    }
    displayArray(NumArray,NumArrayElems);
  }


  // 5. TODO: Read in a value and call your insertElement function to append
  // a value to the end of the array 
  // Display the contents of the array afterwards 
  cout << "Enter a value to append: ";
  cin  >> valueAppend;
  if (NumArrayElems == CAPACITY)
    displayArray(NumArray,NumArrayElems);
  else 
  {
    NumArrayElems = NumArrayElems + 1;
    positionAppend = NumArrayElems - 1;
    station = insertElement (NumArray, NumArrayElems, positionAppend, valueAppend);
    displayArray(NumArray,NumArrayElems);
  }
  return 0;
}

//TODO: Implement all functions declared above.
//Don't forget to put precondition/postcondition comments under or over the function header.

//removeElement- to delete an element from the array
//pre: an array with an element about to delete 
//post: an array that without the target elememnt 
bool removeElement (int array[], int numElement, int position)
{
  int i, temp;
 if (position < 0)
    return false;
  else if (position > numElement)
    return false;
  else 
  {
    for (i= position; i< numElement; i++)
    {
      temp = i+1;
      array[i] = array[temp];
    }
  }
  return true;
}

//searchElement- find the target element and return the positon 
//pre: an array and an element to find
//post: the same array and a target position 
int searchElement (int array[], int numElement, int target)
{
  int i, last = numElement -1;
  for (i = 0; i< numElement; i++)
  {
    if (array[i] == target)
    {
      return i;
      break;
    }
  }
  return -1;
}

//insertElement - a function to insert a number into target posilition 
//precon: original array with target value and position 
//postcon: an array with new element inserted 
bool insertElement (int array[], int numElements, int position, int value)
{
  int i, temp;
  if (position < 0)
    return false;
  else if (position > numElements)
    return false;
  else if (numElements == CAPACITY)
    return false;
  else 
  {
    for (i = numElements; i > position; i --)
    {
      temp = i - 1; 
      array[i] = array[temp];
    }
    //inserting 
    array[position] = value;
  }

  return true;
}

//fillArray - a function to input oringinal array elements
//precon: an empty array[]
//postcon: array[] is containing user input 
void fillArray(int array[], int& numElements)
{
  int i;
  cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;
  for (numElements = 0; numElements <= CAPACITY; numElements++)
  {
    cin >> i;
    if (i != -1 && numElements < 20)
    {
      array[numElements] = i;
    }
    else 
      break;
  }
}

// displayArray - displays the array
// precondition: int array[] is an unordered array of numElems integers.
// postcondition: array is displayed on the console on a single line separated by blanks.
void displayArray(int array[], int numElems)
{
    for (int i = 0; i < numElems; i++)
        cout << array[i] << " ";
    cout << endl;
}

