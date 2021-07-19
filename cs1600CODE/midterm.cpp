//Siyi He
//Oct. 20, 2020
//R02 - midterm coding

#include <iostream>
using namespace std;

int main()
{
    //varible 
    int MufflersNum, BrakesNum, AlternatorsNum, orderNum; 
    float MufflersPrice, BrakesPrice, AlternatorsPrice, tax, discount, totalPrice, finalPrice, grandTotal;
    char answer;

    //init 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    discount = 50;
    orderNum = 1;
    grandTotal = 0;

    do 
    {
        //Welcome 
        cout << "     Welcome to Siyi’s Auto Parts! " << endl;
        cout << endl;

        //input
        cout << "     Enter the number of brakes you want to buy? : ";
        cin  >> BrakesNum;
        cout << "   Enter the number of mufflers you want to buy? : ";
        cin  >> MufflersNum;
        cout << "Enter the number of alternators you want to buy? : ";
        cin  >> AlternatorsNum;

        cout << "--------- Siyi's Auto Parts ----------" << endl;
        cout << endl;

        //processing 
        BrakesPrice = BrakesNum * 200.50;
        MufflersPrice = MufflersNum * 100.50;
        AlternatorsPrice = AlternatorsNum * 300.50;
        totalPrice = BrakesPrice + MufflersPrice + AlternatorsPrice;
        tax = totalPrice * 0.1;
        finalPrice = totalPrice + tax;

        //output
        cout << "Part          Quantity          Price" << endl;
        cout << "--------------------------------------"<< endl;
        cout << "Mufflers      " << MufflersNum   << "                 $" << MufflersPrice    << endl;
        cout << "Brakes        " << BrakesNum     << "                 $" << BrakesPrice      << endl;
        cout << "Alternators   " << AlternatorsNum<< "                 $" << AlternatorsPrice << endl; 
        cout << endl;
        cout << "    Sub Total : $" << totalPrice << endl;
        cout << "          Tax : $" << tax << endl;
        cout << "   Total Sale : $" << finalPrice << endl;
        
        //discount check 
        if (finalPrice > 700.00)
        {
            finalPrice = finalPrice - discount;

            //output
            cout << "      Discount : $" << discount << endl;
            cout << "Adj Total Sale : $" << finalPrice << endl;
        }   

        //ask for another order
        cout << "Do you want another auto parts order request? y=yes n=no : ";
        cin  >> answer;
        cout << endl;

        //grandtotal processing 
        if (answer == 'y')
        {
            orderNum++;
        }
        grandTotal= grandTotal + finalPrice;

    } while ( answer == 'y');

    //grandtoal output
    cout << endl;
    cout << "Grand total for " << orderNum << "order(s) was $" << grandTotal << endl;
    cout << "Have a nice day!" << endl;

    return 0;
}