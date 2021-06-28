#ifndef COMPCONT_H
#define COMPCONT_H

#include "employee.h"
#include "listTemp.h"

class Company
{
private:
	Employee bestPaid;
	ListTemp<Employee> container;

public:
	void inputEmployee(); //when input employee from keyboard, store the input data in the container for later use;
	
	void findBestPaid(); //go through the container to find the best paid employee

	//please implement findbestpaid
	void findBestPaidReverse(); //go through the container in the reverse order to find the best paid employee

	void printBestPaid() const;
}; 

#endif