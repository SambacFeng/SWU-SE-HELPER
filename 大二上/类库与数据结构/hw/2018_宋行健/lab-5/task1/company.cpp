
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
	ListTemp<Employee>::Iterator itr = (container.End()--); //最后一位没有数据，所以这里要进行自减操作，否则第一次比较会报错

	while (!(itr == container.Begin()))
	{
		if (*itr > bestPaid)
			bestPaid = *itr;
		itr--;
	}
	if (*itr > bestPaid)
		bestPaid = *itr;
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) " << endl;
	bestPaid.output();
} // printBestPaid
