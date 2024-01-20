#include "application.h"
#include <iostream>
using namespace std;

#define NULL 0

//board
int maze[8][8] = {  {0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0} };

void Application::initialize() {}

//从第一行从第一个开始依次往后尝试,这样只能找出来第一个皇后放在(0,0)的情况
Position Application::getStartPosition() 
{
	//return Position(0, 0);
	static int c = 0; //静态变量，只有第一次调用会初始化
	return Position(0, c++); //每一次调用此函数都能让c加1，也就是不断挪初始位置
}

bool Application::isValid(const Position& p) //只有为0才有效
{
	int row = p.getRow();
	int column = p.getColumn();
	//不超出范围，且值为0，才可以放置
	return (row >= 0 && row <= 7) && (column >= 0 && column <= 7) && (maze[row][column] == 0);
}

void Application::progress(const Position& p) //每放一个皇后，标记自己为9，行列斜为当前皇后所在行数
{
	//检测是否为0，若是0，则改为当前行数的值，如第二行的皇后就全改为2，第三行的皇后就全改为为3
	//若不是0，那就不变，因为已经被其他皇后控制了
	//行列控制：
	for (int i = 0; i <= 7; i++) {
		if (maze[p.getRow()][i] == 0) {
			maze[p.getRow()][i] = p.getRow() + 1; //行占有
		}
	}

	for (int i = 0; i <= 7; i++) {
		if (maze[i][p.getColumn()] == 0) {
			maze[i][p.getColumn()] = p.getRow() + 1; //列占有
		}
	}
	//斜线控制
	//主对角线
	int row, column;//找到起点
	//主对角线占有
	if (p.getRow() > p.getColumn()) {
		row = p.getRow() - p.getColumn();
		column = p.getColumn() - p.getColumn();
	}
	else {
		row = p.getRow() - p.getRow();
		column = p.getColumn() - p.getRow();
	}
	while (row <= 7 && column <= 7) { //任何一边到边界都算是结束
		if (maze[row][column] == 0) {
			maze[row][column] = p.getRow()+1;
		}
		row++;
		column++;
	}

	//副对角线
	if ((p.getRow() + p.getColumn()) <= 3) {
		row = p.getRow() - p.getRow();
		column = p.getColumn() + p.getRow();
	}
	else {
		row = p.getRow() - (7 - p.getColumn());
		column = 7;
	}
	
	while (row <= 7 && column >= 0) {
		if (maze[row][column] == 0) {
			maze[row][column] = p.getRow() + 1;
		}
		row++;
		column--;
	}
	maze[p.getRow()][p.getColumn()] = 9;//皇后所在位置标记为9
}

bool Application::success(const Position& p)
{
	if (p.getRow() == 7) { //若当前位置为第七行，那说明这个地方已经放下了皇后，也就是成功了
		return true; 
	}
	else {
		return false;
	}
	/*int queennum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == 9) {
				queennum++;
			}
		}
	}
	return queennum == 8;*/
}

//返回时将此时尝试的pos标记为0,还要将当前皇后占有的格数撤回，全部遍历一遍，等于当前行数的全部改成0
void Application::goBack(const Position& p) 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == p.getRow()+1) {
				maze[i][j] = 0;
			}
		}
	}
	maze[p.getRow()][p.getColumn()] = 0;
}

void Application::print() //打印
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] != 9) { //避免修改maze本身，因为之后每找出一次结果都要print，防止回溯时maze被修改了
				cout << 0 << " ";
			}
			else {
				cout << maze[i][j] << " ";
			}
			
		}
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
	currItrPosPtr = NULL; //将无类型指针指向空
}

Application::Iterator::Iterator(const Position& currPos) //以行为单位，所以让迭代器指向这一行
{
	itrPosition* p = new itrPosition;
	p->row = currPos.getRow(); 
	p->column = 0;
	p->turn = 0;
	currItrPosPtr = p; //将无类型指针指向迭代器，此时的类型为itrPosition*
}

Position Application::Iterator::getNextPosition() //这里要改成按照行进行遍历
{
	int row = ((itrPosition*)currItrPosPtr)->row;
	int column = ((itrPosition*)currItrPosPtr)->column;
	int turn = ((itrPosition*)currItrPosPtr)->turn;
	//int turn = ((itrPosition*)currItrPosPtr)->turn;
	row++; //转到下一行，但不存到迭代器中，这样就能每次迭代都在下一行
	column = turn; //计数器记录列数
	turn++; //计数器加1
	((itrPosition*)currItrPosPtr)->turn = turn; //计数器的值每次都要更新
	((itrPosition*)currItrPosPtr)->column = column; //列数更新
	return Position(row, column); //return the new position

}

bool Application::Iterator::noNextPosition() //当前行尝试完毕
{
	return ((itrPosition *)currItrPosPtr)->turn > 7;
}

Application::Iterator::~Iterator()
{
	delete (itrPosition*)currItrPosPtr;
}