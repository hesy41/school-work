//Siyi He
//Nov. 11, 2020
//R02- lab#8 find lowest # of accidents for a city region (N, S, E, W, C)

#include <iostream>
using namespace std;

//prototype 
int getNumAccidents (string);
void findLowest (int, int, int, int, int);

int main()
{
    //varible 
    int na, sa, ea, wa, ca;

    //input
    na = getNumAccidents ("North ");
    sa = getNumAccidents ("South ");
    ea = getNumAccidents ("East  ");
    wa = getNumAccidents ("West  ");
    ca = getNumAccidents ("Central");

    //processing
    findLowest (na, sa, ea, wa, ca);

    //output


    return 0;
}

//function definition 
void findLowest (int n, int s, int e, int w, int c)
{
    char min;
    int minN;

    if (n > s) //compare n and s 
    {
        min = 's';
        minN = s;
    }
    else
    {
       min = 'n';
        minN = n;
    }

    if (minN > e) //compare s and e
    {
        min = 'e';
        minN = e;
    }

    if (minN > w) // compare e and w
    {
        min = 'w';
        minN = w;
    }

    if (w > c) //compare w and c
    {
        min = 'c';
        minN = c;
    }
    
    //output
    switch (min)
    {
    case 'n': 
        cout << "The safest region is the north with " << n << " automobile accidents reported in that region during the last year." << endl;
        break;
    
    case 's':
        cout << "The safest region is the south with " << s << " automobile accidents reported in that region during the last year." << endl;
        break;

    case 'e':
        cout << "The safest region is the east with " << e << " automobile accidents reported in that region during the last year." << endl;
        break;
    
    case 'w':
        cout << "The safest region is the west with " << w << " automobile accidents reported in that region during the last year." << endl;
        break;

    case 'c':
        cout << "The safest region is the central with " << c << " automobile accidents reported in that region during the last year." << endl;
        break;

    default:
        break;
    }
}

//function definition 
int getNumAccidents (string r)
{
    //varible
    int temp;

    cout << "Enter the number of car accidents for the region " << r << " : " ;
    cin  >> temp;

    if (temp < 0)
    {
        cout << "Do not accept an accident number that is less than 0 (zero)." << endl;
        return 0;
    }

    return temp;
}