#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define INT_MAX 0x7fffffff
using namespace std;


/*****************************************************************
* 函数描述： 打印 vector
* 函数参数： arr——向量
* 函数返回： void
*****************************************************************/
void printVector(vector<int>& arr)
{
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout << setw(5) << *it << '\t';
    }
    cout << "\n" << endl;
}




class MergeTree
{
private:
    struct MergeNode
    {
        int weight; // 节点权重，记录数
        int parent;
        int lchild, rchild;
    };

public:
    // 构造函数
    MergeTree(vector<int> arr)
    {
        int n = arr.size(); // 求得当前 arr 的节点个数
        count = 2 * n - 1;  // 二叉树的总节点数;
        MoveTotal = 0;      // 移动总量初始化为0
        Node = new MergeNode[count];
        // 使用传入的向量构造叶子节点
        for (int i = 0; i < size(arr); ++i)
        {
            LeafNodes.push_back(arr[i]);
        }
    }

    MergeNode* Node;
    int count;             // 总节点数
    int MoveTotal;         // 移动总量
    vector<int> LeafNodes; // 节点数据
    // 核心算法：构造最优二元归并树
    void Tree();
    // 从 LeafNodes 选取两个最小数
    void selectMin(int& s1, int& s2);
    // 打印树
    void printTree();
    // 标记已经归并的节点，把 LeafNodes 的 i 位置置位为正无穷
    void labelNode(vector<int>& arr, int i) { arr[i] = INT_MAX; }
};


/*****************************************************************
* 函数描述： 选择 vector 中两个最小的数，并将索引号储存在 s1 和 s2 中
* 函数参数： s1, s2——储存当前的两个最小的数的内存地址
* 函数返回： void
*****************************************************************/
void MergeTree::selectMin(int& s1, int& s2)
{
    int Min1 = INT_MAX, Min2 = INT_MAX;
    for (int i = 0; i < LeafNodes.size(); ++i)
    {
        if (LeafNodes[i] < Min1)
        {
            if (Min1 < Min2)
            {
                Min2 = Min1;
                s2 = s1;
            }
            Min1 = LeafNodes[i];
            s1 = i;
        }
        else if (LeafNodes[i] < Min2)
        {
            Min2 = LeafNodes[i];
            s2 = i;
        }
        else
            continue;
    }
}

/*****************************************************************
* 函数描述： 构造二元归并的最优解法树
* 函数参数： null
* 函数返回： void
*****************************************************************/
void MergeTree::Tree()
{
    sort(LeafNodes.begin(), LeafNodes.end()); // 将 arr 升序排列
    int n = LeafNodes.size();                 // 求得当前 arr 的节点个数
    //初始化，所有节点没有父节点和左右子节点
    for (int i = 0; i < count; ++i)
    {
        Node[i].parent = -1;
        Node[i].lchild = -1;
        Node[i].rchild = -1;
    }
    for (int i = n; i < count; ++i)
    {
        int i1, i2;
        selectMin(i1, i2);
        Node[i1].weight = LeafNodes[i1];
        Node[i2].weight = LeafNodes[i2];
        Node[i1].parent = i;
        Node[i2].parent = i;
        int mid = Node[i1].weight + Node[i2].weight;
        Node[i].lchild = i1;
        Node[i].rchild = i2;
        Node[i].weight = mid;
        // 把 i1 和 i2 位置置位为正无穷
        labelNode(LeafNodes, i1);
        labelNode(LeafNodes, i2);
        // 插入新的节点
        LeafNodes.insert(LeafNodes.begin() + i, mid);
        // 累加移动总量
        MoveTotal += mid;
    }
}

/*****************************************************************
* 函数描述： 打印最优解法树
* 函数参数： null
* 函数返回： void
*****************************************************************/
void MergeTree::printTree()
{
    cout << "移动总量为：" << MoveTotal << endl;
    for (int i = 0; i < count; ++i)
    {
        cout << setw(7) << "节点：" << Node[i].weight << "\t";
        cout << setw(7) << "父节点：" << Node[Node[i].parent].weight << "\t";
        cout << setw(7) << "左：" << Node[Node[i].lchild].weight << "\t";
        cout << setw(7) << "右：" << Node[Node[i].rchild].weight << endl;
    }
}


int main()
{
    vector<int> arr;
    int test[] = { 15, 30, 10, 8, 40, 13 };
    for (int i = 0; i < size(test); ++i)
    {
        arr.push_back(test[i]);
    }

    cout << "需要进行二元归并的数据：" << endl;
    printVector(arr);

    // 使用 vector 数据实例化一个归并树
    MergeTree mt(arr);
    // 进行二元最优归并
    mt.Tree();
    // 打印结果
    mt.printTree();

    return 0;
}