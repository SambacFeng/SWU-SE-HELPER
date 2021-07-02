//#include "pch.h"
#include <iostream>
#include "company1.h"
#include "employee1.h"

//comment: ctrl+k ctrl+c
//uncomment: ctrl+k ctrl+u

Company::Company()
{
	bestPaid = Employee();
	empNum = 0;
}//default constructor

void Company::storeEmp()
{
	Employee tmpEmp; //temparory variable
	tmpEmp.input(); //input the information for the first employee

	while (tmpEmp.getName() != "*")
	{
		if (empNum >= 5)
		{
			cout << "No more employee information can be stored!" << endl;
			break;
		}

		else
		{
			empArray[empNum] = tmpEmp; //store
			empNum++; //update the number of employee
			tmpEmp.input(); //next input
		}
	} // while
}

void Company::findBestPaid()
{
	if (empNum == 0)
		cout << "No employee exists!" << endl;
	else
	{
		bestPaid = empArray[0];
		for (int i = 1; i < empNum; i++)
		{
			if (empArray[i] > bestPaid)
				bestPaid = empArray[i];
		}
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) ";
	bestPaid.output();
} // printBestPaid

