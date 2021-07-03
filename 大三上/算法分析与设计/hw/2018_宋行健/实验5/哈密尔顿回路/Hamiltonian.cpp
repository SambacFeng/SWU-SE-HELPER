#include <iostream>
#include <cstring>
using namespace std;
const int MAX_V = 50;

void print(int path[], int V)
{
    cout << "存在哈密顿回路" << endl;
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}

//path记录路径，visited记录顶点是否访问过，len记录当前路径的长度
bool hamCycle(int graph[][MAX_V], int V, int path[], bool visited[], int current)
{
    if (current == V)
    { //访问到最后一个顶点
        if (graph[path[current - 1]][0] == 1)
            return true; //有到0点的边
        else
            return false;
    }
    //遍历起点外其它顶点
    for (int v = 1; v < V; v++)
    {
        //如果没访问过，并且有边相连
        if (!visited[v] && graph[path[current - 1]][v] == 1)
        {
            visited[v] = true;
            path[current] = v;
            //当本次递归的child也为true时返回true
            if (hamCycle(graph, V, path, visited, current + 1))
                return true;
            //当本条递归线路失败时恢复原图
            path[current] = -1;
            visited[v] = false;
        }
    }
    return false;
}

//从起点开始引导
bool hamCycleStart(int graph[][MAX_V], int V)
{
    int path[MAX_V];
    memset(path, -1, sizeof(path));
    bool visited[MAX_V] = {0};
    path[0] = 0;
    visited[V] = true; //把起点标记为访问过
    //起点已确定，current从1开始
    if (hamCycle(graph, V, path, visited, 1) == false)
    {
        cout << "哈密顿回路不存在" << endl;
        return false;
    }
    print(path, V);
    return true;
}

int main()
{
    int graph[MAX_V][MAX_V];
    int V;
    cout << "请输入点的个数：" << endl;
    cin >> V;
    for (int i = 0; i < V; ++i)
    {
        cout << "请输入图的第" << i << "行" << endl;
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }
    hamCycleStart(graph, V);
    return 0;
}