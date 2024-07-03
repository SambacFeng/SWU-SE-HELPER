#include "position.h"

Position::Position()
{
	row = 0;
	column = 0;
}

Position::Position(int thisRow, int thisCol)
{
	row = thisRow;
	column = thisCol;
}

int Position::getRow() const 
{
	return row;
}

int Position::getColumn() const 
{
	return column;
}