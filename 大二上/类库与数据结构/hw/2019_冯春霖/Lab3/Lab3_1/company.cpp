
#include "company.h"
#include <iostream>
using namespace std;

void Company::inputEmployee()
{
	Employee employee;

	employee.input();

	while (employee.getName() != "*")
	{
		//container.AddHead(employee); // add to the container
		container.AddTail(employee);
		employee.input();
	}
}

void Company::findBestPaid()
{
	//to be implemented in the next lab class
}

void Company::printBestPaid() const
{
	cout << "he best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid

void Company::printLength() const
{
	cout << "There are " << container.getLength() << " employees!" << endl;
}