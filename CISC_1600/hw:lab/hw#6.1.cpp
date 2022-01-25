//Siyi He
//Oct. 7, 2020
//R02- rewrite hw#6 find the batman 4 digits

#include <iostream>
using namespace std;

//prototype 
bool isNumberOdd (int);
bool sumIs27 (int);
bool allDifferent (int);
bool threeTimes (int);

int main()
{
    //varible 
    int n;

    //inout
    //no need for this program 

    //processing
    for ( n = 1000; n <= 9999; n++)
    {
        if (isNumberOdd (n) == true)
        {
            if (sumIs27 (n) == true)
            {
                if (allDifferent (n) == true)
                {
                    if (threeTimes (n) == true)
                    {
                        cout << n << endl;
                        cout << endl;
                    }
                }
            }
        }
    }
    
    //output
    cout << "Have a nice day!" << endl;

    return 0;
}

//function  definition 
bool isNumberOdd (int num) //check whether the number is odd
{
    if ((num % 2) == 1)
        return true;
    else 
        return false;
}

bool sumIs27 (int num) //check whether sum of 4 digits is 27
{
    //local varible 
    int n1, n2, n3, n4, temp;

    temp = num;
    n4   = temp % 10; //ones

    temp = temp / 10;
    n3   = temp % 10; //tens 

    temp = temp / 10;
    n2   = temp % 10; //hundreds 

    temp = temp / 10;
    n1   = temp % 10; //thousands

    if ((n1 + n2 +n3 + n4) == 27)
        return true;
    else
        return false;
}

bool allDifferent (int num) //check whether the digits are different from each other 
{
    //local varible 
    int n1, n2, n3, n4, temp;

    temp = num;
    n4   = temp % 10; //ones 

    temp = temp / 10;
    n3   = temp % 10; //tens

    temp = temp / 10;
    n2   = temp % 10; //hundreds

    temp = temp / 10;
    n1   = temp % 10; //thousands

    if (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4 )
        return true;
    else
        return false;
}

bool threeTimes (int num) // check whether thousands is three times the tens 
{
   //local varible 
    int n1, n2, n3, n4, temp;

    temp = num;
    n4   = temp % 10; //ones 

    temp = temp / 10;
    n3   = temp % 10; //tens

    temp = temp / 10;
    n2   = temp % 10; //hundreds

    temp = temp / 10;
    n1   = temp % 10; //thousands

    if (n1 == (n3 * 3)) 
        return true;
    else 
        return false;
}