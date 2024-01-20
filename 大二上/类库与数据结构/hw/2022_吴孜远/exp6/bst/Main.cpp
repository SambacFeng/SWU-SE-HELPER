#include<iostream>
#include"bst.h"
using namespace std;

int main() {
	
	srand((unsigned)time(0));
	/*int sum = 0;
	double aveHeight = 0;
	for (int n = 10; n < 60; n = n + 5) {
		cout << n << ", ";
	}
	cout << endl;
	for (int n = 10; n < 60; n = n + 5) { //测试节点数为11-20
		sum = 0;
		for (int i = 0; i < 20; i++) { //每个节点数生成20次树，取树高平均值
			BinSearchTree<int>* bst = new BinSearchTree<int>;

			for (int i = 0; i < n; i++) { //生成一个n个结点的树
				bst->insert(rand() % 100 + 1);
			
			}
			sum = sum + bst->height();
		
			//cout << bst->height() << " ";
		}
		aveHeight = sum / 20.0;
		cout << aveHeight << ",";
	}*/
	BinSearchTree<int>* bst = new BinSearchTree<int>;
	BinSearchTree<int>::Iterator itr;
	for (int i = 0; i < 50; i++) { //生成一个n个结点的树
		bst->insert(rand() % 100 + 1);

	}
	bst->printTree();

	return 0;
}
