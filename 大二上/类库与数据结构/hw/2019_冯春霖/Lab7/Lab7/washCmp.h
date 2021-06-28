#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;
	//const static int CAPACITY;

	int numServedCars;
	int totalWaitingTime;

	double lambda;
	double mu;
	int totalServiceNumber;
	int maxQueueLength = 0;

	int getNextArrival(); //accept user input to get the next arrival time
	void processArrivalNonEmptyQ(int currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(int currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

	double expRandomNumber(double a);

public:
	WashCmp();
	void simulation();
	void printCmpStatistic();
	void init();

	void simulation(int times);
};


#endif