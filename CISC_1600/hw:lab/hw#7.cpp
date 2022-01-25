//Siyi He
//Oct. 31, 2020
//R02-hw#7 vending machine 

#include <iostream>
using namespace std;

//prototype 
float coinsTrans (char);
bool moneyCheck (float);
float check (float);

int main()
{
    //varible 
    char coinType;
    float totalMoney, change;

    //init 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint); 
    cout.precision(2);
    totalMoney = 0;

    //general announcement 
    cout << "Welcome to the vending machine. You need $3.50 to buy a deep-fried twinkie." << endl;
    cout << "We only take coins in denominations of a dollar, quarter, dime, or nickel." << endl;

    //processing 
    do 
    {
        //input
        cout << "Input your coin here, [D]ollar, [Q]uarter, D[I]me, or [N]ickel: ";
        cin  >> coinType;

        //calculating 
        totalMoney = totalMoney + coinsTrans (coinType);

    }while(moneyCheck (totalMoney)== true);

    //check calculation 
    change = check(totalMoney);

    //output
    cout << "You have input $" << totalMoney << "enough! There is your change: $" << change << "." << endl;

    return 0;
}

//function definition 
float coinsTrans (char coins)
{
    switch (coins)
    {
    case 'D':
        return 1;
        break;
    
    case 'Q':
        return 0.25;
        break;

    case 'I':
        return 0.1;
        break;

    case 'N':
        return 0.05;
        break;
    
    default:
        return 0;
        break;
    }
    
}

//function defintion 
bool moneyCheck (float money)
{
    if (money < 3.5)
        return true;
    else 
        return false;
}

//function definition
float check (float money)
{
    float check;
    check = money - 3.5;

    return check;
}