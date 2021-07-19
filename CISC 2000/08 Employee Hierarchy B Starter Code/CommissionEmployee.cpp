#include "CommissionEmployee.h"
#include <iostream>
#include <string>
using namespace std;

// ToDo: implement the default constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(): Employee(), sales(0.0), commissionPercent(0.0)
{
	//empty
}

// ToDo: implement the constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(string the_name, string the_SSN, double the_sales, double the_commission)
	: Employee(the_name,the_SSN),sales(the_sales),commissionPercent(the_commission) 
{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n"; 
}

// ToDo: implement accessor/mutators
double CommissionEmployee::get_sales() const
{
	return sales;
}

double CommissionEmployee::get_commissionPercent () const
{
	return commissionPercent;
}

void CommissionEmployee::set_sales (double new_sales)
{
	sales=new_sales;
}

void CommissionEmployee::set_commissionPrecent (double new_commission)
{
	commissionPercent= new_commission;
}

// ToDo: implement virtual get_net_pay function
// Hint: compensation is commission/100 * sales
double CommissionEmployee::get_net_pay() const
{
	return commissionPercent/100 * sales;
}


// ToDo: implement the virtual print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void CommissionEmployee::print_check() const
{
	Employee::print_check();
	cout << "Commission Employee. " << endl;
	cout << "Gross sales: " << sales << " Commission: " << commissionPercent 
		<< " Pay: " << get_net_pay() <<endl;
	cout << "_________________________________________________\n";
	//cout << "CommissionEmployee::print_check() not implemented" << endl;
}

// ToDo: implement the virtual promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream& CommissionEmployee::promptInput(istream& in, ostream& out)
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
	Employee::promptInput(in,out);


	// ToDo: read the sales and commission.
	out <<"Enter sales and commission: ";
	in  >> sales >> commissionPercent;

}


