//#pragma once
#include <iostream>
#include "Employee.h"

#ifndef _COMMISSION_H
#define _COMMISSION_H

class CommissionEmployee : public Employee
{
public:
	// ToDo: declare default constructor for CommissionEmployee
	CommissionEmployee ();

	// ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
	CommissionEmployee (string the_name, string the_ssn, double the_sales, double the_commissionPercent );

	// ToDo: declare Accessor/Mutator functions
	double get_sales() const;
	double get_commissionPercent () const;
	void set_sales (double new_sales);
	void set_commissionPrecent (double new_commission);

	// ToDo: declare vitual functions to override
	double get_net_pay() const override;
    void print_check( ) const override;
	istream& promptInput(istream& in, ostream& out) override;

private:
	// ToDo: declare a sales, commission percent member
	double sales;
	double commissionPercent;
};
#endif // _COMMISSION_H

