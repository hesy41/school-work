//Siyi He
//Dec. 5, 2020
//Quiz#2-- Sorted?

#include <iostream>
using namespace std;

//phototype
bool sortedCheck (int[],int);
void GetUserInput (int[], int);

int main ()
{
    //varible 
    int q;
    int intNumber;

    //input 
    cout << "Enter the number of integers in the list : ";
    cin  >> intNumber;

    //array defined
    int arrInt[intNumber];

    GetUserInput(arrInt, intNumber);
    
    //processing
    if (sortedCheck(arrInt, intNumber) == true)
        cout << "The list is sorted!" << endl;
    else 
        cout << "The list is NOT sorted!" << endl;

    return 0;
}

//function definition 
void GetUserInput (int arr[], int size)
{ 
    int i;

    for (i=0; i < size; i++)
    {
        cout << "Enter a number : ";
        cin  >> arr[i];
    }
}

bool sortedCheck (int arr[], int size)
{
    int i;

    if (size == 0 || size == 1)
        return true;
    
    for (i=1; i<size; i++)
    {
        if (arr[i-1] > arr[i])
            return false;
    }
    return true;
}