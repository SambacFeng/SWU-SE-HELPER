#include <iostream>

int tile = 1;        // 骨牌序号
int board[128][128]; // 二维数组模拟棋盘

// (tr,tc)表示棋盘的左上角坐标(即确定棋盘位置), (dr,dc)表示特殊方块的位置, size=2^k确定棋盘大小
void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    // 递归出口
    if (size == 1)
        return;

    int s = size / 2; //分割棋盘
    int t = tile++;   //t记录本层骨牌序号
    // 判断特殊方格在不在左上棋盘
    if (dr < tr + s && dc < tc + s)
    {
        chessBoard(tr, tc, dr, dc, s); //特殊方格在左上棋盘的递归处理方法
    }
    else
    {
        board[tr + s - 1][tc + s - 1] = t;             // 用t号的L型骨牌覆盖右下角
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s); // 递归覆盖其余方格
    }

    // 判断特殊方格在不在右上棋盘
    if (dr < tr + s && dc >= tc + s)
    {
        chessBoard(tr, tc + s, dr, dc, s);
    }
    else
    {
        board[tr + s - 1][tc + s] = t;
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    // 判断特殊方格在不在左下棋盘
    if (dr >= tr + s && dc < tc + s)
    {
        chessBoard(tr + s, tc, dr, dc, s);
    }
    else
    {
        board[tr + s][tc + s - 1] = t;
        chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    // 判断特殊方格在不在右下棋盘
    if (dr >= tr + s && dc >= tc + s)
    {
        chessBoard(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        board[tr + s][tc + s] = t;
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main()
{
    int boardSize = 8;                 // 棋盘边长
    chessBoard(0, 0, 3, 3, boardSize); // (0, 0)为顶点，大小为boardSize的棋盘； 特殊方块位于(3, 3)

    // 打印棋盘
    int i, j;
    printf("\n\n\n");
    for (i = 0; i < boardSize; i++)
    { 
        for (j = 0; j < boardSize; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n\n\n");
    }
    return 0;
}
