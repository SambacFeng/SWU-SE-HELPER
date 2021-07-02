//#include "pch.h"
#include "employee2.h"

#include <iostream>

Employee2::Employee2()
{
	month = 0;
	monthlySalary = 0;
}

void Employee2::input()
{
	cout << "Please enter a name, a number oof working months, and a monthly salary." << endl;
	cout << "To quit, enter * followed by any two numbers:" << endl;
	cin >> name >> month >> monthlySalary;
	grossPay = month * monthlySalary;
}