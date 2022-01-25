/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the title (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start with the version from 
 *  SalariedEmployee
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator:public SalariedEmployee
{
  public:
	// ToDo: declare default constructor for Administrator
	Administrator();

	// ToDo: declare constructor for Administrator that takes a name, SSN, salary, title, bonus
	Administrator (string name, string SSN, double salary, string title, double bonus);

	// ToDo: declare Accessor/Mutator functions
	string get_title ();
	double get_bonus();
	void set_title(string new_title);
	void set_bonus(double new_bonus);

	// ToDo: declare vitual functions to override
	void print_check() const;                        // call SalariedEmployee::print_check()
    istream& promptInput(istream& in, ostream& out); // call SalariedEmployee::prompInput(in, out)
    double get_net_pay() const;                      // use salary + bonus;


  private: 
	// ToDo: declare a job title, bonus member
	string title;
	double bonus;

};

#endif
