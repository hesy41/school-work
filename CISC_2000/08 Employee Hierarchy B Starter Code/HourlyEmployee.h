//DISPLAY 15.3 Interface for the Derived Class HourlyEmployee
//This is the header file hourlyemployee.h. 
//This is the interface for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;


class HourlyEmployee : public Employee 
{
    public:
		// Constructors
        HourlyEmployee( );
        HourlyEmployee(string the_name, string the_ssn,
                           double the_wage_rate, double the_hours);

		// Accessors
        double get_rate( ) const;
        double get_hours( ) const;

		// Mutators
        void set_rate(double new_wage_rate);
        void set_hours(double hours_worked);

		// Virtual functions
		double get_net_pay() const override;
        void print_check( ) const override;
		istream& promptInput(istream& in, ostream& out) override;

    private:
        double wage_rate; 
        double hours;
};


#endif //HOURLYMPLOYEE_H
