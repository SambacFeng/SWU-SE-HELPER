
#include <iostream>
#include "employee1.h"


Employee::Employee()
{
   name = "";
   grossPay = 0;
} // default constructor


void Employee::input()
{
	cout << "Please enter a name and gross pay; to quit, enter * followed by any number: ";
	cin >> name >> grossPay;
} // input


void Employee::output() const
{
	cout << "is: " << name << ",  $" << grossPay << endl;
} // output


void Employee::copy(const Employee &otherEmployee)
{
   name = otherEmployee.name;
   grossPay = otherEmployee.grossPay;
} // copy


bool Employee::compare(const Employee &otherEmployee) const
{
   return grossPay > otherEmployee.grossPay;
} // compare

string Employee::getName() const
{
	return name;
}


