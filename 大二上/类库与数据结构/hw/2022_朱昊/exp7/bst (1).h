#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

#define NULL 0

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

public:

	// Postcondition: this BinSearchTree is empty.
	BinSearchTree(); //  default constructor

   // Postcondition: the number of items in this BinSearchTree
   //                has been returned.
	int size() const;

	// Postcondition: the height of this BinSearchTree
	//                has been returned.
	int height() const;

	// Postcondition: item has been inserted into this BinSearchTree. An iterator 
	//                positioned at the inserted item has been returned. The
	//                averageTime(n) is O(log n) and worstTime(n) is O(n).
	Iterator insert(const T& item);

	// Postcondition: if there is an item in this BinSearchTree that equals item,
	//                the value returned is an iterator pointing to that item.
	//                Otherwise, the value returned is an iterator with the same
	//                value as the iterator returned by the end( ) method.  The
	//                averageTime(n) is O(log n) and worstTime(n) is O(n).
	Iterator find(const T& item) const;

	// Precondition: itr is positioned at an item in this BinSearchTree.
	// Postcondition: the item that itr is positioned at has been deleted from
	//                this BinSearchTree.  The averageTime(n) is O(log n)
	//                and worstTime(n) is O(n).
	void erase(Iterator itr);

	// Postcondition: The space allocated for this BinSearchTree has been
	//                deallocated.  The worstTime(n) is O(n).
	~BinSearchTree();

	// Postcondition: The tree-shape of this BinSearchTree has been printed
	void printTree();

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

		bool operator== (const Iterator &otherIterator)const;

	}; // Iterator

	// Postcondition: if this BinSearchTree is non-empty, an iterator positioned
	//                at the smallest item in the tree has been returned.
	//                Otherwise, the iterator returned has the same value as the
	//                iterator returned by the end( ) method.
	Iterator begin();


	// Postcondition: the value returned is an iterator that can be used in a 
	//                comparison for ending the traversal of this BinSearchTree.
	//                If this BinSearchTree is non-empty, the largest item is in the
	//                position just before the position of the iterator returned.
	Iterator end();

}; // BinSearchTree



//************************the following is the implmentation of the bst class interfaces***********************************
template<typename T>
BinSearchTree<T>::BinSearchTree()
{
	//Please implement this!
}

template<typename T>
int BinSearchTree<T>::size() const
{
	//Please implement this!
}

template<typename T>
int BinSearchTree<T>::height() const
{
	//Please implement this!
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::insert(const T& item)
{
	//Please implement this!
}

template<typename T>
void BinSearchTree<T>::printTree()
{
	//Please think about how to implement this!
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::find(const T& item) const
{
	//not finished
	return Iterator();
}


template<typename T>
void BinSearchTree<T>::erase(Iterator itr)
{
	//not finished
}

template<typename T>
BinSearchTree<T>::~BinSearchTree()
{
	//Please implement this!
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::begin()
{
	//not finished
	return Iterator();
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::end()
{
	//not finished
	return Iterator();
}

//************************the following is the implmentation of the iterator inner class***********************************
template<typename T>
BinSearchTree<T>::Iterator::Iterator(Node *currNode)
{
	curr = currNode;
}

template<typename T>
BinSearchTree<T>::Iterator::Iterator( )
{
}

template<typename T>
typename BinSearchTree<T>::Iterator& BinSearchTree<T>::Iterator::operator++()
{
	//not finished
	return Iterator();
}

template<typename T>
typename BinSearchTree<T>::Iterator& BinSearchTree<T>::Iterator::operator--()
{
	//not finished
	return Iterator();
}

template<typename T>
T& BinSearchTree<T>::Iterator::operator* () const
{
	return curr->item;
}

template<typename T>
bool  BinSearchTree<T>::Iterator::operator==(const Iterator &otherIterator) const
{
	//not finished
	return false;
}


#endif