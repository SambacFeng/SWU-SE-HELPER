#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

template<class T>
class ListTemp
{
private:
	struct Node
	{
		T data;
		Node *next;
	};

	Node *head;
	int size;

public:

	ListTemp();

	~ListTemp();

	int getLength() const;

	bool isEmpty() const;

	void AddHead(const T& newData);

	//************************declaration of the inner iterator class****************************
	class Iterator
	{
		friend class ListTemp<T>; //friend class
	private:
		Node *curr;
		Iterator(Node *ptr); //constructor with Node parameter, defined as private

	public:

		Iterator(); //default constructor

		Iterator operator++(int); //post-increment of ++

		T& operator*() const;

		bool operator==(const Iterator other) const;

	};//class Iterator

	Iterator Begin() const;

	Iterator End() const;

};


//************************implementation of the iterator inner class**************************
template<class T>
ListTemp<T>::Iterator::Iterator()
{
	curr = NULL;
}

template<class T>
ListTemp<T>::Iterator::Iterator(Node *ptr)
{
	curr = ptr;
}

template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::Iterator::operator++(int)
{
	Iterator temp = *this;
	this->curr = curr->next;
	return temp;
}

template<class T>
T& ListTemp<T>::Iterator::operator*() const
{
	return curr->data;
}

template<class T>
bool ListTemp<T>::Iterator::operator==(const Iterator other) const
{
	return curr == other.curr;
}


//************************implementation of the Begin and End position**************************
template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::Begin() const
{
	return Iterator(head); //private of Iterator class
}

template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::End() const
{
	return Iterator();
}





//************************implementation of the linked list class template**************************
template<class T>
ListTemp<T>::ListTemp()
{
	head = NULL;
	size = 0;
}


template<class T>
ListTemp<T>::~ListTemp()
{
	Node *current = head;
	Node *temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}


template<class T>
int ListTemp<T>::getLength() const
{
	return size;
}


template<class T>
bool ListTemp<T>::isEmpty() const
{
	return size == 0;
}


template<class T>
void ListTemp<T>::AddHead(const T& newData)
{
	Node *temp = new Node;
	temp->next = head;
	temp->data = newData;
	head = temp;

	size++;
}



#endif