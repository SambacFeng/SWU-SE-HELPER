
#include "company.h"
#include <iostream>
using namespace std;

void Company::inputEmployee()
{
	Employee employee;

	employee.input();

	while (employee.getName() != "*")
	{
		container.AddHead(employee); // add to the container
		employee.input();
	}
}

void Company::findBestPaid()
{
	bestPaid = Employee();
	ListTemp<Employee>::Iterator itr = container.Begin();
	while (!(itr == container.End()))
	{
		if (*itr > bestPaid)
			bestPaid = *itr;
		itr++;
	}
}

//please implement this
void Company::findBestPaidReverse()
{
	bestPaid = Employee();
	ListTemp<Employee>::Iterator itr = container.End();
	while (!(itr == container.Begin()))
	{
		itr--;
		if (*itr > bestPaid)
			bestPaid = *itr;
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid
