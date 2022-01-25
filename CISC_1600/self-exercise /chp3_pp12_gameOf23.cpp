//Siyi He
//Oct, 20, 2020
//R02- selfpractise chp3 programming project 12 - game of 23

#include <iostream>
using namespace std;

int main ()
{
    //varible 
    int toothpicksNum, humanDraw, CompDraw;

    //init
    toothpicksNum = 23;

    do 
    {
        //human input
        cout << "How many toothpicks you want to withdraw? ";
        cin  >> humanDraw;

        //human input check 
        if (humanDraw > toothpicksNum)
        {
            cout << "You cannot withdraw more toothpicks than exist in the pile." << endl;

        }
        if ( !(humanDraw >= 1 && humanDraw <= 3))
        {
            cout << "You can only withdraw either 1, 2, or 3 toothpicks at a time." << endl;

            break;
        }
        
            
        //human input processing 
        toothpicksNum = toothpicksNum - humanDraw;
        cout << "There are " << toothpicksNum << " toothpicks remaining." << endl;
        cout << endl;

        //computer processing
        if (toothpicksNum > 4)
        {
            CompDraw = 4 - humanDraw;
            cout << "Computer withdraw " << CompDraw << " toothpicks." << endl;
            toothpicksNum = toothpicksNum - CompDraw;
            cout << "There are " << toothpicksNum << " toothpicks remaining." << endl;            
        }
        else if (toothpicksNum >= 2 && toothpicksNum <=4)
        {
            CompDraw = toothpicksNum - 1;
            cout << "Computer withdraw " << CompDraw << " toothpicks." << endl;
            toothpicksNum = toothpicksNum - CompDraw;
            cout << "There are " << toothpicksNum << " toothpicks remaining." << endl;  
        }
        else if (toothpicksNum == 1)
        {
            toothpicksNum--;
            cout << "Computer takes the last toothpick. Computer lost!" << endl;
        }
        cout << endl;
    }
    while (toothpicksNum > 1 );

    //output
    if (toothpicksNum == 1)
    {
        cout << "Human lost! You have to take the last toothpick!" << endl;
    }
    
    cout << "Game is over." << endl;

    return 0;
}