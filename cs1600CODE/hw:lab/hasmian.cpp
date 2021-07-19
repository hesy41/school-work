#include <iostream>;
using namespace std;

int mian()
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
        cout << "Input your coin here, [D]ollar, [Q]uarter, D[I]me, or [N]ickel";
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