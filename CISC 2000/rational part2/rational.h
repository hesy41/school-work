#include <iostream>
#include <string>

#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;

class rational
{
public:
	/* TODO: default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
	rational();
	rational(int num); //for extra credit 
	rational(int num, int den); // for extra credit
	/*for extra credit: I understand that I should set the num=0 and den=1, but if I do this, all three
	constructors would be ambiguous, so I gived up setting num and den. Hope this could work.  */

    //set function 
    void set(int a_numerator, int a_denominator);

	//overloaded input function with operator >>
    //get the value as a rational type
    //Precondition: If in is a file input stream, then in has already been connected to a file
	friend istream & operator >> (istream &input, rational &r);

	//overloaded output function with operator <<
    //get the value as a rational type
    //Precondition: If out is a file input stream, then out has already been connected to a file
	friend ostream & operator << (ostream &output, const rational &r);


	/* TODO: declare the accessor to return the invoking object's numerator */
	int getNumerator();
	
	/* TODO: declare the accessor to return the invoking object's denominator */
	int getDenominator();

	//overload operator+
    // op1 + op2 is stored in a local rational object which is returned
    // @return a rational with the sum
	friend rational operator +(const rational&, const rational&);

	//overload operator minus (-)
    // op1 - op2 is stored in a local rational object which is returned
    // @return a rational with the sum
	friend rational operator -(const rational&, const rational&);

	//overload operator *
    // op1 * op2 is stored in a local rational object which is returned
    // @return a rational with the sum
	friend rational operator *(const rational&, const rational&);

	//overload operator/
    // op1 / op2 is stored in a local rational object which is returned
    // @return a rational with the sum
	friend rational operator /(const rational&, const rational&);

    //opertor ==
    //compare two rationals r1, r2 (precon: r1 and r2 that need to be compared)
    //return true if the two rationals equal
    friend bool operator == (const rational&, const rational&);

    //opertor <
    //compare two rationals r1, r2 (precon: r1 and r2 that need to be compared)
    //return true if r1<r2
    friend bool operator < (const rational&, const rational&);

    //opertor >
    //compare two rationals r1, r2 (precon: r1 and r2 that need to be compared)
    //return true if r1>r2
    friend bool operator > (const rational&, const rational&);

private:
	/* TODO: declare data members for rational object */
	int numerator;
	int denominator;

    //gcd function 
    //precon: two ints
    //return the greatest common denominator
    int gcd(int, int);

    //simplify function 
    //sets the invoking object to be a simplified rational
    void simplify();
};

#endif