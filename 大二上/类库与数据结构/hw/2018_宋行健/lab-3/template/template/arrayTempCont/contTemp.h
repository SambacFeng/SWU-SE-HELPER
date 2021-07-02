#ifndef CONTTEMP_H
#define CONTTEMP_H
#include<iostream>

using namespace std;

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

	ContTemp(int capacity);

	int getLength() const;

	void Add(const T& newElem);

	void Add(const T& newElem, int i);

	T& Access(const int i) const;

	T& remove(int i);

	~ContTemp(); //destructor

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
ContTemp<T>::ContTemp(int capacity)
{
	size = 0;
	elemArray = new T[capacity];
}

template<class T>
int ContTemp<T>::getLength() const
{
	return size;
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

//尾部添加
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

//在i位置添加元素
template<class T>
void ContTemp<T>::Add(const T& newElem,int i)
{
	if (!isFull())
	{
		//i位置后所有元素后推一位
		for (int j = i; j < size; j++)
		{
			elemArray[j + 1] = elemArray[j];
		}
		elemArray[i] = newElem;
		size++;
	}
	else
	{
		Extend();
		Add(newElem);
	}
}


//查找i位置的元素
template<class T>
T& ContTemp<T>::Access(const int i) const
{
	if (i < 0 || i >= size)
		std::cout << "Out-of-bound access!" << std::endl;
	else
		return elemArray[i];
}

//删除指定位置i的元素
template<class T>
T& ContTemp<T>::remove(int i) {

	if (i < 0 || i >= size)
	{
		cout << "Out-of-bound access!" << endl;
		exit(-1);
	}
	else
	{
		for (int j = i; j < size; j++)
		{
			elemArray[j] = elemArray[j + 1];
		}
	}
	size--;

	return *elemArray;
}

template<class T>
ContTemp<T>::~ContTemp()
{
	delete[] elemArray; //garbage collection
}

#endif