#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

#include <iostream>
using namespace std;

template<class T>
class ListTemp
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node *head;
	int size;

public:

	ListTemp();

	~ListTemp();

	int getLength() const;

	bool isEmpty() const;
	
	void AddHead(const T& newData);

	void AddLast(const T& newData);

	T Access(const int n)const;
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
void ListTemp<T>::AddHead(const T& newData)
{
	Node *newHead = new Node;
	newHead->data = newData;
	newHead->next = head;
	head = newHead;
	size++;

} 

template<class T>
void ListTemp<T>::AddLast(const T& newData)
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	Node* last = new Node;
	temp->next = last;
	last->data = newData;
	size++;

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
T ListTemp<T>::Access(const int n)const
{
	int i = 0;
	Node *temp=head;
	T access;
	while (i <= n && temp != NULL) 				//遍历所有的链节，找到要删除的一项，地址存入delet_element；
	{
		access = temp -> data;
		temp = temp -> next;
		i++;
	}

	return access;
}

#endif