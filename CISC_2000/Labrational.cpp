#include <iostream>
#include <string>
#include <stdlib.h>

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

	/* TODO: define input to set the invoking object's value from user input */
	void input();

	/* TODO: define output to display invoking object's value in the standard output, in the form of numerator/denominator */
	void output() const;

	/* TODO: declare the accessor to return the invoking object's numerator */
	int getNumerator();
	
	/* TODO: declare the accessor to return the invoking object's denominator */
	int getDenominator();

	/* TODO: declare Add to set the invoking object to be the sum of op1 and op2, use const & parameters */
	void Add(const rational&, const rational&);

	/* TODO: declare Subtract to set the invoking object to the difference of op1 and op2, use const & parameters */
	void Subtract(const rational&, const rational&);

	/* TODO: declare Multiply to set the invoking object to the product of op1 and op2, use const & parameters */
	void Multiply(const rational&, const rational&);

	/* TODO: declare Divide to set the invoking object to the Quotient of op1 and op2, use const & parameters */
	void Divide(const rational&, const rational&);

private:
	/* TODO: declare data members for rational object */
	int numerator;
	int denominator;
};


int main()
{
	char oper;
	// TODO: declare rational objects for result and operand.
	rational result, op1;
	cout << "Enter op1 (in the format of p/q): ";
	// TODO: Use your input function to read the first operand into result.
	result.input();
	//Test rational class member function 
	do {
		cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), q(uit)]: ";
		// TODO: Read the operator into oper
		cin  >> oper;
		// TODO: Change the pseodocode below to test oper for binary operators
		if (oper== '+'|| oper == '-' || oper =='*' || oper == '/') 
		{
			cout << "\nEnter op2 (in the format of p/q): ";
			// TODO: Use your input function to read the operand into operand
			op1.input();
		}
		
		// ToDo: Implement a switch or multiway if statement with one case for each option above where
		// '+','*','/','-' inputs a rational op1 and calculates result.oper(result,op1)
		// '=' outputs the current result,
		// 'c' to clear current result, use input function to read first operand into result,
		// 'a' to test accessors, 'q' to quit.

		switch (oper)
		{
			case '+':
				result.Add(result,op1);
				break;

			case '-':
				result.Subtract(result,op1);
				break;

			case '*':
				result.Multiply(result,op1);
				break;

			case '/':
				result.Divide(result,op1);
				break;

			case '=':
				result.output();
				break;

			case 'c':
			{
				cout << "Enter op1 (in the format of p/q): ";
				result.input();
				break;
			}

			case 'a':
			{
				cout << "result's numerator is: " << result.getNumerator()<< endl;
				cout << "result's denominator is: " << result.getDenominator()<< endl;
				break;
			}

			case 'q':
				break;
		}

	} while (oper != 'q');
	return 0;
}


// TODO: Definitions of all member functions declared above
/*member function: input
  take user input as classes rational*/
void rational::input()
{
	char c;
	cin  >> numerator >> c >> denominator;
}

/*member function: output 	
  output the target rational*/
void rational::output() const
{
	cout << "result = " << numerator << "/" << denominator << endl;
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

/*member function: add
  take two rationals and add them together (r1+r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
void rational::Add(const rational& r1, const rational& r2)
{
	numerator= r1.numerator * r2.denominator + r2.numerator*r1.denominator;
	denominator = r1.denominator * r2.denominator;
}

/*member function: subract
  take two rationals and subract the second one from the first one (r1-r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
void rational::Subtract(const rational& r1, const rational& r2)
{
	numerator= r1.numerator * r2.denominator - r2.numerator*r1.denominator;
	denominator = r1.denominator * r2.denominator;
}

/*member function: multiply 
  take two rationals and multiply them together (r1*r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
void rational::Multiply(const rational& r1, const rational& r2)
{
	numerator=r1.numerator * r2.numerator;
	denominator = r1.denominator * r2.denominator;
}

/*member function: divide
  take two rationals and do the calculation (r1/r2)
  (no value return)result is stored by changing the first rational (invoking variable)*/
void rational::Divide(const rational& r1, const rational& r2)
{
	numerator=r1.numerator * r2.denominator;
	denominator=r2.numerator * r1.denominator;
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
