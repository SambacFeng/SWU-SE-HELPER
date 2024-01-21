#include <iostream>
using namespace std;

#include "company.h"

void Company::inputEmployee()
{
	Employee newEmployee;
	newEmployee.input();

	while (newEmployee.getName() != "*")
	{
		empContainer.addHead(newEmployee);
		newEmployee.input();
	}

	
}

void Company::findBestPaid()
{
	ListTemp<Employee>::Iterator itr; //创建迭代器（注意创建方式）
	
	bestPaid = *empContainer.Begin(); //先将第一个employee赋值给bestpaid
    for (itr = empContainer.Begin(); !(itr == empContainer.End()); itr++) //遍历链表
    {
		if (*itr > bestPaid){
			bestPaid = *itr;
		}
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay: " << endl;
	bestPaid.output();
} // printBestPaid
