// maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

using namespace std;

int maze[8][13] = { {1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1} ,
					{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1} ,
					{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1} ,
					{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1} ,
					{1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1} ,
					{1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0} ,
					{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

void printMaze()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 13; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}

bool isValidNextUp(int row, int column)
{
	//not path position, not end position and not boundary position
	int tempR = row - 1;
	return (tempR >= 0 && maze[tempR][column] == 1);
}

bool isValidNextRight(int row, int column)
{
	//not path position, not end position and not boundary 
	int tempC = column + 1;
	return (tempC <= 12 && maze[row][tempC] == 1);
}

bool isValidNextDown(int row, int column)
{
	//not path position, not end position and not boundary position
	int tempR = row + 1;
	return (tempR <= 7 && maze[tempR][column] == 1);
}

bool isValidNextLeft(int row, int column)
{
	//not path position, not end position and not boundary position
	int tempC = column - 1;
	return (tempC >= 0 && maze[row][tempC] == 1);
}

void progress(int row, int column)
{
	maze[row][column] = 9; //path position
}

void goBack(int row, int column)
{
	//maze[row][column] = 2; //end position
	maze[row][column] = 1; //also work
}

bool success(int row, int column)
{
	return (row == 7 && column == 12);
}

bool backTrack(int row, int column)
{
	progress(row, column);

	if (success(row, column)) //reach goal
		return true;
	else //not goal
	{
		if (isValidNextUp(row, column) && backTrack(row - 1, column)) //recursive call
			return true; //from north position can reach goal
		else if (isValidNextRight(row, column) && backTrack(row, column + 1)) 
			return true;
		else if (isValidNextDown(row, column) && backTrack(row + 1, column))
			return true;
		else if (isValidNextLeft(row, column) && backTrack(row, column - 1))
			return true;
		else //cannot reach goal from current (row, column)
		{
			goBack(row, column); //lead to end position
			return false;
		}
	}
}

int main()
{	
	if (backTrack(0, 0))
		printMaze();
	else
		cout << "No path exists!\n";
	return 0;
}