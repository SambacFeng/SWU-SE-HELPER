
#include "washCmp.h"
#include <iostream>
#include <cmath>
#include <ctime>

//const int WashCmp::CAPACITY = 5 + 1;

WashCmp::WashCmp()
{
	totalWaitingTime = 0;
	numServedCars = 0;
}

void WashCmp::simulation()
{
	int arrivalTime = getNextArrival(); //get the next arrival time from keyboard input

	while(arrivalTime != 999)
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
		if (carQueue.size() > maxQueueLength)
			maxQueueLength = carQueue.size();
	}

	//no more arrival, process the remaining cars in the queue
	processRemain();
}

void WashCmp::simulation(int times)
{
	int arrivalTime;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < times; i++)
	{
		srand((unsigned int)time(NULL));

		arrivalTime = -lambda * (log(1 - rand() / (double)(RAND_MAX)));
		if (carQueue.empty()) //queue empty, process arrival
		{
			processArrivalEmptyQ(arrivalTime);
		}
		else if (arrivalTime < carQueue.front().getDepartureTime()) //arrival first, process arrival
		{
			processArrivalNonEmptyQ(arrivalTime);
		}
		else //departure first or of the same time, process departure
		{
			processDeparture(); //no need to get next arrival
		}
		if (carQueue.size() > maxQueueLength)
			maxQueueLength = carQueue.size();
	}

	processRemain();
}

int WashCmp::getNextArrival()
{
	int tempT;
	std::cout << "Please input the next arrival time (input 999 to terminate):\n";
	std::cin >> tempT;
	return tempT;
}

void WashCmp::processArrivalEmptyQ(int arrivalTime)
{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.setDepartAndWaitTime(arrivalTime, mu); //set the departure and waiting time of the arrived car
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
}

void WashCmp::processArrivalNonEmptyQ(int arrivalTime)
{
	//if (carQueue.size() < CAPACITY) //add the arrived car to the waiting queue
	//{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
	//}
	//else //the arrived car leaves
	//	std::cout << "OVERFLOW!!!\n";
}

void WashCmp::processDeparture()
{
	int currTime = carQueue.front().getDepartureTime(); //get the current time

	totalWaitingTime += carQueue.front().getWaitingTime(); //update statistics
	numServedCars++; //update statistics

	carQueue.front().printCarDeparture(); //print departure information 
	carQueue.pop(); //departs

	if (!carQueue.empty())                                 //set the departure and waiting time of
		carQueue.front().setDepartAndWaitTime(currTime, mu);   //the current front car in the queue
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
	std::cout << "Number of max queue length cars: " << maxQueueLength << std::endl;

	std::cout << (1.0 / lambda) / ((1.0 / mu) * (1.0 / mu - 1.0 / lambda)) << std::endl;
}

void WashCmp::init()
{
	std::cout << "Please input the mean arrival rate:\n";
	std::cin >> lambda;
	std::cout << "Please input the mean service rate:\n";
	std::cin >> mu;
	std::cout << "Please input the number of cars to be simulate:\n";
	std::cin >> totalServiceNumber;
	simulation(totalServiceNumber);
}

double WashCmp::expRandomNumber(double a)
{
	srand((unsigned int)time(NULL));
	return -a * (log(1 - rand() / (RAND_MAX)));
}