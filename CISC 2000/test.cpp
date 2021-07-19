#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int gcd (int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main()
{
    int a=6;
    int b=3;

    cout << gcd(a,b) << endl;

    return 0;
}