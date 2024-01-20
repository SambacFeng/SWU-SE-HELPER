#include <iostream>
using namespace std;

#include "company.h"

void Company::inputEmployee()
{
	Employee newEmployee; 
	newEmployee.input(); //input方法已经封装好了

	while (newEmployee.getName() != "*") //当name输入"*"时停止循环
	{
		empContainer.addHead(newEmployee); //将newEmployee中的数据传入容器
		newEmployee.input(); //更新newEmployee中的数据
	}

	
	//please implement this
}
