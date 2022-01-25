//Siyi He
//Oct. 26, 2020
//R02- lab#6

#include <iostream>
using namespace std;

//prototype 
char translator(char);

int main()
{
    //varible 
    char answer, number, num;
    int i, length;
    string phoneNumber, newPhoneNumber;

    //processing
    do
    {
        //init
        newPhoneNumber = "";

        //input
        cout << "Enter a string : ";
        cin  >> phoneNumber;
        //getline (cin , phoneNumber);

        //processing
        length = phoneNumber.length();

        for (i = 0; i < length; i ++)
        {
            number = phoneNumber.at(i);
            num = translator(number);
            std::string newNumber;
            newNumber += num; // convert char into string
            newPhoneNumber += newNumber; 
        }

        //out put
        cout << newPhoneNumber << endl;
        cout << endl;

        //ask for another phone 
        cout << "Want to process another phone? y=yes, n=no : ";
        cin  >> answer;
        cout << endl;
    } while (answer == 'y');

    //final wishes
    cout << "Have a nice day!" << endl;
    
}

//function definition 
char translator (char number)
{
    if (number == 'a' || number == 'A' || number == 'b' || number == 'B' || number == 'c' || number == 'C')
        return number = '2';
    else if (number == 'd' || number == 'D' || number == 'e' || number == 'E' || number == 'f' || number == 'F')
        return number = '3';
    else if (number == 'g' || number == 'G' || number == 'h' || number == 'H' || number == 'i' || number == 'i')
        return number = '4';
    else if (number == 'j' || number == 'J' || number == 'k' || number == 'K' || number == 'l' || number == 'L')
        return number = '5';
    else if (number == 'm' || number == 'M' || number == 'n' || number == 'N' || number == 'o' || number == 'O')
        return number = '6';
    else if (number == 'p' || number == 'P' || number == 'q' || number == 'Q' || number == 'r' || number == 'R' || number == 's' || number == 'S')
        return number = '7';
    else if (number == 't' || number == 'T' || number == 'u' || number == 'U' || number == 'v' || number == 'V')
        return number = '8';
    else if (number == 'w' || number == 'W' || number == 'x' || number == 'X' || number == 'y' || number == 'Y' || number == 'z' || number == 'Z')
        return number = '9';
    else 
        return number;
}