#include <iostream>
#include "employee.h"
#include <ctime>
#include<cstdlib>
using namespace std;

Employee::Employee()
{
   name = "";
   grossPay = 0;
} // default constructor


void Employee::input(int id)
{
	//please implement this
	name = "employee" + to_string(id); //用string类的方法，
	//先将整数id转换为字符串，再用重载的“+”运算符来连接两个字符串，
	grossPay = rand(); //使用之前初始化过的随机数生成器
} // input


void Employee::output() const
{
	cout << "name: " << name << "; gross pay: " << grossPay << endl;
} // output

void Employee::operator=(const Employee &otherEmployee)
{
	name = otherEmployee.name;
	grossPay = otherEmployee.grossPay;
}

bool Employee::operator>(const Employee &otherEmployee) const
{
   return grossPay > otherEmployee.grossPay;
} // compare

string Employee::getName() const
{
	return name;
}