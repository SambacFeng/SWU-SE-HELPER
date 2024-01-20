#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

template<class T>
class list
{
private:
	struct Node
	{
		T item;
		Node* next;
		Node* pre;
	};

	Node* head;
	Node* tail;

public:

	//************************declaration of the inner iterator class****************************
	class iterator
	{
		friend class list<T>; //friend class of the iterator class
	private:
		Node* curr;

	public:
		iterator(Node* ptr); //constructor with Node parameter, defined as private

		iterator(); //default constructor

		iterator& operator++(); //pre-increment of ++

		iterator operator++(int); //post-increment of ++

		iterator& operator--(); //pre-increment of --

		iterator operator--(int); //post-increment of --

		T& operator*() const; //返回item的引用，由于返回的是引用，所以如果对返回值进行赋值，会直接修改list中item的内容

		bool operator==(const iterator other) const;

	};//class Iterator

	list(); //constructor

	~list(); //destructor


	list(const list<T>& x); //copy constructor, worstTime(n) is O(n)

	void push_front(const T& x); //在头部加入元素

	void push_back(const T& x); //在尾部加入元素

	iterator insert(iterator position, const T& x); //在position前加入x，返回指向x的迭代器，worstTime(n) is constant. 

	void pop_front(); //list非空，删除第一个元素

	void pop_back();// list非空，删除最后一个元素

	iterator erase(iterator position); //删除position指向的元素，返回指向position下一个位置的迭代器，worstTime(n) is constant. 

	iterator erase(iterator first, iterator last);//删除区间[first,last)的元素

	unsigned size() const; //返回size

	bool empty() const; //返回是否为空链表

	iterator begin() const; //返回指向第一个元素的迭代器

	iterator end() const; //返回指向最后一个元素的下一个元素的迭代器

	list<T>& operator=(const list<T>& x); //重载赋值运算符，把一个x中的内容复制过来

	void splice(iterator position, list<T>& x); //将x里的内容转移到position之前，x变为empty

};

#endif