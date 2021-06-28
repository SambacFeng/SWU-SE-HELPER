
#include "company.h"
#include <iostream>
using namespace std;

void Company::inputEmployee()
{
	Employee employee;

	employee.input();

	while (employee.getName() != "*")
	{
		container.Add(employee); // add to the container
		employee.input();
	}
}

//please implement this
void Company::findBestPaid()
{
	ContTemp<Employee>::Iterator itr(container.Begin());
	bestPaid = *itr;
	while (true)
	{
		if (*itr > bestPaid)
			bestPaid = *itr;
		itr++;
		if (itr == container.End())
			break;
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid