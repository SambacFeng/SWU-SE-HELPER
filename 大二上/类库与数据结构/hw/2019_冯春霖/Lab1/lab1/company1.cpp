
#include <iostream>
#include "company1.h"
#include "employee1.h"

//comment: ctrl+k ctrl+c
//uncomment: ctrl+k ctrl+u

Company::Company()
{
	bestPaid = Employee();
}//default constructor

void Company::findBestPaid()
{
   Employee employee;

   employee.input();

   while (employee.getName() != "*")
   {
      if (employee.compare(bestPaid))
         bestPaid.copy(employee);
      employee.input();
   } // while
} // findBestPaid


void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) ";
	bestPaid.output();
} // printBestPaid

