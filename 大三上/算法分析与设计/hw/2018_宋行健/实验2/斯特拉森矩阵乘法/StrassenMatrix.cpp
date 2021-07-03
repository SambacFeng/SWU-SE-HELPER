#include <iostream>
#define N 2

int res[N][N];
int A[N][N] = {1, 2, 3, 4};
int B[N][N] = {1, 2, 3, 4};

// 矩阵加法
void plus(int res[N / 2][N / 2], int A[N / 2][N / 2], int B[N / 2][N / 2])
{
    int i, j;
    for (i = 0; i < N / 2; i++)
    {
        for (j = 0; j < N / 2; j++)
        {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 矩阵减法
void minus(int res[N / 2][N / 2], int A[N / 2][N / 2], int B[N / 2][N / 2])
{
    int i, j;
    for (i = 0; i < N / 2; i++)
    {
        for (j = 0; j < N / 2; j++)
        {
            res[i][j] = A[i][j] - B[i][j];
        }
    }
}

// 矩阵乘法
void mul(int res[N / 2][N / 2], int A[N / 2][N / 2], int B[N / 2][N / 2])
{
    int i, j, k;
    for (i = 0; i < N / 2; i++)
    {
        for (j = 0; j < N / 2; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N / 2; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 斯特拉森矩阵乘法
void StrassenMatrix(int res[N][N], int A[N][N], int B[N][N])
{
    int i, j;
    int A11[N / 2][N / 2], A12[N / 2][N / 2], A21[N / 2][N / 2], A22[N / 2][N / 2];
    int B11[N / 2][N / 2], B12[N / 2][N / 2], B21[N / 2][N / 2], B22[N / 2][N / 2];
    int M1[N / 2][N / 2], M2[N / 2][N / 2], M3[N / 2][N / 2], M4[N / 2][N / 2],
        M5[N / 2][N / 2], M6[N / 2][N / 2], M7[N / 2][N / 2];
    int temp1[N / 2][N / 2], temp2[N / 2][N / 2];
    int C11[N / 2][N / 2], C12[N / 2][N / 2], C21[N / 2][N / 2], C22[N / 2][N / 2];

    // 分割矩阵，A11 A12 A21 A22 B11 B12 B21 B22
    for (i = 0; i < N / 2; i++)
    {
        for (j = 0; j < N / 2; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + N / 2];
            A21[i][j] = A[i + N / 2][j];
            A22[i][j] = A[i + N / 2][j + N / 2];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + N / 2];
            B21[i][j] = B[i + N / 2][j];
            B22[i][j] = B[i + N / 2][j + N / 2];
        }
    }

    //M1 = (A11 - A22) * (B21 + B22)
    minus(temp1, A12, A22);
    plus(temp2, B21, B22);
    mul(M1, temp1, temp2);

    //M2 = (A11 + A22) * (B11 + B22)
    plus(temp1, A11, A22);
    plus(temp2, B11, B22);
    mul(M2, temp1, temp2);

    //M3 = (A21 - A11) * (B11 + B12)
    minus(temp1, A21, A11);
    plus(temp2, B11, B12);
    mul(M3, temp1, temp2);

    //M4 = (A11 + A22) * B22
    plus(temp1, A11, A12);
    mul(M4, temp1, B22);

    //M5 = A11 * (B12 - B22)
    minus(temp1, B12, B22);
    mul(M5, A11, temp1);

    //M6 = A22 * (B21 - B11)
    minus(temp1, B21, B11);
    mul(M6, A22, temp1);

    //M7 = (A21 + A22) * B11
    plus(temp1, A21, A22);
    mul(M7, temp1, B11);

    //C11 = M1 + M2 + M6 - M4
    plus(temp1, M1, M2);
    plus(temp2, temp1, M6);
    minus(C11, temp2, M4);

    //C12 = M4 + M5
    plus(C12, M4, M5);

    //C21 = M6 + M7
    plus(C21, M6, M7);

    //C22 = M2 + M3 + M5 - M7
    plus(temp1, M2, M3);
    plus(temp2, temp1, M5);
    minus(C22, temp2, M7);

    for (i = 0; i < N / 2; i++)
    {
        for (j = 0; j < N / 2; j++)
        {
            res[i][j] = C11[i][j];
            res[i][j + N / 2] = C12[i][j];
            res[i + N / 2][j] = C21[i][j];
            res[i + N / 2][j + N / 2] = C22[i][j];
        }
    }
}

// 递归斯特拉森矩阵乘法
void RecursionStrassenMatrix(int size){
    if(size!=2){
        StrassenMatrix(res, A, B);
    }
}

// 普通矩阵乘法
void OrdinaryMatrix(int res[N][N], int A[N][N], int B[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 打印矩阵
void printMatrix(int m[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    printf("\nStrassen matrix multiplication:\n");
    StrassenMatrix(res, A, B);
    printMatrix(res);

    printf("\nOrdinary matrix multiplication:\n");
    OrdinaryMatrix(res, A, B);
    printMatrix(res);

    return 0;
}