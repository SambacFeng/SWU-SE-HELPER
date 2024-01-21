#include "company.h"
#include <iostream>
using namespace std;

void Company::inputEmployeeHead(int total_num)
{
	//please implement this
	//循环input，次数为传入的参数total_num
	for (int i = 0; i < total_num; i++) {
		srand((unsigned int)time(NULL));//初始化随机数发生器，
		//用当前时间（转化为无符号整数）作为seed
		int id = i + 1; //id就按顺序来好了，无所谓的
		Employee newEmployee;
		newEmployee.input(id);
		container.addHead(newEmployee);//用addHead方法从头增加
	}
}

void Company::inputEmployeeTail(int total_num)
{
	//please implement this
	for (int i = 0; i < total_num; i++) {
		srand((unsigned int)time(NULL));//初始化随机数发生器，
		//用当前时间（转化为无符号整数）作为seed
		int id = i + 1;
		Employee newEmployee;
		newEmployee.input(id);
		container.addTail(newEmployee);
	}

}

void Company::findBestPaid()
{
	bestPaid = Employee();
	ListTemp<Employee>::Iterator curr = container.Begin();
	while (!(curr == container.End()))
	{
		if (*curr > bestPaid)
			bestPaid = *curr;
		curr++;
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay: " << endl;
	bestPaid.output();
} // printBestPaid
