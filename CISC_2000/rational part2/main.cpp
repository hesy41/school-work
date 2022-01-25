#include <iostream>
#include <string>
#include "rational.h"
#include "rational.cpp"
using namespace std;

int main()
{
	char oper;
	// TODO: declare rational objects for result and operand.
	rational result, op1;
	cout << "Enter op1 (in the format of p/q): ";
	// TODO: Use your input function to read the first operand into result.
	cin >>result;
	//Test rational class member function 
	do {
		cout << "\nEnter operator [+, -, /, *, =, ?(==), <(less), >(greater), c(lear), a(ccessors), q(uit)]: ";
		// TODO: Read the operator into oper
		cin  >> oper;
		// TODO: Change the pseodocode below to test oper for binary operators
		if (oper== '+'|| oper == '-' || oper =='*' || oper == '/'|| oper == '?' || oper == '<' || oper == '>') 
		{
			cout << "\nEnter op2 (in the format of p/q): ";
			cin  >> op1;
		}
		
		// ToDo: Implement a switch or multiway if statement with one case for each option above where
		// '+','*','/','-' inputs a rational op1 and calculates result.oper(result,op1)
		// '=' outputs the current result,
		// 'c' to clear current result, use input function to read first operand into result,
		// 'a' to test accessors, 'q' to quit.

		switch (oper)
		{
			case '+':
				result = result+op1;
				break;

			case '-':
				result = result-op1;
				break;

			case '*':
				result = result*op1;
				break;

			case '/':
				result = result/op1;
				break;

			case '=':
				cout << "result = " << result;
				break;

			case '?':
				cout << ((result == op1)? "Correct! Good job!" : "Oh no! Good try!") << endl;
				break;

			case '<':
				cout << ((result < op1)? "True, great!" : "False, try again!") << endl;
				break;

			case '>':
				cout << ((result > op1)? "True, great!" : "False, try again!") << endl;
				break;

			case 'c':
			{
				cout << "\nEnter op1 (in the format of p/q): ";
				cin >> result;
				break;
			}

			case 'a':
			{
				cout << "\nresult's numerator is: " << result.getNumerator()<< endl;
				cout << "result's denominator is: " << result.getDenominator()<< endl;
				break;
			}

			case 'q':
				break;
		}

		// Fixes cin if the last rational was invalid
  		if (cin.fail()) 
		{
    		cin.clear(); cin.ignore();
  		} 
	} while (oper != 'q');

	return 0;
}