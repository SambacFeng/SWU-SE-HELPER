#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <string.h>
using namespace std;

/*****************************************************************
* 函数描述： 构造矩阵（n阶方阵）
* 函数参数： n——矩阵行数
			m——矩阵列数
* 函数返回： 构造的矩阵指针
*****************************************************************/
int **GenerateMatrix(int n, int m)
{
    int **s = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
    {
        s[i] = (int *)malloc(sizeof(int) * m);
        memset(s[i], 0, sizeof(int) * m);
    }
    return s;
}

/*****************************************************************
* 函数描述： 释放内存（n阶方阵）
* 函数参数： p——需要被释放内存的矩阵
			n——阶数
* 函数返回： void
*****************************************************************/
void FreeMatrix(int **p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        free(p[i]);
    }
    free(p);
}

/*****************************************************************
* 函数描述： 打印矩阵（不打印0索引）
* 函数参数： p——被打印矩阵
			n——行数
			m——列数
* 函数返回： void
*****************************************************************/
void PrintMatrix(int **p, int n, int m)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            cout << setw(7) << p[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/*****************************************************************
* 函数描述： 矩阵乘法 a*b=c
* 函数参数： a——矩阵a
			b——矩阵b
			c——结果矩阵c
			ra——矩阵a的行数
			ca——矩阵a的列数
			rb——矩阵b的行数
            ca——矩阵b的列数
* 函数返回： void
*****************************************************************/
void MatrixMultiply(int **a, int **b, int **c, int ra, int ca, int rb, int cb)
{
    if (ca != rb) // 如果不满足矩阵乘法规则（左列数=右行数），则返回
    {
        cout << "Matrix multiplication error." << endl;
        return;
    }
    // 矩阵乘法
    for (int i = 0; i < ra; ++i)
    {
        for (int j = 0; j < cb; ++j)
        {
            int tmp = 0;
            for (int k = 0; k < ca; ++k)
            {
                tmp += a[i][k] * b[k][j];
            }
            c[i][j] = tmp;
        }
    }
}

/*****************************************************************
* 函数描述： 矩阵连乘核心算法
* 函数参数： p——连乘矩阵行列值数组
			n——连乘矩阵的个数
			m——储存分步最优值数组
			s——储存分步最优解，最优值断开的位置
* 函数返回： 最优值
*****************************************************************/
int MatrixChain(int *p, int n, int **m, int **s)
{
    int i, j;
    //对角线上的元素都设置成0
    for (i = 1; i <= n; ++i)
        m[i][i] = 0;
    for (int len = 2; len <= n; ++len)
    { // 遍历连乘长度，从2开始，子问题规模
        for (i = 1; i <= n - len + 1; ++i)
        {
            j = i + len - 1;
            // 将链ij划分为A(i) * ( A[i+1:j] )
            m[i][j] = 0 + m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; ++k)
            { // 将链ij划分为( A[i:k] ) * ( A[k+1:j] )
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > t)
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
        PrintMatrix(m, n + 1, n + 1);
    }
    return m[1][n]; // 返回最优值
}

/*****************************************************************
* 函数描述： 递归求最优解
* 函数参数： s——最优解断开位置矩阵
			i——连乘矩阵链起始位置
			j——连乘矩阵链终止位置
* 函数返回： void
*****************************************************************/
void Traceback(int **s, int i, int j)
{
    if (i == j)
        return;
    Traceback(s, i, s[i][j]);
    Traceback(s, s[i][j] + 1, j);
    cout << "Matrix A" << i << "," << s[i][j] << " and A" << s[i][j] + 1 << "," << j << endl;
}

int main()
{
    // 连乘的矩阵个数
    const int n = 6;
    // n个矩阵连乘，行列顺序。30*35 35*15 15*5 5*10 10*20 20*25
    int p[n + 1] = {30, 35, 15, 5, 10, 20, 25};
    int **m = GenerateMatrix(n + 1, n + 1);
    int **s = GenerateMatrix(n + 1, n + 1);
    int min = MatrixChain(p, n, m, s);
    cout << "Min: " << min << endl;
    PrintMatrix(m, n + 1, n + 1); // 打印储存最优值的矩阵
    PrintMatrix(s, n + 1, n + 1); // 打印储存最优解的矩阵
    Traceback(s, 1, n);           // 打印最优解
    return 0;
}