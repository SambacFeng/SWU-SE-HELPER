
#include "company.h"
#include <iostream>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime> // Header file needed to use time
using namespace std;

void Company::inputSalary()
{
	//set the seed for random number generation	
	srand((unsigned int)time(0));

	for(int i=0; i < NUM_EMPLOYEE; i++)
	{
		int rand_number = rand() % MAX_SALARY;
		container.AddHead(rand_number); // add to the container
	}
}

//please implement this
void Company::findBestPaid()
{
	bestPaid = 0;
	ListTemp<int>::Iterator itr = container.Begin();
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
	bestPaid = 0;
	ListTemp<int>::Iterator itr = container.End();
	while (!(itr == container.Begin()))
	{
		itr--;
		if (*itr > bestPaid)
			bestPaid = *itr;
	}
}

void Company::printBestPaid() const
{
	cout << "The salary of the best-paid employee is: " << bestPaid << endl;
} // printBestPaid
