#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>
using namespace std;

int gcd (int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main()
{
   string s;
   regex re("([0-9]*)(/)([0-9]*)");
   smatch match;

   cin >> s;

  if (regex_search(s,match,re))
  {
    int num = stoi(match.str(1));
    int den = stoi(match.str(3));
    cout << num << "/" << den << endl;
  }
  else 
  {
    cout << "Invalid rational format!" << endl;
    s.setstate(ios::failbit);
  }
}

