//Siyi He
//Nov. 20, 2020
//R02- lab#9 sales bar chart 

#include <iostream>
using namespace std;

//prototype
void getUserInput (int[ ], int);
int storeSum (int[], int);
int storeHighest (int[], int);
int storeHighestNum (int[], int);
void barChartConverstion (int[], int);

const int max_store = 5;

int main()
{
    //varible
    int store[max_store], totalStores, maxStore, highestStore;
    int z;

    //input
    getUserInput (store, max_store);

    //processing
    totalStores = storeSum (store, max_store);
    maxStore = storeHighest (store, max_store);
    highestStore = storeHighestNum (store, max_store); 

    //output
    cout << endl;
    cout << "SALES BAR CHART" << endl;
    cout << "(Each * = $100)" << endl;
    cout << endl;

    barChartConverstion (store, max_store);
    
    cout << endl;
    cout << "Store # " << highestStore << " had the highest: " << maxStore << endl; 
    cout << endl;
    cout << "Total for all stores was : " << totalStores << endl;

    

    return 0;
}

//function definitio
void getUserInput (int array[ ], int size)
{
    int x;

    for ( x = 0; x < size; x++)
    {
        cout << "Enter today’s sales for store " << x+1 << " : ";
        cin  >> array[x];
    }
}

//function definition
int storeSum (int array[], int size)
{
    //varible 
    int x, sum;
    
    //init
    sum = 0;

    for (x = 0; x < size; x++)
    {
        sum = sum + array[x];
    }

    return sum;
}

//function definition 
int storeHighest (int arr[], int size)
{
    int x;
    int max = arr[0]; 

    for (x=0; x < size; x++)
    {
        if (arr[x] > max)
        {
            max = arr[x];
        }
    }

    return max;
}

//function def
int storeHighestNum (int arr[], int size)
{
   int x, highest;
    int max = arr[0]; 

    for (x=0; x < size; x++)
    {
        if (arr[x] > max)
        {
            max = arr[x];
            highest = x + 1;
        }
    }

    return highest; 
}

//function def 
void barChartConverstion (int arr[], int size)
{
    int x, y, store, starNum;
    string barChart[size], star;

    for (x=0; x< size; x++)
    {
        //init
        star = " ";
        
        //processing 
        store = arr[x];
        starNum = store / 100;

        for (y = 0; y < starNum; y++)
        {
            star= star + "*";
        }
        
        barChart[x] = star;

        cout << "Store " << x + 1 << " : " << star << endl;
    }
}