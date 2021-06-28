#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;
	const static int CAPACITY;

	int numServedCars;//储存已服务的车辆数
	double totalWaitingTime;
	double arrivalTime;
	int numServedCars_MAX;//储存总共服务的车辆
	int Car_MAX;//记录最长队列长度




	int getNextArrival(); //accept user input to get the next arrival time
	void processArrivalNonEmptyQ(double currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(double currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp();
	WashCmp(int n);
	void simulation();
	void printCmpStatistic();
};


#endif