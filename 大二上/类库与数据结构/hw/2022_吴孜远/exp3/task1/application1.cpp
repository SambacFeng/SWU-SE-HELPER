#include "application.h"
#include <iostream>

using namespace std;

#define NULL 0

//board
int maze[8][8] = {  {0, 0, 0, 0, 0, 0, 0, 0,} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} };

void Application::initialize() {}

Position Application::getStartPosition()
{
	return Position(0, 0);
}

bool Application::isValid(const Position& p)
{
	int row = p.getRow();
	int column = p.getColumn();
	int newrow = p.getRow();
	int newcolumn = p.getColumn();
	int min = 0;
	//新加的：
	bool noqueenrow= true;
	bool noqueencolumn = true;
	bool noqueenoblique = true;
	for (int i = 0; i < 8; i++ ) {
		if (maze[i][p.getColumn()] == 1) {
			noqueenrow = false;
		}
		if (maze[p.getRow()][i] == 1) {
			noqueencolumn = false;
		}
	}
	//主斜线
	while( newrow < 7 && newcolumn < 7 ) {
		newrow++;
		newcolumn++;
	}
	if (newrow < newcolumn) {
		min = newrow;
	}
	else {
		min = newcolumn;
	}
	for (int i = 0; i< min+1; i++) {
		if (maze[newrow - i][newcolumn - i] == 1) {
			noqueenoblique = false;
			break;
		}
	}
	//副斜线
	//重新等于p的位置
	newrow = p.getRow();
	newcolumn = p.getColumn();
	while (newrow < 7 && newcolumn < 7) {
		newrow--;
		newcolumn++;
	}
	min = newcolumn - newrow;
	for (int i = 0; i < min+1; i++) {
		if (maze[newrow + i][newcolumn - i] == 1) {
			noqueenoblique = false;
			break;
		}
	}
	/*return (row >= 0 && row <= 7) && (column >= 0 && column <= 12) && maze[row][column] == 1;*/
	return (row >= 0 && row <= 7) && (column >= 0 && column <= 7) && maze[row][column] == 0 && noqueenrow == true && noqueencolumn == true && noqueenoblique == true;
			
	
}

void Application::progress(const Position& p)//让走过的地方发生改变, 皇后问题就是让这个点为皇后（1）
{
	maze[p.getRow()][p.getColumn()] = 1;
}

bool Application::success(const Position& p)//判断是否成功
{
	int queennum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == 1) {
				queennum++;
			}
		}
	}
	/*return p.getRow() == 7 && p.getColumn() == 12;*/
	return queennum == 8;
}

void Application::goBack(const Position& p) //修改该位置的值
{

	/*maze[p.getRow()][p.getColumn()] = 1;*/
	maze[p.getRow()][p.getColumn()] = 0;
}

void Application::print()
{
	for (int i = 0; i < 8; i++)
	{
		/*for (int j = 0; j < 13; j++)*/
		for (int j = 0; j < 8; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}



//======================================================================
struct itrPosition
{
	int row;
	int column;
	//int turn;//方向
	int count;
};

//application iterator
Application::Iterator::Iterator()
{
	currItrPosPtr = NULL;
}

Application::Iterator::Iterator(const Position& currPos)//把参数的位置和初始方向0给空指针
{
	itrPosition* p = new itrPosition;
	p->row = currPos.getRow();
	p->column = currPos.getColumn();
	/*p->turn = 0;*/
	p->count = 0;
	currItrPosPtr = p;
}

Position Application::Iterator::getNextPosition()//根据函数体里的计算，返回下一个对应方向的位置，没调用一次，方向就会+1
{
	int row = ((itrPosition*)currItrPosPtr)->row;
	int column = ((itrPosition*)currItrPosPtr)->column;
	/*int turn = ((itrPosition*)currItrPosPtr)->turn;*/
	int count = ((itrPosition*)currItrPosPtr)->count;
	//if (turn == 0)//向右走
	//{
	//	column++;
	//	turn++;
	//}
	//else if (turn == 1)//向下走
	//{
	//	row++;
	//	turn++;
	//}
	//else if (turn == 2)//向左走
	//{
	//	column--;
	//	turn++;
	//}
	//else if (turn == 3)//向上走
	//{
	//	row--;
	//	turn++;
	//}
	//else
	//{
	//}
	if (count < 8) {
		column++;
		row = count;
		count++;
	}
	((itrPosition*)currItrPosPtr)->count = count;
	return Position(row, column); //return the new position，返回新位置
}

bool Application::Iterator::noNextPosition()
{
	return ((itrPosition*)currItrPosPtr)->count > 7;
}

Application::Iterator::~Iterator()
{
	delete (itrPosition*)currItrPosPtr;
}