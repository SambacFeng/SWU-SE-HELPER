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

	//please implement the following method
	void AddHead(const T& newData);
	//please implement the following method
	void AddTail(const T& newData);
};

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
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
	size++;
}

template<class T>
void ListTemp<T>::AddTail(const T& newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = NULL;
	if (head == NULL)
		head = newNode;
	else
	{
		Node* itr = head;
		while ((itr->next) != NULL)
			itr = itr->next;
		itr->next = newNode;
	}
	size++;
}

#endif