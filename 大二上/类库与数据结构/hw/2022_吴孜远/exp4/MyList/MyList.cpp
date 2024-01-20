#include"MyList.h"

//************************implementation of the linked list class template**************************
template<class T>
list<T>::list()
{
	head = NULL;
	tail = NULL;
}


template<class T>
list<T>::~list()
{
	Node* current = head;
	Node* temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp; //release
	}
}


template<class T>
list<T>::list(const list<T>& x) 
{
	Node* current = x.head;
	while (current != NULL)
	{
		push_back(current->item);
		current = current->next;
	}
}


template<class T>
void list<T>::push_front(const T& x)
{
	Node* newNode = new Node; //创建新节点
	newNode->item = x;
	if (empty()) {
		head = newNode;
		tail = newNode;
		newNode->pre = NULL;
		newNode->next = NULL;
	}
	else {
		head->pre = newNode;
		newNode->pre = NULL;
		newNode->next = head;
		head = newNode;
	}
}

template<class T>
void list<T>::push_back(const T& x)
{

	Node* newNode = new Node;
	newNode->item = x;
	if (empty()) {
		head = newNode;
		tail = newNode;
		newNode->pre = NULL;
		newNode->next = NULL;
	}
	else {
		newNode->pre = tail; //新节点pre指向原来的tail
		tail->next = newNode; //原来的尾节点的next指向新节点
		newNode->next = NULL;
		tail = newNode;
	}
}

template<class T>
typename list<T>::iterator list<T>::insert(iterator position, const T& x) {
	Node* newNode = new Node;
	newNode->item = x;
	newNode->next = position.curr;
	newNode->pre = (position.curr)->pre;
	(position.curr)->pre->next = newNode;
	position.curr->pre = newNode;
	position--;
	return position;
}

template<class T>
void list<T>::pop_front() {
	head = head->next; //head指向第二个元素
	delete head->pre;
	head->pre = NULL;
}

template<class T>
void list<T>::pop_back() {
	tail = tail->pre; //tail指向倒数第二个元素
	delete tail->next;
	tail->next = NULL;
}

template<class T>
typename list<T>::iterator list<T>::erase(iterator position) {
	if ((position.curr) == NULL) {
		return position;
	}
	//定位前后两个结点的位置
	Node* front = position.curr->pre;
	Node* behind = position.curr->next;

	position++;
	delete position.curr->pre;

	front->next = behind;
	behind->pre = front;
	return position;
}

template<class T>
typename list<T>::iterator list<T>::erase(iterator first, iterator last){
	if (first.curr == last.curr == NULL) {
		return last;
	}
	//定位前后两个结点的位置
	Node* front = (first.curr)->pre;
	Node* behind = (last.curr);
	while (!(first == last)) {
		first++;
		delete (first.curr)->pre;
	}
	front->next = behind;
	behind->pre = front;
	return last;
}

template<class T>
unsigned list<T>::size() const
{
	Node* temp = head;
	int size = 0;
	while (temp != NULL) {
		temp = temp->next;
		size++;
	}
	return size;
}


template<class T>
bool list<T>::empty() const
{
	return size() == 0;
}

template<class T>
list<T>& list<T>::operator=(const list<T>& x) 
{
	//先将原来存储的元素全部删掉
	Node* current = head;
	Node* temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp; //release
	}

	//将x中的所有元素都复制过来
	Node* current2 = x.head;
	while (current2 != NULL)
	{
		push_back(current2->item);
		current2 = current2->next;
	}
	return *this;
}

template<class T>
void list<T>::splice(iterator position, list<T>& x) {
	Node* front = position.curr->pre;
	Node* behind = position.curr;
	front->next = x.head;
	x.head->pre = front;
	behind->pre = x.tail;
	x.tail->next = behind;

	x.head = NULL;
	x.tail = NULL;
}

//************************implementation of the Begin and End position**************************
template<class T>
typename list<T>::iterator list<T>::begin() const
{
	return iterator(head); 
}

template<class T>
typename list<T>::iterator list<T>::end() const
{
	return iterator(); 
}







