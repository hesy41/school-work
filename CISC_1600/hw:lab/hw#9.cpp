//Siyi He
//Nov.20, 2020
//R02- hw#9 coins

#include <iostream>
using namespace std;

//prototype
void computeCoins (int, int&, int&);

int main ()
{
    //varible 
    int change, coinValue, coinNumber, amountLeft, quarters, dimes, pennies;
    char answer;

    do
    {
        //init 
        coinNumber = 0;
        change = 0;
        amountLeft = 0;
        quarters = 0;
        dimes = 0;
        pennies = 0;

        //input
        cout << "How much is the change that need to deal with coins? " ;
        cin  >> change;

        //processing 
        amountLeft = change;

        if (amountLeft >= 25 && amountLeft <= 100)
        {
            //quarters check
            coinValue = 25;
            computeCoins (coinValue, coinNumber, amountLeft); 
            quarters = coinNumber;
        }

        if (amountLeft < 25 && amountLeft >= 10)
        {
            //dimes check 
            coinValue = 10;
            computeCoins (coinValue, coinNumber, amountLeft);  
            dimes = coinNumber;
        }
        if (amountLeft < 10 && amountLeft >= 0)
        {
            //pennies check
            coinValue = 1;
            computeCoins (coinValue, coinNumber, amountLeft); 
            pennies = coinNumber;
        }
        else 
        {   
            cout << " Plese enter a positive change amount that smaller than 100." << endl;
        }

        //output 
        cout << change << " cents can be given as " << endl;
        cout << quarters << " quarters(s) " << dimes << " dime(s) " << pennies << " penny (pennies)" << endl;
        cout << endl;

        cout << "Do you want another calculation?" ;
        cin  >> answer;

    }while (answer == 'y' || answer == 'Y');

    return 0;
}

//function definition 
void computeCoins (int value, int& num, int& left)
{
    num = left / value;
    left = left % value;
}