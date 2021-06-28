
#include "washCmp.h"
#include <iostream>
#include <ctime>
#include <cmath>

//const int WashCmp::CAPACITY = 5 + 1;

WashCmp::WashCmp()
{
	totalWaitingTime = 0;
	numServedCars = 0;

	double temp;

	std::cout << "Please input the mean arrival rate:\n";
	std::cin >> temp;
	lambda = 1.0 / temp;
	std::cout << "Please input the mean service rate:\n";
	std::cin >> temp;
	mu = 1.0 / temp;
	std::cout << "Please input the number of cars to be simulate:\n";
	std::cin >> totalServiceNumber;
}

void WashCmp::simulation()
{
	arrivalTime = getNextArrival();

	while (numServedCars != totalServiceNumber)
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
	//std::cout << "Please input the next arrival time (input 999 to terminate):\n";
	tempT = arrivalTime - 1.0 / lambda * log(1 - rand() / (double)RAND_MAX);
	return tempT;
}

void WashCmp::processArrivalEmptyQ(int arrivalTime)
{
	Car arrivedCar = Car(arrivalTime, mu);
	arrivedCar.setDepartAndWaitTime(arrivalTime); //set the departure and waiting time of the arrived car
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
	if (carQueue.size() > maxQueueLength)
		maxQueueLength = carQueue.size();
}

void WashCmp::processArrivalNonEmptyQ(int arrivalTime)
{
	Car arrivedCar = Car(arrivalTime, mu);
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
	if (carQueue.size() > maxQueueLength)
		maxQueueLength = carQueue.size();
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
	std::cout << "Total waiting time: " << totalWaitingTime << std::endl;
	std::cout << "The average waiting time is: " << (double)totalWaitingTime / numServedCars << std::endl;
	std::cout << "Max length of queue is: " << maxQueueLength << std::endl;
	std::cout << "lambda / (mu * (mu - lambda)): " << lambda / (mu * (mu - lambda)) << std::endl;
}
