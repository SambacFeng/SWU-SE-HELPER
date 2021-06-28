
#include <iostream>
#include "empCont.h"
using namespace std;

EmpCont::EmpCont()
{
	size = 0;
	capacity = 5; //initial capacity is 5
	empArray = new Employee[capacity]; //allocate memory space
}

void EmpCont::Extend()
{
	capacity = capacity * 2;
	Employee* temp = new Employee[capacity];

	for (int i = 0; i < size; i++)
		temp[i] = empArray[i]; 

	delete[] empArray; //memory reclaim

	empArray = temp;
}

bool EmpCont::isFull() const
{
	return (size == capacity);
}


int EmpCont::getLength() const
{
	return size;
}

void EmpCont::Add(const Employee& newEmp)
{
	if (!isFull())
	{
		empArray[size] = newEmp;
		size++;
	}
	else
	{
		Extend();
		Add(newEmp); //recursive
	}
}


Employee& EmpCont::Access(int i) const
{
	if (i < 0 || i >= size)
	{
		cout << "Out-of-bound access!" << endl;
		exit(-1);
	}
	else
		return empArray[i];
}

EmpCont::~EmpCont()
{
	delete[] empArray; //memory reclaim
}


//implement the following method
void EmpCont::remove(int i)
{
	for (int j = i; j < size - 1; j++)
	{
		empArray[j] = empArray[j + 1];
	}
	Employee temp;
	empArray[size-1] = temp;
	size--;
}

