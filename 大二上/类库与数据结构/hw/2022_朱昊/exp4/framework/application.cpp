#include "application.h"
#include <iostream>
using namespace std;

#define NULL 0

//board
int maze[8][13] = { {1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1} ,
					{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1} ,
					{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1} ,
					{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1} ,
					{1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1} ,
					{1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0} ,
					{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

void Application::initialize() {}

Position Application::getStartPosition()
{
	return Position(0, 0);
}

bool Application::isValid(const Position& p)
{
	int row = p.getRow();
	int column = p.getColumn();
	return (row >= 0 && row <= 7) && (column >= 0 && column <= 12) && maze[row][column] == 1;
}

void Application::progress(const Position& p)
{
	maze[p.getRow()][p.getColumn()] = 9;
}

bool Application::success(const Position& p)
{
	return p.getRow() == 7 && p.getColumn() == 12;
}

void Application::goBack(const Position& p)
{

	maze[p.getRow()][p.getColumn()] = 1;
}

void Application::print()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 13; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}



//======================================================================
struct itrPosition
{
	int row;
	int column;
	int turn;
};

//application iterator
Application::Iterator::Iterator()
{
	currItrPosPtr = NULL;
}

Application::Iterator::Iterator(const Position& currPos)
{
	itrPosition* p = new itrPosition;
	p->row = currPos.getRow();
	p->column = currPos.getColumn();
	p->turn = 0;
	currItrPosPtr = p;
}

Position Application::Iterator::getNextPosition()
{
	int row = ((itrPosition *)currItrPosPtr)->row;
	int column = ((itrPosition *)currItrPosPtr)->column;
	int turn = ((itrPosition*)currItrPosPtr)->turn;
	if (turn == 0)
	{
		column++;
		turn++;
	}
	else if (turn == 1)
	{
		row++;
		turn++;
	}
	else if (turn == 2)
	{
		column--;
		turn++;
	}
	else if (turn == 3)
	{
		row--;
		turn++;
	}
	else
	{
	}
	((itrPosition*)currItrPosPtr)->turn = turn;
	return Position(row, column); //return the new position
}

bool Application::Iterator::noNextPosition()
{
	return ((itrPosition *)currItrPosPtr)->turn > 3;
}

Application::Iterator::~Iterator()
{
	delete (itrPosition*)currItrPosPtr;
}