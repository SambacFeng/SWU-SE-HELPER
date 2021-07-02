//#include "pch.h"
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
	ListTemp<Employee>::Iterator curr = container.Begin();
	if (container.getLength() == 0)
		cout << "No employee exists!" << endl;
	else
	{
		bestPaid = *curr;
		for (int i = 0; i < container.getLength(); i++)
		{
			if (*curr > bestPaid) // overloading >
				bestPaid = *curr; //overloading =
			curr++;
		}
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) " ;
	bestPaid.output();
} // printBestPaid
