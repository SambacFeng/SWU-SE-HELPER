
#include "company.h"
#include <iostream>
using namespace std;

void Company::inputEmployee()
{
	Employee employee;
	employee.input();

	while (employee.getName() != "*")
	{
//		container.AddHead(employee); // add to the container
		container.AddLast(employee);
		employee.input();
	}
}

void Company::findBestPaid()
{
	if (container.getLength() == 0)
		cout << "No employee exists!" << endl;

	else
	{
		bestPaid = container.Access(1);
		for (int i = 1; i < container.getLength(); i++)
		{
			if (container.Access(i) > bestPaid) // overloading >
				bestPaid = container.Access(i); //overloading =
		}
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay)  ";
	bestPaid.output();
} // printBestPaid

void Company::printLength() const
{
	cout << "There are " << container.getLength() << " employees!" << endl;
}