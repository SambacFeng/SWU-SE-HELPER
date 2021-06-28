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
		container.Add(employee); // add to the container
		employee.input();
	}
}

void Company::findBestPaid()
{
	if (container.getLength() == 0)
		cout << "No employee exists!" << endl;

	else
	{
		bestPaid = container.Access(0);
		for (int i = 1; i < container.getLength(); i++)
		{
			if (container.Access(i) > bestPaid) // overloading >
				bestPaid = container.Access(i); //overloading =
		}
	}

}

void Company::printBestPaid() const
{
	cout << "he best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid

//implement the following method
void Company::removeEmployee()
{
	int i;
	cout << "\nPlease input the index (starting from 0) of the employee to be removed: ";
	cin >> i;
	container.Remove(i);
}