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
	
	//please implement findbestpaid
	void findBestPaid(); //go through the container to find the best paid employee

	void printBestPaid() const;
}; 

#endif