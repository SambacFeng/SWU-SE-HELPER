#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
string exchange(int number);			//将计数变量转化为字符串；

int main()
{
	ifstream in;			//读入文件流；
	ofstream out;			//写入文件流；
	int number=1;			//第几回的计数变量；
	string name;			//文件名称：第几回；
	string line;			//读入文件流，每次读一行，储存变量；
	string location;			//文件地址名称；
	char *loc;			//文件地址名称字符串首位指针；

	in.open("E:\\C++\\射雕英雄传.txt");			//打开要读入的文件；
	out.open("E:\\C++\\射雕英雄传out\\前言.txt");			//打开前言；

	if (!in)
		cout << "Open failed(in)" << endl;			//检验原文件是否打开成功；
	
	else 
	{
		name = exchange(number);			//将计数变量转化为字符串——“第几回”；
		while (getline(in, line))			//当in成行读入有数据，则将读入的数据存入line；
		{
			if (!line.find(name))			//如果line中含有“第几回”关键字，则新建文件；
			{
				out.close();					//关闭上一个文件；	
				cout << name << endl;			//监视复制过程；
				location = "E:\\C++\\射雕英雄传out\\" + name + ".txt";			//location来存文件的完整地址的字符串；
				loc = &location[0];			//loc来存文件的完整地址字符串的内存地址；
		
				out.open(loc);			//打开新文件；
				if (!out)
				{
					cout << "Open failed(out)" << endl;			//检查文件是否创建成功,若不成功则跳出循环；
					break;
				}
				number++;			//计数变量加一；
				name = exchange(number);				//将计数变量转化为字符串——“第几回”；			
			}
			out << line << endl;			//一行一行将数据写入文件；
		}
		cout << endl;
		cout << "FINISH!!!" << endl;			//复制完成提示；
	}

	out.close();			//关闭打开的所有文件；
	in.close();

	return 0;
}

string exchange(int number)			//将计数变量转化为字符串；
{
	string name;			//第几回；
	int number_1;			//计数变量的十位；
	int number_2;			//计数变量的个位；
	number_1 = number / 10;
	number_2 = number % 10;
	
	if (number_1 == 0)			//计数变量为个位数，十位为0；
	{
		switch (number_2)
		{
		case 1:name = "一"; break;
		case 2:name = "二"; break;
		case 3:name = "三"; break;
		case 4:name = "四"; break;
		case 5:name = "五"; break;
		case 6:name = "六"; break;
		case 7:name = "七"; break;
		case 8:name = "八"; break;
		case 9:name = "九"; break;
		}
	}
	else if (number_1 == 1)			//计数变量为10~19；
	{
		switch (number_2)
		{
		case 0:name = "十"; break;
		case 1:name = "十一"; break;
		case 2:name = "十二"; break;
		case 3:name = "十三"; break;
		case 4:name = "十四"; break;
		case 5:name = "十五"; break;
		case 6:name = "十六"; break;
		case 7:name = "十七"; break;
		case 8:name = "十八"; break;
		case 9:name = "十九"; break;
		}
	}
	else					//计数变量为20~99；
	{
		switch (number_1)			//先输出十位；
		{
		case 2:name = "二"; break;
		case 3:name = "三"; break;
		case 4:name = "四"; break;
		case 5:name = "五"; break;
		case 6:name = "六"; break;
		case 7:name = "七"; break;
		case 8:name = "八"; break;
		case 9:name = "九"; break;
		}

		switch (number_2)			//再输出个位；
		{
		case 0:name = name + "十"; break;
		case 1:name = name + "十一"; break;
		case 2:name = name + "十二"; break;
		case 3:name = name + "十三"; break;
		case 4:name = name + "十四"; break;
		case 5:name = name + "十五"; break;
		case 6:name = name + "十六"; break;
		case 7:name = name + "十七"; break;
		case 8:name = name + "十八"; break;
		case 9:name = name + "十九"; break;
		}
	}
	name = "第" + name + "回";			//完整名称，第几回；
	//cout << name << endl;

	return name;			//返回名称字符串；
}