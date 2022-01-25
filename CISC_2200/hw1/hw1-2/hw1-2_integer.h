/*homework1-problem2_integer.h
  author: Siyi He 
  created on 2021-9-16 */
#include <iostream>
using namespace std;
#ifndef INTEGER_H
#define INTEGER_H

class integer
{
  public:
    integer(); // default constructor
    integer(int dig); //constructor 

    friend istream& operator>>(istream& input, integer& Aint); //input() >>
    friend ostream& operator<<(ostream& output, const integer& Aint);//output() <<
    integer operator+(const integer int2);//add() +
    integer operator++(); //increment() ++ (prefix)
    integer operator++(int i); //increment ++ (postfix)
    integer operator-(); //decrement() - (prefix)
    integer operator *(const integer int2); //multiply() *
    integer operator /(const integer int2);//divide() /
    bool operator == (const integer int2); //isEqualTo() ==
    bool operator != (const integer int2); //isNotEqualTo() !=
    bool operator >= (const integer int2); //isGreaterThanorEqualTo() >=
    bool operator <= (const integer int2); //isLessThanorEqualTo() <=
    bool iszero();//isZero(): check whether the integer is zero

  private:
    int digit;
};

#endif