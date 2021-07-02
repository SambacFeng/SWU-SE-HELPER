#ifndef EMPLOYEE2
#define EMPLOYEE2

#include "employee1.h"

class Employee2:public Employee
{
private:
	int month;
	double monthlySalary;

public:
	Employee2();
	void input();
};


#endif