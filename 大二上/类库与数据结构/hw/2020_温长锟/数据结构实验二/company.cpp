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

//please implement this
void Company::findBestPaid()
{
	bestPaid = Employee();
	ListTemp<Employee>::Iterator curr = container.Begin();
	while (!(curr == container.End()))
	{
		if (*curr > bestPaid)
			bestPaid = *curr;
		curr++;
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid
