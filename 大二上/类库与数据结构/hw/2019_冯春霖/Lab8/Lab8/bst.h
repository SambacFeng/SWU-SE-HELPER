#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

#define NULL 0

#define LEFT 1
#define RIGHT 2
#define ROOT 0

template<typename T>
class BinSearchTree
{
	class Iterator; //very important!!!

private:

	struct Node
	{
		T item;
		Node* parent;
		Node* left;
		Node* right;
	}; // Node

	Node *root;
	int count;

	Iterator insertRec(const T& item, Node *curr, Node *parent, int side);
	void destroyRec(Node *curr);

public:
	BinSearchTree(); //  default constructor

	int size() const;

	//please implement this
	int height() const;

	int getHeight(Node* _node) const;

	Iterator insert(const T& item);

	~BinSearchTree();

	class Iterator
	{
		friend class BinSearchTree<T>;

	private:

		Node *curr;
		Iterator(Node *currNode);

	public:

		Iterator();

		Iterator& operator++ ();

		Iterator& operator-- ();

		T& operator* () const;

		bool operator== (const Iterator &otherIterator) const;

	}; // Iterator

}; // BinSearchTree

//************************the following is the implmentation of the bst class interfaces***********************************
template<typename T>
BinSearchTree<T>::BinSearchTree()
{
	root = NULL;
	count = 0;
}

template<typename T>
int BinSearchTree<T>::size() const
{
	return count;
}

template<typename T>
int BinSearchTree<T>::height() const
{
	return getHeight(root);
}

template<typename T>
int BinSearchTree<T>::getHeight(Node* _node) const
{
	return _node == NULL ? -1 : max(getHeight(_node->left) + 1, getHeight(_node->right) + 1);
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::insertRec(const T& item, Node *curr, Node *parent, int side)
{
	if (curr == NULL)//insert leaf
	{
		curr = new Node;
		curr->item = item;
		curr->parent = parent;
		curr->left = NULL;
		curr->right = NULL;

		if (side == LEFT)
			parent->left = curr;
		if (side == RIGHT)
			parent->right = curr;

		count++;
		if (count == 1)
			root = curr; //root

		return Iterator(curr);
	}
	else
	{
		if (item < curr->item) //insert left
			return insertRec(item, curr->left, curr, LEFT);
		else //insert right
			return insertRec(item, curr->right, curr, RIGHT);
	}
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::insert(const T& item)
{
	return insertRec(item, root, NULL, ROOT);
}

template<typename T>
void BinSearchTree<T>::destroyRec(Node *curr)
{
	if (curr != NULL)
	{
		destroyRec(curr->left);
		destroyRec(curr->right);
		delete curr;
	}
}

template<typename T>
BinSearchTree<T>::~BinSearchTree()
{
	destroyRec(root);
}


//************************the following is the implmentation of the iterator inner class***********************************
template<typename T>
BinSearchTree<T>::Iterator::Iterator(Node *currNode)
{
	curr = currNode;
}

//not implemented
template<typename T>
BinSearchTree<T>::Iterator::Iterator( )
{
}

//not implemented
template<typename T>
typename BinSearchTree<T>::Iterator& BinSearchTree<T>::Iterator::operator++()
{
}

//not implemented
template<typename T>
typename BinSearchTree<T>::Iterator& BinSearchTree<T>::Iterator::operator--()
{
}

template<typename T>
T& BinSearchTree<T>::Iterator::operator* () const
{
	return curr->item;
}

//not implemented
template<typename T>
bool  BinSearchTree<T>::Iterator::operator==(const Iterator &otherIterator) const
{
}


#endif