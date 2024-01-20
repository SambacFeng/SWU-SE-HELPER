#include <iostream>
using namespace std;

#include "company.h"

void Company::inputEmployee()
{
	Employee newEmployee;
	newEmployee.input();

	while (newEmployee.getName() != "*")
	{
		empContainer.addHead(newEmployee);
		newEmployee.input();
	}	
}

void Company::findBestPaid()
{
	doubleListTemp<Employee>::Iterator itr;  
	
	bestPaid = *empContainer.Begin();  
    for (itr = empContainer.Begin(); !(itr == empContainer.End()); itr++)
    {
		if (*itr > bestPaid){
			bestPaid = *itr;
		}
	}
}

void Company::findBestPaidReverse()
{
	doubleListTemp<Employee>::Iterator reverse_itr;

	bestPaid = *empContainer.reverse_Begin();
	for (reverse_itr = empContainer.reverse_Begin(); 
		!(reverse_itr == empContainer.reverse_End()); 
		reverse_itr--)
	{
		if (*reverse_itr > bestPaid) {
			bestPaid = *reverse_itr;
		}
	}

}

void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay: " << endl;
	bestPaid.output();
} // printBestPaid
