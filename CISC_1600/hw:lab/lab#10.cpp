//Siyi He
//Dec. 3, 2020
//R02-lab#10 Count occurrence of each letter in a string

#include <iostream>
using namespace std;

//varible  
int counts[25];
string aStr;

//phototype
void count(string aStr, int[]);
void printOutput (int[]);

int main ()
{
    //varible 
    int i;
    //init
    for (i=0; i<26; i++)
    {
        counts[i] = 0;
    }

    //input 
    cout << "Enter a string: ";
    getline (cin, aStr);

    //processing 
    count (aStr, counts);

    //output
    printOutput (counts);

    return 0;
}

//function definition
void count(string aStr, int c[])
{
    int length, i; /*varible*/
    char letter;

    length = aStr.length();

    for (i=0; i<length; i++)
    {
        letter = aStr.at(i);

        switch (letter)
        {
            case 'a':
            case 'A':
                c[0]++;
                break;

            case 'b':
            case 'B':
                c[1]++;
                break;

            case 'c':
            case 'C':
                c[2]++;
                break;

            case 'd':
            case 'D':
                c[3]++;
                break;

            case 'e':
            case 'E':
                c[4]++;
                break;

            case 'f':
            case 'F':
                c[5]++;
                break;

            case 'g':
            case 'G':
                c[6]++;
                break;

            case 'h':
            case 'H':
                c[7]++;
                break;

            case 'i':
            case 'I':
                c[8]++;
                break;

            case 'j':
            case 'J':
                c[9]++;
                break;

            case 'k':
            case 'K':
                c[10]++;
                break;

            case 'l':
            case 'L':
                c[11]++;
                break;
            
            case 'm':
            case 'M':
                c[12]++;
                break;

            case 'n':
            case 'N':
                c[13]++;
                break;

            case 'o':
            case 'O':
                c[14]++;
                break;

            case 'p':
            case 'P':
                c[15]++;
                break;

            case 'q':
            case 'Q':
                c[16]++;
                break;

            case 'r':
            case 'R':
                c[17]++;
                break;

            case 's':
            case 'S':
                c[18]++;
                break;

            case 't':
            case 'T':
                c[19]++;
                break;

            case 'u':
            case 'U':
                c[20]++;
                break;

            case 'v':
            case 'V':
                c[21]++;
                break;

            case 'w':
            case 'W':
                c[22]++;
                break;

            case 'x':
            case 'X':
                c[23]++;
                break;

            case 'y':
            case 'Y':
                c[24]++;
                break;

            case 'z':
            case 'Z':
                c[25]++;
                break;

            default:
                break;
        }
    }
} 

//function def
void printOutput (int c[])
{
    int i; //varible 
    char letter = 'a';

    for (i=0; i<25; i++)
    {
        if (c[i] != 0)
        {
            cout << letter << ": " << c[i] << " times" << endl;
        }
        letter ++;
    }
}