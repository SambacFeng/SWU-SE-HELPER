#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>

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

	Node *largestNode;
	Node *smallestNode;

	int count;

	Iterator insertRec(Node *curr, Node *parent, const T& item, int side);
	int getHeightRec(Node* root)const;
	int getLeafCountRec(Node* root)const;
	void destroy(Node *curr);

public:

	// Postcondition: this BinSearchTree is empty.
	BinSearchTree(); //  default constructor

   // Postcondition: the number of items in this BinSearchTree
   //                has been returned.
	int size() const;

	int height() const; //
	int LeafCount()const;

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
	
	void printTreeRec(Node* tempRoot);
	void printTree(); //please implement

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
	root = NULL;

	largestNode = NULL;
	smallestNode = NULL;

	count = 0;
}

template<typename T>
int BinSearchTree<T>::size() const
{
	return count;
}


template<typename T>
int BinSearchTree<T>::getLeafCountRec(Node* root)const{
	if (root == NULL)
		return 0;
	else
	{
		if ((root->right ==NULL) && (root->left == NULL))
			return 1;
		else
			return getLeafCountRec(root->left) + getLeafCountRec(root->right);
	}
}

template<typename T>
int BinSearchTree<T>::LeafCount() const
{
	return getLeafCountRec(root);	//计算叶子节点迭代函数
}

//计算树高的迭代函数
template<typename T>
int BinSearchTree<T>::getHeightRec(Node* tempRoot)  const {	
	if (tempRoot == NULL)	return -1;	//空树的树高定义为-1
	int leftHeight = getHeightRec(tempRoot->left);		//计算并返回左子树树高
	int rightHeight = getHeightRec(tempRoot->right);	//计算并返回右子树树高
	//以左右子树高的为准，加上自己这个节点，返回当前树高
	if (leftHeight > rightHeight) return leftHeight+1;
	else return rightHeight+1;
}

template<typename T>
int BinSearchTree<T>::height() const
{
	return getHeightRec(root);	//计算树高迭代函数
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::insertRec(Node *curr, Node *parent, const T& item, int side)
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
			root = curr;//root

		return Iterator(curr);
	}
	else
	{
		if (item < curr->item) //insert left
			return insertRec(curr->left, curr, item, LEFT);
		else //insert right
			return insertRec(curr->right, curr, item, RIGHT);
	}
}

template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::insert(const T& item)
{
	return insertRec(root, NULL, item, ROOT);
}


template<typename T>
void BinSearchTree<T>::printTreeRec(Node* tempRoot) {
	//分类1：根节点没有右孩子的情况，无法调用它的父母，所以先单独判断
	if(tempRoot==root && tempRoot->right==NULL)		
		cout << tempRoot->item << "\n";	
	//分类2：右孩子链的结尾换行，此情况为了避免与左子树根节点的打印重合，又加入条件必须是是父节点的右孩子节点
	else if (tempRoot->right == NULL && tempRoot->parent->right==tempRoot)
		cout << tempRoot->item<<"\n";
	//分类3：左子树开头情况，要统计tab数和“|”的打印位置
	else if (tempRoot != root && tempRoot->parent->left == tempRoot) {
		Node* temp = tempRoot->parent;	//创建临时节点，用来遍历当前节点的祖宗节点，判断tab数和“|”的打印位置
		vector <string> tab;	//创建向量tab用来储存tab和“|”

		//遍历当前节点的祖宗节点
		while (temp != root) {
			if(temp->parent->left != NULL && temp->item != 101) 
				tab.push_back("│\t");	//如果此节点未被标记，则需要打印“|”连接
			else 
				tab.push_back("\t"); //如果此节点被标记为101则说明以打印，不需要再打印“|”连接
			temp = temp->parent;
		}

		//将tab向量反向输出
		for (int i = tab.size(); i >0; i--) {
			cout << tab[i-1];
		}

		if (tempRoot->right == NULL) {	//分类3.1：如果这个节点既是左子树开始，又是左子树结尾
			cout << "└─────\t" << tempRoot->item << "\n";
			tempRoot->item = 101;	//标记已输出的右子树根
		}
		else {	//分类3.2：如果这个节点仅是左子树开始，他还有右孩子
			cout << "└─────\t" << tempRoot->item << "────\t";
			tempRoot->item = 101;	//标记已输出的右子树根
		}
	}
	else cout << tempRoot->item <<"────\t";	//分类4：右子树链的普通情况


	//递归代码
	if (tempRoot->right != NULL) {
		printTreeRec(tempRoot->right);
	}
	if (tempRoot->left != NULL) {
		printTreeRec(tempRoot->left);		
	}
	if (tempRoot->right == NULL && tempRoot->left == NULL) return;

}
//please implement
template<typename T>
void BinSearchTree<T>::printTree()
{
	printTreeRec(root);
}

//not implemented
template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::find(const T& item) const
{
	return Iterator();
}

//not implemented
template<typename T>
void BinSearchTree<T>::erase(Iterator itr)
{

}


template<typename T>
void BinSearchTree<T>::destroy(Node *curr)
{
	if (curr != NULL)
	{
		destroy(curr->left);
		destroy(curr->right);
		delete curr;
	}
}

template<typename T>
BinSearchTree<T>::~BinSearchTree()
{
	destroy(root);
}

//not implemented
template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::begin()
{
	
}

//not implemented
template<typename T>
typename BinSearchTree<T>::Iterator BinSearchTree<T>::end()
{

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