
#include "compCont.h"
#include <iostream>
using namespace std;

void CompCont::inputEmployee()
{
	Employee employee;

	employee.input();

	while (employee.getName() != "*")
	{
		container.Add(employee); // add to the container
		employee.input();
	}
}

void CompCont::findBestPaid()
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

void CompCont::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid

//implement the following method
void CompCont::removeEmployee()
{
	cout << "please input the number of employee you want to remove: ";
	int order;
	cin >> order;
	container.remove(order);
}