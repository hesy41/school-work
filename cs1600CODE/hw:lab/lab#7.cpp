//Siyi He
//Nov. 3, 2020
//R02-lab#7 check PassWord

#include <iostream>
using namespace std;

//prototype
bool tenCharacter (string);
bool upperCaseLetter (string);
bool oneDigit (string);
bool specialCharacter (string);

//main function 
int main()
{
    //varible 
    string password;

    //input
    cout << "Enter a password  :  ";
    cin  >> password;
    cout << endl;

    //check 
    if (tenCharacter (password) == true)
    {
        if (upperCaseLetter (password) == true)
        {
            if (oneDigit (password) == true)
            {
                if (specialCharacter (password) == true)
                {
                    cout << "Valid password! " << endl;
                }
                else 
                    cout << "Invalid Password!" << endl;
            }
            else 
                cout << "Invalid Password!" << endl;
        }
        else 
            cout << "Invalid Password!" << endl;
    }
    else 
        cout << "Invalid Password!" << endl;

    cout << endl;

    return 0;
}

//function definition 
bool tenCharacter (string pw)
{
    //varible 
    int length;

    length = pw.length();
     
    if (length >= 10)
        return true;
    else
        return false;
}

bool upperCaseLetter (string pw)
{
   //varible 
    int length, i;
    char letter;

    length = pw.length();

    for (i = 0; i < length; i ++)
        {
            letter = pw.at(i);

            if (letter == 'Q' || letter == 'W' || letter == 'E' || letter ==  'R' || letter == 'T' || letter == 'Y' || letter == 'U' 
                || letter == 'I' || letter == 'O' || letter == 'P' || letter == 'A' || letter == 'S' || letter == 'D' || letter == 'F'
                || letter == 'G' || letter == 'H' || letter == 'J' || letter == 'K' || letter == 'L' || letter == 'Z' || letter == 'X'
                || letter == 'C' || letter == 'V' || letter == 'B' || letter == 'N' || letter == 'M')
            {
                return true;
                break;
            }   

        }
    return false;
}

bool oneDigit (string pw)
{
    //varible 
    int length, i;
    char letter;

    length = pw.length();

    for (i = 0; i < length; i ++)
        {
            letter = pw.at(i);

            if (letter == '1' || letter == '2' || letter == '3' || letter == '4' || letter == '5' || letter == '6' || letter == '7'
                || letter == '8' || letter == '9' || letter == '0')
            {
                return true;
                break;
            }
        }
    return false;
}

bool specialCharacter (string pw)
{
    //varible 
    int length, i;
    char letter;

    length = pw.length();

    for (i = 0; i < length; i ++)
        {
            letter = pw.at(i);

            if (letter == '!' || letter == '@' || letter == '#' || letter == '$' || letter == '%'|| letter == '^' || letter == '&'
                || letter == '*' || letter == '(' || letter == ')')
            {
                return true;
                break;
            }
        }
    return false; 
}
