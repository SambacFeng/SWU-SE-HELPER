#include <iostream>
#include "employee1.h"

using namespace std;

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
	cout << "name: " << name << "; gross pay: " << grossPay << endl;
} // output


string Employee::getName() const
{
	return name;
}


void Employee::operator=(const Employee& otherEmployee)
{
	//please implement this operator overloading
}

bool Employee::operator>(const Employee& otherEmployee) const
{
	//please implement this operator overloading
}

