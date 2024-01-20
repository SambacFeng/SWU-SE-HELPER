#include <iostream>
using namespace std;

#include "company1.h"

Company::Company()
{
	bestPaid = Employee(); //copy assignment
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
	cout << "The best-paid employee and gross pay:" << endl;
	bestPaid.output();
} // printBestPaid

