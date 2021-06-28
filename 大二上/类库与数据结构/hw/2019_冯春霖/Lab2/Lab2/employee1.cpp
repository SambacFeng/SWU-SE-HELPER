
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

void Employee::operator=(const Employee &otherEmployee)
{
	name = otherEmployee.name;
	grossPay = otherEmployee.grossPay;
}

bool Employee::compare(const Employee &otherEmployee) const
{
   return grossPay > otherEmployee.grossPay;
} // compare

bool Employee::operator > (const Employee& otherEmployee)
{
	return this->grossPay > otherEmployee.grossPay;
}

string Employee::getName() const
{
	return name;
}


