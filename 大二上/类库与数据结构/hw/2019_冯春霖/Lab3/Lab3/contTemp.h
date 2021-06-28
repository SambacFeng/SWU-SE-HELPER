#ifndef CONTTEMP_H
#define CONTTEMP_H
#include <iostream>

//**************************the following is the class delcaration*********************************//
template<class T>
class ContTemp
{
private:
	int capacity;
	int size;
	T* elemArray;

	void Extend();
	bool isFull() const;

public:

	ContTemp();

	int getLength() const;

	void Add(const T& newElem);

	T& Access(const int i) const;

	~ContTemp(); //destructor

	//please implement this!
	void Remove(int i);

};



//*****************the following is the method implementation*******************************//

template<class T>
ContTemp<T>::ContTemp()
{
	size = 0;
	capacity = 5;
	elemArray = new T[capacity];
}

template<class T>
int ContTemp<T>::getLength() const
{
	return size;
}


template<class T>
void ContTemp<T>::Add(const T& newElem)
{
	if (!isFull())
	{
		elemArray[size] = newElem;
		size++;
	}
	else
	{
		Extend();
		Add(newElem);
	}
}

template<class T>
void ContTemp<T>::Extend()
{
	capacity = capacity * 2;
	T* temp = new T[capacity];

	for (int i = 0; i < size; i++)
		temp[i] = elemArray[i];

	delete[] elemArray;

	elemArray = temp;
}

template<class T>
bool ContTemp<T>::isFull() const
{
	return (size == capacity);
}

template<class T>
T& ContTemp<T>::Access(const int i) const
{
	if (i < 0 || i >= size)
		std::cout << "Out-of-bound access!" << std::endl;
	else
		return elemArray[i];
}

template<class T>
ContTemp<T>::~ContTemp()
{
	delete[] elemArray; //garbage collection
}

template<class T>
void ContTemp<T>::Remove(const int i)
{
	for (int j = i; j < size - 1; j++)
	{
		elemArray[j] = elemArray[j + 1];
	}
	T temp;
	elemArray[size - 1] = temp;
	size--;
}


#endif