/*homework1-problem2_integer.cpp
  author: Siyi He 
  created on 2021-9-16 */
#include <iostream>
#include "hw1-2_integer.h"
using namespace std;

//constructor 
integer::integer(): digit(0){ //defualt constructor 

}

integer::integer(int dig):digit(dig){ //constructor with one parameter

}

//iostream overriden
istream& operator>>(istream& input, integer& integ) //istream overriden
{
  input >> integ.digit; // store valus inputed from keyboard under "number" the class digit
  return input;
}

ostream& operator<<(ostream& output, const integer& integ)
{
    output << integ.digit;
    return output;
}

//operation overriden 
integer integer::operator+(const integer i)// add() +
{
  integer sum; //make sure that the addition will not change int1 or int 2
  sum.digit = (*this).digit + i.digit;
  return sum;
}

integer integer::operator++()//increment() ++ (prefix)
{
  (*this).digit++;
  return (*this);
}

integer integer::operator++(int i)//increment ++ (postfix)
{
  integer temp = *this;
  ++(*this);
  return *this;
}

integer integer::operator-()//decrement() - (prefix)
{
  (*this).digit--;
  return (*this);
}

integer integer::operator*(const integer int2)//multiply() *
{
  integer product;////make sure that the mutification will not change int1 or int 2
  product.digit=(*this).digit * int2.digit;
  return product;
}

integer integer::operator/(const integer int2)//divide() /
{
  integer quotient;
  if (int2.digit == 0)
  {
    cout << "Divison unsecessful: the divisor cannot be 0." << endl;
    return integer(404);
  }
  else 
  {
    quotient.digit=(*this).digit / int2.digit;
    cout << "the result is the integer portion of the quotient with the fractional part discarded." << endl;
    return quotient;
  }
}

bool integer::operator==(const integer int2)//isEqualTo() ==
{
  if ((*this).digit == int2.digit)
    return true;
  else
    return false;
}

bool integer::operator!=(const integer int2)//isNotEqualTo() !=
{
  if ((*this).digit != int2.digit)
    return true;
  else
    return false;
}

bool integer::operator>=(const integer int2)//isGreaterThanorEqualTo() >=
{
  if ((*this).digit >= int2.digit)
    return true;
  else
    return false;
}

bool integer::operator<=(const integer int2)//isLessThanorEqualTo() <=
{
  if ((*this).digit <= int2.digit)
    return true;
  else
    return false;
}

bool integer::iszero() //isZero(): check whether the integer is zero
{
  if ((*this).digit==0)
    return true;
  else
    return false;
}