/*homework1-problem2-main.cpp
  author: Siyi He 
  created on 2021-9-16 
  bug detcted: I need to include hw1-2_integer.cpp to make main compile with integer.cpp*/
#include <iostream>
#include "hw1-2_integer.h"
#include "hw1-2_integer.cpp"
using namespace std;

int main()
{
  integer int1, int2;

  cout << "Create your first integer: ";
  cin  >> int1;
  cout << "Create your second integer: ";
  cin  >> int2;
  cout << "The sum of these two integer is: " <<int1 + int2<< endl;
  cout << "We increse the first integer by 1: " <<int1++<< endl; 
  cout << "We decrease the second integer by 1: " <<-int2<< endl; 
  if (int1 == int2)
  {
    cout << "int1 == int2" << endl;
  }
  if (int1 != int2)
  {
   cout << "int1 != int2" << endl; 
  }
  if(int1 >= int2)
  {
    cout << "int1 is greater than or equal to int2!" << endl;
  }
  if(int1 <= int2)
  {
    cout << "int1 is less than or equal to int2!" << endl;
  }
  if (int1.iszero())
    cout << "int1 equals to 0." << endl;
  else if (int2.iszero())
    cout << "int2 equals to 0." << endl;
  else 
    cout << "Neither int1 nor int2 equals to zero." << endl;

  return 0;
}