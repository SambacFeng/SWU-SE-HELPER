//#include<iostream>
//
//using namespace std;
//int num = 0;
//void print(int qp[8][8]);
//bool isValid(int qp[8][8], int r, int c) {
//	// 判断一列上有无皇后
//	for (int i = 0; i < 8; i++) {
//		if (i == r) continue;
//		else if (qp[i][c] == 1)return false;
//	}
//
//	//判断左对角
//	int j = c - 1;
//	for (int i = r - 1; i >= 0 && j >= 0; i--) {
//		if (qp[i][j] == 1) return false;
//		j--;
//
//	}
//	j = c + 1;
//	for (int i = r + 1; i < 8 && j < 8; i++) {
//		if (qp[i][j] == 1) return false;
//		j++;
//	}
//
//	//判断右对角
//	j = c + 1;
//	for (int i = r - 1; i >= 0 && j < 8; i--) {
//		if (qp[i][j] == 1) return false;
//		j++;
//	}
//	j = c - 1;
//	for (int i = r + 1; i < 8 && j >= 0; i++) {
//		if (qp[i][j] == 1) return false;
//		j--;
//	}
//	return true;
//}
////深搜函数
//void backTrack(int qp[8][8], int n) {
//	//如果第九行就结束，表示8个皇后已经安放完毕
//	if (n == 8) {
//		cout<<++num <<":"<<endl;
//		print(qp);
//		cout<<"------------------------"<<endl;
//		return;
//	}
//	else {
//		for (int j = 0; j < 8; j++) {
//			if (isValid(qp, n, j)) {
//				qp[n][j] = 1;  //放皇后
//				backTrack(qp, n + 1); //递归
//				qp[n][j] = 0;//回溯，把皇后拿掉
//			}
//		}
//	}
//
//}
//	//输出棋盘
//void print(int qp[8][8]) {
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 8; j++) {
//			if (qp[i][j] == 1) cout<<'q';
//			else cout<<'0';
//		}
//		cout << endl;
//	}
//}
//int  main() {
//	int a[8][8]{ 0 };
//	backTrack(a, 0);//深搜开始
//	cout<<"total:" <<num<<endl;
//	return 0;
//}
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#define inf 0x3f3f3f3f
#define modd 1000000007
using namespace std;
typedef long long ll;
ll quick_mod(ll a, ll b, ll c) {
    ll A = 1; // 结果的保存，就是 An，初始化一下
    ll T = a % c; //首先计算 T0 的值，用于 Tn 的递推
    while (b != 0) {
        if (b & 1) {
            A = (A * T) % c;
        }
        b >>= 1;
        T = (T * T) % c; // 更新 T，如果下一位是 1 就可以用这个算 A
    }
    return A;
}
ll max(ll a, ll b)
{
    if (a > b) return a;
    return b;
}
int a[770][770] = { 0 };

int main()
{
    int n, k;

    scanf_s("%d%d", &n, &k);
    int i, j, l, q;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            scanf_s("%d", &a[i][j]);
        }
    }
    ll maxx = -inf;

    ll tot = (k + 1) * k / 2;
    for (i = k; i <= n - k + 1; i++)
    {
        for (j = 1; j <= i - k + 1; j++)
        {
            ll tem = 0;
            int num = 0;
            for (l = i - k + 1; l <= i; l++)
            {
                num++;
                for (q = j; q <= j + num - 1; q++)
                {
                    tem += a[l][q];
                }
            }
            maxx = max(tem / tot, maxx);
            tem = 0;
            num = k + 1;;
            for (l = i; l <= i + k - 1; l++)
            {
                num--;
                for (q = j + k - 1; q >= j + k - num; q--)
                {
                    tem += a[l][q];
                }
            }
            maxx = max(tem / tot, maxx);
            tem = 0;
        }
    }
    for (i = n - k + 2; i <= n; i++)
    {
        for (j = 1; j <= i - k + 1; j++)
        {
            ll tem = 0;
            int num = 0;
            for (l = i - k + 1; l <= i; l++)
            {
                num++;
                for (q = j; q <= j + num - 1; q++)
                {
                    tem += a[l][q];
                }
            }
            maxx = max(tem / tot, maxx);

            tem = 0;
        }
    }
    cout<<maxx;
    return 0;
}