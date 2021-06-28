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
		friend class ListTemp<T>;
	private:
		Node *head;
		Node *curr;
		Iterator(Node *hear_ptr, Node *curr_ptr); //constructor with Node parameter, defined as private

	public:

		Iterator(); //default constructor

		Iterator operator++(int); //post-increment of ++

		//please implement this
		Iterator operator--(int); //post-decrement of --

		T& operator*() const;

		bool operator==(const Iterator other) const;

	};//class Iterator

	//please implement this
	Iterator Begin() const;

	//please implement this
	Iterator End() const;

};


//************************implementation of the iterator inner class**************************
template<class T>
ListTemp<T>::Iterator::Iterator()
{
	head = NULL;
	curr = NULL;
}

template<class T>
ListTemp<T>::Iterator::Iterator(Node *head_ptr, Node *curr_ptr)
{
	head = head_ptr;
	curr = curr_ptr;
}

template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::Iterator::operator++(int)
{
	Iterator temp = *this;
	this->curr = curr->next;
	return temp;
}

// please implement this
template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::Iterator::operator--(int)
{
	Iterator temp = Iterator(head, head);
	Iterator _this = *this;
	while (true)
	{
		if (temp == _this)
			break;
		*this = temp;
		temp++;
	}

	return _this;
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
	return Iterator(head, head);
}

template<class T>
typename ListTemp<T>::Iterator ListTemp<T>::End() const
{
	return Iterator(head, NULL);
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