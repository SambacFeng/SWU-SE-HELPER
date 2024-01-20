#ifndef WASH_H
#define WASH_H

#include <queue>
#include <list>
#include "car.h"

extern double lambda;
extern double mu;

class WashCmp
{	
private:
	std::queue<Car> carQueue;
	std::list<Car> washingBay;
	//const static int CAPACITY;

	int numServedCars;
	double totalWaitingTime;
	int totalCars;
	int arrivedCars;
	int MaxWaitingCars;
	double lastArrivalTime;

	void setLambda();
	void setMu();
	double getMinDepartureTime();
	double getNextArrival(); //accept user input to get the next arrival time
	int getTotalCars();
	void processArrivalNonEmptyQ(double currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(double currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp();
	void simulation();
	void printCmpStatistic();
};


#endif