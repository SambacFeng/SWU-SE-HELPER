#include <iostream>
using namespace std;

#include "company1.h"

Company::Company()
{
	bestPaid = Employee();
}//default constructor

void Company::findBestPaid()
{
	//please implement this method using the overloaded operator > and = for the Employee class
} // findBestPaid


void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay:" << endl;
	bestPaid.output();
} // printBestPaid

