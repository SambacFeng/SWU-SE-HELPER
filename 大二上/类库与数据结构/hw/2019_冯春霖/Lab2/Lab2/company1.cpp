
#include <iostream>
#include "company1.h"
#include "employee1.h"

//comment: ctrl+k ctrl+c
//uncomment: ctrl+k ctrl+u

Company::Company()
{
}//default constructor

void Company::findBestPaid()
{
   Employee employee;

   employee.input();

   while (employee.getName() != "*")
   {
	   //if (employee.compare(bestPaid))
		  // //please use overloaded operator >, instead of compare

		  // //bestPaid.copy(employee);
		  // bestPaid = employee;
	   if (employee > bestPaid)
		   bestPaid = employee;
      employee.input();
   } // while
} // findBestPaid


void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) ";
	bestPaid.output();
} // printBestPaid

