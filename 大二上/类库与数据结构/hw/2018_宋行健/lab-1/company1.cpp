//#include "pch.h"
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
   Employee temp;
   temp.input();

   while(temp.getName() != "*")
   {
//	  if(temp.compare(bestPaid))
//		  bestPaid.copy(temp);
	   if (temp > bestPaid)
		   bestPaid = temp;
      temp.input();
   }
} // findBestPaid



         
      





void Company::printBestPaid() const
{
	cout << "The best-paid employee (and gross pay) ";
	bestPaid.output();
} // printBestPaid

