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
	void inputEmployeeHead(int total_num);
	void inputEmployeeTail(int total_num);
	void findBestPaid(); 
	void printBestPaid() const;
}; 

#endif