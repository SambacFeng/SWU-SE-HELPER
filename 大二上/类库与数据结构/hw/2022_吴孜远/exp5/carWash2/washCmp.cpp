#include "washCmp.h"
#include <iostream>

//const int WashCmp::CAPACITY = 5 + 1;
double lambda;
double mu;

WashCmp::WashCmp()
{
	totalWaitingTime = 0;
	numServedCars = 0;
	totalCars = 0;
	arrivedCars = 0;
	MaxWaitingCars = 0;
	lastArrivalTime = 0;
}

void WashCmp::simulation()
{
	setLambda();
	setMu();
	int totalCars = getTotalCars();
	double arrivalTime = getNextArrival(); //获取第一个到达时间

	while(arrivedCars <= totalCars)
	{
		if (carQueue.empty()) //queue empty, process arrival
		{
			processArrivalEmptyQ(arrivalTime);
			arrivalTime = getNextArrival(); //get next arrival
		}
		else if (arrivalTime < carQueue.front().getDepartureTime()) //arrival first, process arrival
		{
			processArrivalNonEmptyQ(arrivalTime);
			arrivalTime = getNextArrival(); //get next arrival
		}
		else //departure first or of the same time, process departure
		{
			//若下一辆车到达时间远大于服务车离开时间，则每次都处理离开而不获取下一个到达时间，直到上一次的到达时间小于离开时间
			processDeparture(); //no need to get next arrival
		}
	}
	//no more arrival, process the remaining cars in the queue
	processRemain();
}

void WashCmp::setLambda()
{
	
	double meanInterArrivalTime; //3
	std::cout << "input the mean inter arrival time:";
	std::cin >> meanInterArrivalTime;
	lambda = 1 / meanInterArrivalTime;
	//std::cout << lambda << std::endl;
}
void WashCmp::setMu()
{

	double meanServiceTime; //2
	std::cout << "input the mean service time:";
	std::cin >> meanServiceTime;
	mu = 1 / meanServiceTime;
	//std::cout << mu << std::endl;
}

double WashCmp::getNextArrival()
{
	double p = rand() / double(RAND_MAX + 1);
	double t = - (log(1 - p)) / lambda;

	return t + lastArrivalTime; //下一个到达时间=时间间隔+上一个车的到达时间
}

int WashCmp::getTotalCars()
{
	int tempT;
	std::cout << "Please input the total car number: ";
	std::cin >> tempT;
	std::cout << "\n";
	return tempT;
}

void WashCmp::processArrivalEmptyQ(double arrivalTime)
{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.setDepartAndWaitTime(arrivalTime); //set the departure and waiting time of the arrived car
	//arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car

	if (MaxWaitingCars < carQueue.size()) {
		MaxWaitingCars = carQueue.size();
	}
	arrivedCars++; //计数到达车辆
	lastArrivalTime = arrivalTime; //记录这一辆车的到达时间用于计算下一辆车的到达时间
}



void WashCmp::processArrivalNonEmptyQ(double arrivalTime)
{
	// if (carQueue.size() < CAPACITY) //若还有空位，则加入等待
	//{
	Car arrivedCar = Car(arrivalTime);
	//arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
	//每次加入都更新最大队列数
	if (MaxWaitingCars < carQueue.size()) {
		MaxWaitingCars = carQueue.size();
	}
	arrivedCars++;
	lastArrivalTime = arrivalTime;
	//}
	//else //the arrived car leaves
		//std::cout << "OVERFLOW!!!\n";
}

void WashCmp::processDeparture()
{
	double currTime = carQueue.front().getDepartureTime(); //get the current time

	totalWaitingTime += carQueue.front().getWaitingTime(); //update statistics
	numServedCars++; //update statistics

	//carQueue.front().printCarDeparture(); //print departure information 
	carQueue.pop(); //departs

	if (!carQueue.empty())//set the departure and waiting time of
		//下一辆车开始服务，currTime是上一辆车离开时间也是当前车的开始服务时间
		carQueue.front().setDepartAndWaitTime(currTime);   //设置当前服务车的离开时间（未来）和等待时间
}

void WashCmp::processRemain() //wash the remaining cars in the queue
{
	while (!carQueue.empty())
		processDeparture();
}

void WashCmp::printCmpStatistic()
{
	//std::cout << "Number of served cars: " << numServedCars << std::endl;
	std::cout << "Total waiting time: " << totalWaitingTime << std::endl;
	std::cout << "The average waiting time is: " << (double)totalWaitingTime / numServedCars << std::endl;
	std::cout << "Total Max Waiting Cars: " << MaxWaitingCars - 1 << std::endl;
	std::cout << "Theoretical value of average waiting time：" << lambda / (mu * (mu - lambda));

	
}