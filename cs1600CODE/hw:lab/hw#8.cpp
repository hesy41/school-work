//Siyi He
//Nov. 10, 2020
//R02- hw#8 24hours notation 

#include <iostream>
using namespace std;

//prototype 
void getUserInput (int&, string&);
void convertTo12 (int&);
char amAndpm (int&);

int main ()
{
    //varibles
    int hours;
    string minutes;
    char timeblock, answer;

    do 
    {
        //input
        getUserInput (hours, minutes); //do not put the '&' reference here 

        //processing
        timeblock = amAndpm (hours);
        convertTo12 (hours);

        //output
        cout << "success: " << hours << ":" << minutes << " " << timeblock << "M !" << endl;

        cout << "Do you want another notation? [Y]es; [N]o.";
        cin  >> answer;

        cout << endl;
        
    } while (answer == 'Y'|| answer == 'y');

    return 0;
}

//function def
void getUserInput (int& h, string& m)
{
    char sep;

    cout << "Enter a 24-hour notation string (HH : MM): " ;
    cin  >> h >> sep >> m;
}

void convertTo12 (int& hr)
{
    if (hr > 12)
    {
        hr = hr - 12;
    }
}

char amAndpm (int& hr)
{
    char time;

    if ( hr >= 0 && hr <= 11)
        {
            return 'A';
        }
    else 
        {
            return 'P';
        }
}

//I used "string" to store the varible "minute" becase if I use int, 11:08 will be converted to 11:8 AM.
//We usually use 08 to represent 8 minites after 11 O'clock. 11:8 is kind of wired. 
//And we don't need to do calculation about minute in this 24-hour notation, so I use string instead.