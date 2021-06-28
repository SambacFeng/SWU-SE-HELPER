#ifndef COMPCONT_H
#define COMPCONT_H

#include "listTemp.h"

#define NUM_EMPLOYEE 10000
#define MAX_SALARY 10000

class Company
{
private:
	int bestPaid;
	ListTemp<int> container;

public:
	void inputSalary(); //when input employee from keyboard, store the input data in the container for later use;
	
	//please implement the following two methods
	void findBestPaid(); //go through the container to find the best paid employee
	void findBestPaidReverse(); //go through the container in the reverse order to find the best paid employee

	void printBestPaid() const;
}; 

#endif