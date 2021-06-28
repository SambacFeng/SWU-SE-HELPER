//#include <iostream>
//
//using namespace std;
//
//int board[8][8]{ 0 };
//int c = 0;
//
//void printBoard()
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//			cout << board[i][j] << ' ';
//		cout << endl;
//	}
//}
//
//bool checkRow(int row)
//{
//	for (int i = 0; i < 8; i++)
//		if (board[row][i])
//			return false;
//	return true;
//}
//
//bool checkCol(int col)
//{
//	for (int i = 0; i < 8; i++)
//		if (board[i][col])
//			return false;
//	return true;
//}
//
//bool checkDiag(int _row, int _col)
//{
//	int row = _row;
//	int col = _col;
//	while (col > -1 && row > -1)
//	{
//		if (board[row--][col--])
//			return false;
//	}
//	row = _row;
//	col = _col;
//	while (col < 8 && row < 8)
//	{
//		if (board[row++][col++])
//			return false;
//	}
//	return true;
//}
//
//bool checkBack(int _row, int _col)
//{
//	int row = _row;
//	int col = _col;
//	while (col > -1 && row > -1 && col < 8 && row < 8)
//	{
//		if (board[row--][col++])
//			return false;
//	}
//	row = _row;
//	col = _col;
//	while (col > -1 && row > -1 && col < 8 && row < 8)
//	{
//		if (board[row++][col--])
//			return false;
//	}
//}
//bool check(int row, int col)
//{
//	if (!board[row][col] && checkRow);
//}
//
//void putAQueen(int row, int col)
//{
//	board[row][col] = 1;
//}
//
//void goBack(int row, int col)
//{
//	board[row][col] = 0;
//}
//
//bool backTrack(int row, int col)
//{
//	if (c == 8)
//		return true;
//	else
//	{
//		if (check(row, col));
//	}
//}
//
//int main()
//{
//
//	return 0;
//}
