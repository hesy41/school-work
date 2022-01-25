//Siyi He
//CSII 21Spring - lab alternitive R01
//Practice Exercise - power function

#include <iostream>
using namespace std;

// TODO: Write the power function
//prototype 
int power( int number, int pow);

int main()
{
   int number, pow;
   cout << "Enter a number ";
   cin >> number;
   cout << "Enter a power ";
   cin >> pow;
   cout << "Result is " << power(number, pow) << endl;
   return 0;
}

//function def
int power( int num, int po)
{
   int result, i;
   result = 1;

   for (i=0; i< po; i++)
   {
      result = result * num;
   }

   return result;
}
 
