// Siyi He
// Oct. 25, 2020
//R02- hw#6 Holy digits Batman!  

#include <iostream>
using namespace std;

int main()
{
    //varibles
    int digit1, digit2, digit3, digit4;


    //processing 
    for (digit1 = 1; digit1 <= 7; digit1 = digit1 +2)
    {
        //init 
        digit2 = 0;
        do
        {
            digit2 = digit2 + 1;
            digit4 = digit2 * 3;
            digit3 = 27 - digit1 - digit2 - digit4;

            if (digit3 >= 0 && digit3 <= 9)
            {
                break;
            }
            
        } while (digit2 < 3);

        if (digit1 != digit2 && digit1 != digit3 && digit1 != digit4 && digit2 != digit3 && digit3 != digit4 && digit3 >= 0 && digit3 <= 9)
        {
            cout << "I found the address!" << endl;

            break;
        }
    }

    //output
    cout << "The address is " << digit4 << digit3 << digit2 << digit1 << endl;
   
    return 0;
}