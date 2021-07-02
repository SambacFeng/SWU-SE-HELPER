#include "washCmp.h"
#include <iostream>
#include <time.h>
#include <math.h>


const int WashCmp::CAPACITY = 9999999;	//队列长度无限
const double WashCmp::LAMTA = 1.0 / 20.0;	//关于车辆到达相隔时间的参数


WashCmp::WashCmp()
{
	totalWaitingTime = 0.0;
	numServedCars = 0.0;
}

void WashCmp::simulation()
{
	double TIME = 0.0;	//模拟总时间轴
	double arrivalTime = getNextArrival(&TIME); //get the next arrival time from keyboard input

	while(arrivalTime < 99999)	//停止标识设为10万
	{
		if (carQueue.empty()) //如果当前队列为空
		{
			processArrivalEmptyQ(arrivalTime);
			arrivalTime = getNextArrival(&TIME); //get next arrival
		}
		else if (arrivalTime < carQueue.front().getDepartureTime()) //arrival first, process arrival
		{
			processArrivalNonEmptyQ(arrivalTime);
			arrivalTime = getNextArrival(&TIME); //get next arrival
		}
		else //departure first or of the same time, process departure
		{
			processDeparture(); //no need to get next arrival
		}
	}

	//no more arrival, process the remaining cars in the queue
	processRemain();
}

double WashCmp::getNextArrival(double* TIME)
{
	double tempT;
	//std::cout << "Please input the next arrival time (input 999 to terminate):\n";
	//std::cin >> tempT;
	//srand((unsigned int)time(0));
	tempT = -1.0 / LAMTA * log(1.0 - rand() / double(RAND_MAX + 1));
	*TIME += tempT;
	std::cout << *TIME << std::endl;
	return *TIME;
}

void WashCmp::processArrivalNonEmptyQ(double arrivalTime)
{
	if (carQueue.size() < CAPACITY) //add the arrived car to the waiting queue
	{
		carQueue.push(Car(arrivalTime)); //set the arrival time of the arrived car
		carQueue.back().printCarArrival(); //print the arrival information of the arrived car
	}
	else //the arrived car leaves
		std::cout << "OVERFLOW!!!\n";
}

void WashCmp::processArrivalEmptyQ(double arrivalTime)
{
	carQueue.push(Car(arrivalTime)); //set the arrival time of the arrived car
	carQueue.front().setDepartAndWaitTime(arrivalTime); //set the departure and waiting time of the arrived car
	carQueue.front().printCarArrival(); //print the arrival information of the arrived car
}

void WashCmp::processDeparture()//处理车辆离开
{
	int currTime = carQueue.front().getDepartureTime(); //get the current time

	totalWaitingTime += carQueue.front().getWaitingTime(); //更新总的等待时长
	numServedCars++; //更新服务车的数量
	carQueue.front().printCarDeparture(); //print departure information 
	carQueue.pop(); //departs

	if (!carQueue.empty())                                 //set the departure and waiting time of
		carQueue.front().setDepartAndWaitTime(currTime);   //the current front car in the queue
}

void WashCmp::processRemain() //处理剩余队列中剩余车辆
{
	while (!carQueue.empty())
		processDeparture();
}

void WashCmp::printCmpStatistic()
{
	std::cout << "\nNumber of served cars: " << numServedCars << std::endl;
	std::cout << "Total waiting time: " << totalWaitingTime << std::endl;
	std::cout << "The average waiting time is: " << (double)totalWaitingTime / numServedCars << std::endl;
	std::cout << "The theory average waiting time is: " << LAMTA / (Car::MIU*(Car::MIU-LAMTA)) << std::endl;
}