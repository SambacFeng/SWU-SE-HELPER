#include <iostream>

using namespace std;

int board[8][8]{ 0 };
int counts = 0;

void printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << board[i][j] << ' ';
		cout << endl;
	}
}

bool check(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int invalidCol;
		for (int j = 0; j < 8; j++)
			if (board[i][j])
				invalidCol = j;
		if (col == invalidCol)
			return false;
		if ((i + invalidCol) == (row + col))
			return false;
		if ((i - invalidCol) == (row - col))
			return false;
	}
	return true;
}

void goBack(int row)
{
	for (int i = 0; i < 8; i++)
		board[row][i] = 0;
	return;
}

bool backTrack(int row)
{
	for (int col = 0; col < 8; col++)
		if (check(row, col))
		{
			board[row][col] = 1;
			if (row == 7)
			{
				cout << "Possible results " << ++counts << endl;
				printBoard();
				cout << endl;
				//exit(0);
				goBack(row);
				return true;
			}
			backTrack(row + 1);
			goBack(row);
		}
}

int main()
{
	backTrack(0);

	return 0;
}
