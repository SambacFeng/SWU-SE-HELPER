
#include "employee2.h"

#include <iostream>

Employee2::Employee2()
{
	month = 0;
	monthlySalary = 0;
}

void Employee2::input()
{
	cout << "please enter a name, worked month and monthly salary:";
	cin >> name >> month >> monthlySalary;
	grossPay = month * monthlySalary;
	//please implement this
}