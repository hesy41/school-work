/*self exercise
  practice for sorting algorithms
  author: Siyi He*/

#include <iostream>
using namespace std;

//function protype
void print_array(int[], int);
void swap(int&, int&);

void StraightSelectionSort(int[],int);
void BubbleSort(int[], int size);
void InsertionSort(int[], int size);

int main(){
    int array[10]={45, 23, 100, 12, 67, 901, 230, 4, 55, 511};
    int size = sizeof(array)/sizeof(array[0]);

    //StraightSelectionSort(array,size);
    //BubbleSort(array,size);
    InsertionSort(array, size);
    print_array(array, size);

    return 0;
}

//FUNCTION DEF
/*Straight Selection Sort*/
void sss(int a[], int size, int position);

void StraightSelectionSort(int arr[], int size)
{
    int current_position=0;
    sss(arr,size,current_position);
}

void sss(int a[], int size, int position)
{
    int smallest_position = position;

    if (position < size)
    {
        for (int i=position; i<size; i++)
        {
            if (a[i] < a[smallest_position])
                smallest_position = i;
        }

        swap(a[smallest_position], a[position]);
        position++;
        sss(a, size, position);
    }
}
/*------------------------------------------------------*/

/*bubble sort*/
void BubbleSort(int arr[], int size)
{
    bool swapping = false;
    for (int i=0; i<size; i++)
    {
        for (int j= size-1; j>i; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j], arr[j-1]);
                swapping = true;
            }
        }
        if (swapping == false)
            return;
    }
}
/*-------------------------------------------------------*/

/*insertion sort*/
void insert(int[], int size, int key);

void InsertionSort (int arr[], int size)
{
    for (int key=0; key<size; key++)
    {
        if (arr[key+1]<arr[key])
            insert(arr, size, key);
    }
}

void insert(int a[], int size, int key)
{
    int predecessor = a[key+1];

    while (predecessor < a[key] && key>=0)
    {
        swap (a[key+1], a[key]);
        key--;
    }
}
/*--------------------------------------------------------*/
void print_array(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout << "array[" << i << "] is " << arr[i] << endl;
    }
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}