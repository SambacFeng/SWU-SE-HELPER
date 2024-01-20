
#include "backtrack.h"
#include<iostream>
using namespace std;

BackTrack::BackTrack() {}
	
BackTrack::BackTrack(const Application& thisApp)
{
	this->app = thisApp;
}

bool BackTrack::backTrack(const Position& currPos)
{
	
	app.progress(currPos);
	if (app.success(currPos)) {
		/*eturn true;*/

		app.print(); //每次成功都打印一次
		cout << endl;
		globalcount++; //方法种数加1
		app.goBack(currPos); //继续回溯
		return false;//当作没有找到，返回false
	}
	else
	{
		Application::Iterator itr(currPos);

		Position nextPos;

		while (!itr.noNextPosition())
		{
			nextPos = itr.getNextPosition();
			//cout << "尝试位置：" << nextPos.getRow() << "，" << nextPos.getColumn() << endl;
			
			//先看下一位置是否有效，若有效进入下一层，若无效进行下一次迭代
			if (app.isValid(nextPos) && backTrack(nextPos)) {//recursive call if valid
				return true;
			}
			
		}
		//cannot reach goal from currPos
		app.goBack(currPos); //backtrack
		return false; //from currPos, no solution
	}
}