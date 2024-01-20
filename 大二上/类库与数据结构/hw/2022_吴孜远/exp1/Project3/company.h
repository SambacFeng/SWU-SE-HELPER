#ifndef COMPCONT_H
#define COMPCONT_H

#include "employee.h"
#include "listTemp.h"

class Company
{
private:
	Employee bestPaid;
	doubleListTemp<Employee> empContainer;

public:
	void inputEmployee(); //when input employee from keyboard, store the input data in the container for later use;
	void findBestPaid(); //go through the container to find the best paid employee
	void findBestPaidReverse(); //·´ÏòÕÒ³öbest paid employee
	void printBestPaid() const;
}; 

#endif