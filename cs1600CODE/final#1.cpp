//Siyi He
//Dec. 17, 2020
//final#1

#include <iostream>
using namespace std;

//phototype
bool check(int[], int);

int main ()
{
    //varible 
    int arrSize, i;

    //input 
    cout << "Enter the number of values: ";
    cin  >> arrSize;

    int arr[arrSize];

    for (i=0; i< arrSize; i++) //input for array
    {
        cout << "Enter a value: ";
        cin  >> arr[i];
    }

    //processing 
    if (check(arr, arrSize) == true)
    {
        cout << "The list has consecutive four numbers!" << endl;
    }
    else 
    {
        cout << "The list has no consecutive fours numbers!" << endl;
    }

    return 0;
}

//function definition 
bool check(int a[], int size)
{
    int i;
    
    for (i=0; i<size; i++)
    {
        if (a[i]==a[i+1] && a[i]==a[i+2] && a[i]==a[i+3])
        {
            return true;
        }
    }

    return false;
}