#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;
	const static int CAPACITY;

	int numServedCars;
	int totalWaitingTime;

	double lambda, mu;
	double arrivalTime;
	int totalServiceNumber;
	int maxQueueLength;


	int getNextArrival(); //accept user input to get the next arrival time
	void processArrivalNonEmptyQ(int currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(int currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp();
	void simulation();
	void printCmpStatistic();
};


#endif