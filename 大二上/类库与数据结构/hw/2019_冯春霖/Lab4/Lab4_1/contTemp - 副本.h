#ifndef CONTTEMP_H
#define CONTTEMP_H

#define NULL 0

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

	~ContTemp(); //destructor

	//please implement the iterator inner class
	//************************declaration of the inner iterator class****************************
	class Iterator
	{
		friend class ContTemp<T>;
	private:
		T* curr_ptr;

		Iterator(T* ptr);

	public:

		Iterator(); //default constructor

		Iterator operator++(int); //post-increment of ++

		T& operator*() const;

		bool operator==(const Iterator other) const;

	};//class Iterator

	//please implement begin and end

	Iterator Begin() const;

	Iterator End() const;

}; 



//************************implementation of the inner class**************************
template<class T>
ContTemp<T>::Iterator::Iterator()
{
	curr_ptr = NULL;
}

template<class T>
ContTemp<T>::Iterator::Iterator(T* ptr)
{
	curr_ptr = ptr;
}

template<class T>
typename ContTemp<T>::Iterator ContTemp<T>::Iterator::operator++(int)
{
	return ++curr_ptr;
}

template<class T>
T& ContTemp<T>::Iterator::operator*() const
{
	return curr_ptr;
}

template<class T>
bool ContTemp<T>::Iterator::operator==(const Iterator other) const
{
	return curr_ptr == other.curr_ptr;
}

//************************implementation of Begin() and End()**************************
template<class T>
typename ContTemp<T>::Iterator ContTemp<T>::Begin() const
{
	return Iterator(elemArray);
}

template<class T>
typename ContTemp<T>::Iterator ContTemp<T>::End() const
{
	return Iterator();
}

//*****************the following is the method implementation of container*******************************//

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
ContTemp<T>::~ContTemp()
{
	delete[] elemArray; //garbage collection
}


#endif