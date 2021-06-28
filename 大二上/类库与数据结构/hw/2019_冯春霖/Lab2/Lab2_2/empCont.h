#ifndef EMPCONT_H
#define EMPCONT_H
#include "employee.h"

// defines a container that can hold any number of employees
class EmpCont
{
private:
	int capacity;
	int size;
	Employee* empArray; //a pointer, points to the memory space dynamically allocated for the container

	void Extend(); //extend the capacity when the container is full; called after isFull test returns true
	bool isFull() const; //check whether the container is full; called in the Add method

public:

	EmpCont();

	int getLength() const; //returns the current number of items stored in the container

	void Add(const Employee& newEmp); //add an item at the end of the container

	Employee& Access(int i) const; //access the ith item in the container

	~EmpCont(); //destructor

	//implement the following methods
	void remove(int i);
};

#endif