//CSII-hw#1-calendar
#include <iostream>
#include <iomanip>
#include <string>  
using namespace std;

//prototype
void print_calendar (int, int);
const int DAYS_PER_WEEK=7;

int main()
{
   int days, weekday;
   cout << "Number of days: " << endl;
   cin >> days;
   
   cout << "Weekday of first day (0 = Sunday): " << endl;
   cin >> weekday;
   
   cout << " Su Mo Tu We Th Fr Sa" << endl;
   print_calendar(weekday, days);
   
   return 0;
}

//function def
void print_calendar (int weekdays, int days)
{
    int total = days+ weekdays, i, a=0;
    string number;
    string arr[total];

    for (i=0; i<total; i++)
    {
        int b = i+1, c = total -1;
        if (i < weekdays)
            {
                cout << setw(3) << ' ';
            }
        else if (b % 7 == 0 || i == c)
            {
                a=a+1;
                cout << setw(3) << a << endl;
            }
        else 
            {
                a = a+1;
                cout << setw(3) << a;
            }
    }
}