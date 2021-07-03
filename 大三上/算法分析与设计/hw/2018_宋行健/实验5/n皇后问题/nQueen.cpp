#include <iostream>
#include <iomanip>
#define N 8		// N 为皇后个数
using namespace std;
int num = 0;


/*****************************************************************
* 函数描述： 输出棋盘
* 参数描述： Chess[N][N]——棋盘数组
*****************************************************************/
void printChessboard(int Chess[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Chess[i][j] == 1)
				cout << setw(2) << 'q';
			else
				cout << setw(2) << '_';
		}
		cout << endl;
	}
}

/*****************************************************************
* 函数描述： 判定是否满足放皇后的规则
* 参数描述： Chess[N][N]——棋盘数组
*    		r——行数
* 			c——列数
* 返回值：布尔类型，是否满足放皇后的规则
*****************************************************************/
bool isValid(int Chess[N][N], int r, int c)
{
	// 判断一列上有无皇后
	for (int i = 0; i < N; i++)
	{
		if (i == r)
			continue;
		else if (Chess[i][c] == 1)
			return false;
	}

	//判断左对角
	int j = c - 1;
	for (int i = r - 1; i >= 0 && j >= 0; i--)
	{
		if (Chess[i][j] == 1)
			return false;
		j--;
	}
	j = c + 1;
	for (int i = r + 1; i < N && j < N; i++)
	{
		if (Chess[i][j] == 1)
			return false;
		j++;
	}

	//判断右对角
	j = c + 1;
	for (int i = r - 1; i >= 0 && j < N; i--)
	{
		if (Chess[i][j] == 1)
			return false;
		j++;
	}
	j = c - 1;
	for (int i = r + 1; i < N && j >= 0; i++)
	{
		if (Chess[i][j] == 1)
			return false;
		j--;
	}
	return true;
}

/*****************************************************************
* 函数描述： 回溯递归函数，进行深度优先搜索
* 参数描述： Chess[N][N]——棋盘数组
*    		n——递归到第n层
*****************************************************************/
void backTrack(int Chess[N][N], int n)
{
	//如果第(N+1)行就结束，表示N个皇后已经安放完毕
	if (n == N)
	{
		cout << ++num << ":" << endl;
		printChessboard(Chess);
		cout << "--------------------------" << endl;
		return;
	}
	else
	{
		for (int j = 0; j < N; j++)
		{
			if (isValid(Chess, n, j))
			{
				Chess[n][j] = 1;		  //放皇后
				backTrack(Chess, n + 1); //递归
				Chess[n][j] = 0;		  //回溯，把皇后拿掉
			}
		}
	}
}

int main()
{
	int a[N][N]{0};
	backTrack(a, 0); // 回溯
	cout << "\nTotal:" << num << endl;
	return 0;
}
