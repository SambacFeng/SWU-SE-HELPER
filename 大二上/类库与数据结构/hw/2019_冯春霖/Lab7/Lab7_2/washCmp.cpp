
#include "washCmp.h"
#include <iostream>
extern double l;
WashCmp::WashCmp()
{
	totalWaitingTime = 0;
	numServedCars = 0;
	arrivalTime = 0;
	numServedCars_MAX = 0;
	Car_MAX = 0;
}

WashCmp::WashCmp(int n)
{
	arrivalTime = 0;
	totalWaitingTime = 0;
	numServedCars = 0;
	numServedCars_MAX = n;
	Car_MAX = 0;
}

void WashCmp::simulation()
{
	arrivalTime = getNextArrival(); //get the next arrival time from keyboard input

	while(numServedCars != numServedCars_MAX)
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
			processDeparture(); //no need to get next arrival
		}
	}

	//no more arrival, process the remaining cars in the queue
	processRemain();
}

int WashCmp::getNextArrival()
{
	int tempT;
	std::cout << "Please input the next arrival time (input 999 to terminate):\n";
	tempT  = arrivalTime-1.0/l * log(1 - rand() / double(RAND_MAX + 1));//生成下一个到达时间
	return tempT;
}

void WashCmp::processArrivalEmptyQ(double arrivalTime)
{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.setDepartAndWaitTime(arrivalTime); //set the departure and waiting time of the arrived car
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
	if (carQueue.size() > Car_MAX)Car_MAX = carQueue.size();//获取队列最长长度
}

void WashCmp::processArrivalNonEmptyQ(double arrivalTime)
{
	
		Car arrivedCar = Car(arrivalTime);
		arrivedCar.printCarArrival(); //print the arrival information of the arrived car
		carQueue.push(arrivedCar); //set the arrival time of the arrived car
		if(carQueue.size()>Car_MAX)Car_MAX=carQueue.size();//获取队列最长长度
	
}

void WashCmp::processDeparture()
{
	int currTime = carQueue.front().getDepartureTime(); //get the current time

	totalWaitingTime += carQueue.front().getWaitingTime(); //update statistics
	numServedCars++; //update statistics

	carQueue.front().printCarDeparture(); //print departure information 
	carQueue.pop(); //departs

	if (!carQueue.empty())                                 //set the departure and waiting time of
		carQueue.front().setDepartAndWaitTime(currTime);   //the current front car in the queue
}

void WashCmp::processRemain() //wash the remaining cars in the queue
{
	while (!carQueue.empty())
		processDeparture();
}

void WashCmp::printCmpStatistic()
{
	std::cout << "Number of served cars: " << numServedCars << std::endl;
	std::cout << "Total waiting time: " << (double)totalWaitingTime << std::endl;
	std::cout << "The average waiting time is: " << (double)totalWaitingTime / numServedCars << std::endl;
	std::cout << "The most cars in the queue in the same time"<<Car_MAX<<std::endl;
}