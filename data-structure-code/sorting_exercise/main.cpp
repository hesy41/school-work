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
void MergeSort(int arr[], int size);
void QuickSort(int arr[], int size);
void HeapSort(int arr[], int size);

int main(){
    int array[10]={45, 23, 100, 12, 67, 901, 230, 4, 45, 511};
    int size = sizeof(array)/sizeof(array[0]);

    //StraightSelectionSort(array,size);
    //BubbleSort(array,size);
    //InsertionSort(array, size);
    //MergeSort(array, size);
    //QuickSort(array, size);
    HeapSort(array, size);
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

/*merge sort*/
void Spilt(int arr[], int head, int tail);
void Merge(int a[], int head, int mid, int tail);

void MergeSort(int arr[], int size)
{
    Spilt(arr, 0, size-1);
}

void Spilt(int arr[], int head, int tail)
{   
    //base case: stop when the subarray have one element
    if (head >= tail) 
        return;
    else 
    {
        int mid = (head+tail)/2;
        Spilt(arr, head, mid);
        Spilt(arr, mid+1,tail);
        Merge (arr, head, mid, tail);
    }
}

void Merge(int a[], int head, int mid, int tail)
{
    int subOneSize= mid - head +1;
    int subTwoSize=tail - mid;

    int* subOne= new int[subOneSize];
    int* subTwo = new int[subTwoSize];

    for (int i=0; i<subOneSize; i++) //copy data to the sub array
        subOne[i] = a[head + i];
    for (int j=0; j<subTwoSize; j++)
        subTwo[j] = a[mid+j+1];

    int indexOne = 0;
    int indextwo = 0;
    int indexMerged = head;

    while (indexOne<subOneSize && indextwo<subTwoSize)
    {
        if (subOne[indexOne]<subTwo[indextwo])
        {
            a[indexMerged] = subOne[indexOne];
            indexOne++;
            indexMerged++;
        }
        else
        {
            a[indexMerged] = subTwo[indextwo];
            indextwo++;
            indexMerged++;
        }
    }
    while (indexOne<subOneSize) 
    {
        a[indexMerged] = subOne[indexOne];
        indexOne++;
        indexMerged++; 
    }

    while (indextwo<subTwoSize)
    {
        a[indexMerged] = subTwo[indextwo];
        indextwo++;
        indexMerged++;
    }
    
    delete []subOne;
    delete []subTwo;
}
/*------------------------------------------------------*/

/*quick sort*/
void QuickSortRecursion(int arr[], int first, int last);
int partition(int arr[], int first, int last);

void QuickSort(int arr[], int size)
{
    QuickSortRecursion(arr, 0, size-1);
}

void QuickSortRecursion(int arr[], int first, int last)
{
    if (first<last)
    {
        int PivotIndex = partition(arr, first, last);
        QuickSortRecursion(arr, first, PivotIndex-1);
        QuickSortRecursion(arr, PivotIndex+1, last);
    }
}

int partition(int arr[], int first, int last)
{
    int pivot = arr[last];
    int pivotIndex = first;

    for(int i=first; i<last; i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[last]);
    return pivotIndex;
}
/*-----------------------------------------------------*/

/*heap sort*/
void ReheapDown(int arr[], int size, int index);

void HeapSort(int arr[], int size)
{   //turn the array into a heap
    for (int i=size/2 -1; i>=0; i--)
        ReheapDown(arr, size, i);
    for (int i=size -1; i>0; i--)
    {   
        //put the largest index to the bottom of the array
        swap(arr[0], arr[i]);
        //get the largest value to be the root (a[0])
        ReheapDown(arr, i-1, 0);
    }
}

void ReheapDown(int arr[], int size, int index)
{   
    // first assume the root has largest value
    int largestIndex = index;
    int leftIndex = 2*index+1;
    int rightIndex = 2*index+2;

    if (leftIndex<size && arr[leftIndex]>arr[largestIndex])
        largestIndex = leftIndex;
    if (rightIndex<size && arr[rightIndex]>arr[largestIndex])
        largestIndex = rightIndex;
    if (largestIndex != index)
    {
        swap(arr[largestIndex], arr[index]);
        ReheapDown(arr, size, largestIndex);
    }
}
/*-----------------------------------------------------*/

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