#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

template<class T>
class doubleListTemp
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node* pre;
	};

	Node *head;
	int size;

public:

	doubleListTemp(); //constructor

	~doubleListTemp(); //destructor

	int getLength() const; //get the number of elements

	bool isEmpty() const; //check whether the container is empty

	// Postcondition: A node with newData has been inserted at the
	//                head of the Linked container.
	void addHead(const T& newData); 

	//************************declaration of the inner iterator class****************************
	class Iterator
	{
		friend class doubleListTemp<T>; //friend class of the iterator class
	private:
		Node *curr;

		Iterator(Node *ptr); //constructor with Node parameter, defined as private

	public:

		Iterator(); //default constructor

		Iterator operator++(int); //post-increment of ++
		Iterator operator--(int); //反向迭代

		T& operator*() const;

		bool operator==(const Iterator other) const;

	};//class Iterator

	Iterator Begin() const;
	Iterator reverse_Begin() const;

	Iterator End() const;
	Iterator reverse_End() const;

};


//************************implementation of the iterator inner class**************************
template<class T>
doubleListTemp<T>::Iterator::Iterator()
{
	curr = NULL;
}

template<class T>
doubleListTemp<T>::Iterator::Iterator(Node *ptr)
{
	curr = ptr;
}

template<class T>
typename doubleListTemp<T>::Iterator doubleListTemp<T>::Iterator::operator++(int)
{
	Iterator temp = *this; //default copy constructor
	this->curr = curr->next;
	return temp; //return iterator object
}

template<class T>
typename doubleListTemp<T>::Iterator doubleListTemp<T>::Iterator::operator--(int)
{
	Iterator temp = *this; //default copy constructor
	this->curr = curr->pre; //让当前指针指向前一个结点
	return temp; //return iterator object
}

template<class T>
T& doubleListTemp<T>::Iterator::operator*() const
{
	return curr->data; //return data reference
}

template<class T>
bool doubleListTemp<T>::Iterator::operator==(const Iterator other) const
{
	return curr == other.curr;
}


//************************implementation of the Begin and End position**************************
template<class T>
typename doubleListTemp<T>::Iterator doubleListTemp<T>::Begin() const
{
	return Iterator(head); 
}

template<class T>
typename doubleListTemp<T>::Iterator doubleListTemp<T>::reverse_Begin() const
{
	doubleListTemp<Employee>::Iterator itrTemp = Begin();
	int count = size;
	while (count != 1) {
		itrTemp++;
		count--;
	}
	return itrTemp;

	//Node* endNode = head;
	//while(endNode->next != NULL) {
	//	endNode = endNode->next;
	//}
	//return Iterator(endNode); //用最后一个元素的地址来初始化
}

template<class T>
typename doubleListTemp<T>::Iterator doubleListTemp<T>::End() const
{
	return Iterator(); //NULL pointer
}

template<class T>
typename doubleListTemp<T>::Iterator doubleListTemp<T>::reverse_End() const
{
	return Iterator(head->pre);  //直接传NULL为什么不行？
}


//************************implementation of the linked list class template**************************
template<class T>
doubleListTemp<T>::doubleListTemp()
{
	head = NULL; //empty list
	size = 0;
}


template<class T>
doubleListTemp<T>::~doubleListTemp()
{
	Node *current = head;
	Node *temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp; //release
	}
}


template<class T>
int doubleListTemp<T>::getLength() const
{
	return size;
}


template<class T>
bool doubleListTemp<T>::isEmpty() const
{
	return size == 0;
}


template<class T>
void doubleListTemp<T>::addHead(const T& newData)
{
	//please implement this
	Node* newHead = new Node;
	if (head != NULL) {
		head->pre = newHead; //反向迭代
	}
	newHead->data = newData;
	newHead->next = head;
	head = newHead;
	size++;
}


#endif