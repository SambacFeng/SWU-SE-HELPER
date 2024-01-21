#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <string.h>

#define NULL 0

template<typename T>
class BinSearchTree
{
	public:
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

	int treeHeight(Node* currNode) const;


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

	void deleteNode(Node* temp);

	// Postcondition: The tree-shape of this BinSearchTree has been printed
	void printTree();

	void printTreeStructure(Node* root, std::string prefix, bool isLeft);

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
	this->root = NULL;
	count = 0;

}

template<typename T>
int BinSearchTree<T>::size() const
{
	//Please implement this!
	return count;
}

template<typename T>
int BinSearchTree<T>::height() const
{
	//Please implement this!
	return treeHeight(root);
}

template<typename T>
int BinSearchTree<T>::treeHeight(Node* currNode) const
{
	//Please implement this!
	if (currNode == NULL) {
		return -1;
	}
	return 1 + std::max(treeHeight(currNode->left), treeHeight(currNode->right));
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::insert(const T& item)
{

	//Please implement this!
	if (count == 0) { //树为空时
		root = new Node;
		root->left = NULL;
		root->right = NULL;
		root->item = item;
	}
	else {
		//寻找合适的位置
		Node* parent = root->parent;
		Node* child = root;
		while (child != NULL) {
			parent = child;
			if (item < child->item) {
				child = child->left;
			}
			else {
				child = child->right;
			}
		}

		// 加入新节点
		if (item < parent->item) { //item小于parent
			Node* newNode = new Node;
			parent->left = newNode;
			newNode->item = item;
			newNode->parent = parent;
			newNode->left = NULL;
			newNode->right = NULL;
			return Iterator(newNode);
		}
		else { //item不小于parent
			Node* newNode = new Node;
			parent->right = newNode;
			newNode->item = item;
			newNode->parent = parent;
			newNode->left = NULL;
			newNode->right = NULL;
			return Iterator(newNode);
		}
	}
	count++;

}

template<typename T>
void BinSearchTree<T>::printTree()
{
	//Please think about how to implement this!
	printTreeStructure(root," ",false);
}

template <typename T>
void BinSearchTree<T>::printTreeStructure(Node* root, std::string prefix, bool isLeft)
{
	if (root) {
		std::cout << prefix;
		std::cout << (isLeft ? "└── " : "└── ");
		std::cout << root->item << std::endl;

		printTreeStructure(root->right, prefix + (isLeft ? "│   " : "    "), true);
		printTreeStructure(root->left, prefix + (isLeft ? "│   " : "    "), false);
	}
	else {
		std::cout << prefix;
		std::cout << (isLeft ? "└── " : "└── ");
		std::cout << "NULL" << std::endl;
	}
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
	deleteNode(root);
}

template<typename T>
void BinSearchTree<T>::deleteNode(Node* temp)
{
	//递归的方法，从下往上，先删子树再删自己。
	if (temp == nullptr) {
		return ;
	}
	deleteNode(temp->left);
	deleteNode(temp->right);
	delete temp;
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