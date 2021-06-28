#ifndef COMPCONT_H
#define COMPCONT_H

#include "employee.h"
#include "empCont.h"

class CompCont
{
private:
	Employee bestPaid;
	EmpCont container;

public:
	void inputEmployee(); //when input employee from keyboard, store the input data in the container for later use;
	void findBestPaid(); //go through the container to find the best paid employee
	void printBestPaid() const;

	//implement the following methods
	void removeEmployee();
}; 

#endif