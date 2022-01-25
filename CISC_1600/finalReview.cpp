#include <iostream>
using namespace std;

//phototype
void input(int[], int);
void display(int[], int);
void stats(int[], int);
int  count(int[], int, int);
void search(int[], int);
void replace(int[], int);

const int maxSize = 5;

int main ()
{
    //varible 
    int arr[maxSize], findNum, numTimes;
    
    //processing 
    input(arr, maxSize);
    cout << endl;
    display(arr, maxSize);
    cout << endl; 
    stats(arr, maxSize);
    cout << endl;

    //code for cout()
    cout << "Enter a number to find in the array: ";
    cin  >> findNum;
    numTimes = count(arr, maxSize, findNum);
    cout << endl; 
    cout << "For number " << findNum << ", it was found " << numTimes << " time(s) in the array." << endl;
    cout << endl;

    search (arr, maxSize);
    cout << endl;
    replace (arr, maxSize);
    cout << endl;

    return 0;
}

//function definition 
void replace(int a[], int size)
{
    int formerN, newN, i;

    cout << "Which number do you want to be replaced? ";
    cin  >> formerN;
    cout << "The new number you want to put in is: ";
    cin  >> newN;
    cout << endl;

    for (i=0; i<size; i++)
    {
        if (a[i] == formerN)
        {
            a[i] = newN;
            break;
        }
    }

    cout << "the new array would look like this." << endl;
    cout << endl;
    display (a, size);
}

void search(int a[], int size)
{
    int num, i;

    cout << "enter the number you want to search: ";
    cin  >> num;

    for (i=0; i< size; i++)
    {
        if (a[i] == num)
        {
            cout << "the number you want to search is in position " << i+1 << endl;
            break;
        }

        if (i == size-1)
        {
            cout << "the target number is not in this array." << endl;
        }
    }
}

int count(int a[], int size, int num)
{
    int i, count=0;

    for (i=0; i<size; i++)
    {
        if (a[i] == num)
            count ++;
    }

    return count;
}

void input(int a[], int size)
{
    int i;

    for (i=0; i<size; i++)
    {
        cout << "Enter a number to put into the array: ";
        cin  >> a[i];
    }
}
    
void display(int a[], int size)
{
    int i;

    cout << "position      value" << endl;
    cout << "-------------------" << endl;

    for (i=0; i<size; i++)
    {
        cout << i+1 << "             " << a[i] << endl;
    }
}

void stats(int a[], int size)
{
    int i, max, min, sum; 
    double average;

    max = a[0];
    min = a[0];
    sum = a[0];

    for (i=1; i<size; i++)
    {
        if (a[i]> max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }

        sum = sum+ a[i];
    }

    average = sum / size;

    cout <<"the maximum of all the elements in the array is " << max << endl;
    cout <<"the minimum of all the elements in the array is " << min << endl;
    cout <<"the sum of all the elements in the array is " << sum << endl;
    cout <<"the average of all the elements in the array is " << average << endl;
}