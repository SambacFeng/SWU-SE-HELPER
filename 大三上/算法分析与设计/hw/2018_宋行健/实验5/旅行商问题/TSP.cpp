#include <iostream>
#include <cstring>
#include <math.h>
#define NoEdge -1
#define N 200      // 可执行的最大的顶点个数
using namespace std;
int n;                   // 图的顶点个数
int adjMatrix[N][N];     // 图的邻接矩阵
int x[N];                // 当前解
int bestX[N];            // 当前最优解
int bestC;               // 当前最优值
int cc;                  // 当前费用，形成环的时候与bestC比较看能不能更新bestC

/*****************************************************************
* 函数描述： 数据输入以及内存的初始化
*****************************************************************/
void input()
{
    cin >> n;   // 输入顶点个数
    int k;
    memset(adjMatrix, NoEdge, sizeof(adjMatrix));   // 邻接矩阵的内存初始化
    cin >> k;   // 输入边的个数;
    int p, q, len;
    // 初始化邻接矩阵
    for (int i = 1; i <= k; ++i)
    {
        cin >> p >> q >> len;
        adjMatrix[p][q] = len;
        adjMatrix[q][p] = len;
    }
    // 初始化最优解和当前解
    for (int i = 1; i <= n; ++i)
    {
        bestX[i] = i;
        x[i] = i;
    }
    bestC = NoEdge;
    cc = 0;
}

/*****************************************************************
* 函数描述： 格式化打印结果
*****************************************************************/
void printTravel()
{
    cout << "\n===================\n最短路径为：" << bestC << endl;
    for (int i = 1; i <= n; i++)
        cout << bestX[i] << " ---> ";
    cout << bestX[1];
}

/*****************************************************************
* 函数描述： 回溯递归函数，进行深度优先搜索
* 参数描述： i——递归到第i层
*****************************************************************/
void Traveling(int i)
{
    // 访问到第n个节点，判断是否形成回路
    if (i == n)
    {
        // 形成回路：x[n-1]与x[n]连通，且x[n]与x[1]连通
        if (adjMatrix[x[n - 1]][x[n]] != NoEdge && adjMatrix[x[n]][1] != NoEdge)
        {
            // 如果当前值优于最优值，更新最优值和最优解。或初始化最优解
            if (cc + adjMatrix[x[n - 1]][x[n]] + adjMatrix[x[n]][1] < bestC || bestC == NoEdge)
            {
                for (int k = 2; k <= n; ++k)
                    bestX[k] = x[k];
                bestC = cc + adjMatrix[x[n - 1]][x[n]] + adjMatrix[x[n]][1]; //更新最优值
            }
        }
        return;
    }
    // 当前在第i层，需要继续寻找
    else
    {
        for (int j = i; j <= n; ++j)
        {
            // 判断是否可以进入x[j]子树，
            // x[i-1]与x[j]连通使得1-i层连成一条路径且累计花费优于目前最优值，
            // 如果可以，则交换x[i]与x[j],进入i+1层，
            // 现在的解是x[1],x[2]...x[i]...x[j]...x[n]
            if (adjMatrix[x[i - 1]][x[j]] != NoEdge && cc + adjMatrix[x[i - 1]][x[j]] < bestC || bestC == NoEdge)
            {
                swap(x[i], x[j]);                // 交换之后，现在的解是x[1],x[2]...x[j]...x[i]...x[n]
                cc += adjMatrix[x[i - 1]][x[i]]; // 更新路径的长度，进入i+1层
                Traveling(i + 1);
                cc -= adjMatrix[x[i - 1]][x[i]]; // 还原路径的长度，比较x[j+1]子树
                swap(x[i], x[j]);                // 还原之前的解，现在的解是x[1],x[2]...x[i]...x[j]...x[n]
            }
        }
    }
    return;
}

int main()
{
    input();
    Traveling(2); // 出发点已知
    printTravel();
}

/*
4
6
1 2 30
1 3 6
1 4 4
2 3 5
2 4 10
3 4 20
*/
