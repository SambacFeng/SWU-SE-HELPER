#include<iostream>
using namespace std;

template <class T>
struct treeNode
{
    T data;
    treeNode* left;
    treeNode* right;
};

template <class T>
void inorder(treeNode<T>* start) {
    if (start == nullptr) {
        return;
    }
    else {
        cout << "Entering node " << start->data << endl;
        inorder(start->left);
        cout << "Processing node " << start->data << endl;
        cout << start->data << " ";
        inorder(start->right);
        cout << "Exiting node " << start->data << endl;
    }
}

int main() {
    treeNode<int>* a = new treeNode<int>;
    treeNode<int>* b = new treeNode<int>;
    treeNode<int>* c = new treeNode<int>;
    treeNode<int>* d = new treeNode<int>;

    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;

    a->left = b;
    a->right = d;

    b->right = c;

    inorder(a);

    return 0;
}