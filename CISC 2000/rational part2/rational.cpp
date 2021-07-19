#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include "rational.h"
using namespace std;

//set function 
void rational::set(int a_numerator, int a_denominator)
{
  numerator=a_numerator;
  denominator=a_denominator;
}

/*member function: input
  take user input as classes rational*/

/* istream & operator >> (istream & input, rational & r)
{
  char c;
  input >> r.numerator >> c >> r.denominator;
  return input; 
} */

////failbit version of input 
istream & operator >> (istream & input, rational & r)
{
  string s;
  regex re("(-?[0-9]+)(/)([0-9]+)");
  regex ree("(-?[0-9]+)");
  smatch match;

  input >> s;

  if (regex_match(s,match,re))
  {
    int num = stoi(match.str(1));
    int den = stoi(match.str(3));
    r.set(num,den);
  }
  else if (regex_match(s,match,ree))
  {
    int num = stoi(match.str(1)); 
    int den = 1;
    r.set(num,den);
  }
  
  else 
  {
    cout << "Invalid rational format!" << endl;
    input.setstate(ios::failbit);
  }
  return input; 
}

/*member function: output 	
  output the target rational*/
ostream & operator << (ostream &output, const rational &r)
{
  output<< r.numerator << "/" << r.denominator;
  return output;
}

/*member function: getNumerator
  get the numerator from private class and return*/
int rational::getNumerator()
{
	return numerator;
}

/*member function: getDenomiator
  get the denominator from private class and return*/
int rational::getDenominator()
{
	return denominator;
}

/*member function: add overload 
  take two rationals and add them together (r1+r2)
  return the rational sum*/
rational operator +(const rational& r1, const rational& r2)
{
  rational sum;
	sum.numerator= r1.numerator * r2.denominator + r2.numerator*r1.denominator;
	sum.denominator = r1.denominator * r2.denominator;
  sum.simplify();
  return sum;
}

/*member function: subract overload 
  take two rationals and subract the second one from the first one (r1-r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
rational operator -(const rational& r1, const rational& r2)
{
  rational difference;
	difference.numerator= r1.numerator * r2.denominator - r2.numerator*r1.denominator;
	difference.denominator = r1.denominator * r2.denominator;
  difference.simplify();
  return difference;
}

/*member function: multiply 
  take two rationals and multiply them together (r1*r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
rational operator *(const rational& r1, const rational& r2)
{
  rational product;
	product.numerator=r1.numerator * r2.numerator;
	product.denominator = r1.denominator * r2.denominator;
  product.simplify();
  return product;
}

/*member function: divide
  take two rationals and do the calculation (r1/r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
rational operator /(const rational& r1, const rational& r2)
{
  rational quotient;
	quotient.numerator=r1.numerator * r2.denominator;
	quotient.denominator=r2.numerator * r1.denominator;
  quotient.simplify();
  return quotient;
}

// TODO: Default constructor sets numerator to 0 and denominator to 1
/*default constructor: 
  sets numerator to 0 and denominator to 1*/
rational::rational(): numerator(0), denominator(1){

}

//extra credit parts: use parameter to initialize the rational 
rational::rational(int num): numerator(num), denominator(1){
	
}

rational::rational(int num, int den): numerator(num), denominator(den){
	if (den == 0)
	  denominator=1;
}

//opertor ==
//compare two rationals r1, r2 (precon: r1 and r2 that need to be compared)
//return true if the two rationals equal
bool operator == (const rational& r1, const rational& r2)
{
  return (r1.numerator * r2.denominator == r1.denominator * r2.numerator);
}

//opertor <
//compare two rationals r1, r2 (precon: r1 and r2 that need to be compared)
//return true if r1<r2
bool operator < (const rational& r1, const rational& r2)
{
  return (r1.numerator * r2.denominator < r1.denominator * r2.numerator);
} 

//opertor >
//compare two rationals r1, r2 (precon: r1 and r2 that need to be compared)
//return true if r1>r2
bool operator > (const rational& r1, const rational& r2)
{
  return (r1.numerator * r2.denominator > r1.denominator * r2.numerator);
}

//gcd function 
//precon: two ints
//return the greatest common denominator
int rational::gcd (int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

//simplify function 
//sets the invoking object to be a simplified rational
void rational::simplify()
{
  int gcd = rational::gcd(numerator,denominator);
  numerator=numerator/gcd;
  denominator=denominator/gcd;
}