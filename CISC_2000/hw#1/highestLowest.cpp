//CSII-hw#1-Highest Lowest
#include <iostream>
using namespace std;

// phototype
int highestLowest (int&, int&);

int main()
{
   int first, last, range;

   cout << "Enter the first value in the range: ";
   cin >> first;
   cout << "Enter the last value in the range: ";
   cin >> last;
   
   range = highestLowest (first, last);
   
   cout << "The size of the range is " << range << endl;
   if (range > 0)
   {
       // ToDo: Print the computed values here.
       cout << "The lowest even value is " << first << endl;
       cout << "The highest even value is " << last << endl;
   }
   return 0;
}

//function def
int highestLowest (int& lowest, int& highest)
{
    int range, temp, h, l;
    
    if (highest < lowest) // when the first num is less than the second num, exchange the two value
        return -1;

    h = highest;
    l = lowest; //temp value for calcuating range

    if (highest % 2 == 1)
    {
        highest = highest - 1;
    }
    else 
    {
        h = h + 1;
    }

    if (lowest % 2 == 1)
    {
        lowest = lowest + 1;
    }
    else 
    {
        l = l - 1;
    }
    
    //range calculation
    range = h - l - 1;

    return range;
}
