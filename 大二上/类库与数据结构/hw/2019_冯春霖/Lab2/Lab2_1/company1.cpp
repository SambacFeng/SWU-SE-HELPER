
#include <iostream>
#include "company1.h"
#include "employee1.h"

//comment: ctrl+k ctrl+c
//uncomment: ctrl+k ctrl+u

Company::Company()
{
	empNum = 0;
}//default constructor

void Company::storeEmp()
{
	Employee tmpEmp;
	tmpEmp.input();

	while (tmpEmp.getName() != "*")
	{
		if (empNum >= 5)
		{
			cout << "No more employee can be stored!" << endl;
			break;
		}

		else
		{
			empArray[empNum] = tmpEmp;
			empNum++;
			tmpEmp.input();
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

