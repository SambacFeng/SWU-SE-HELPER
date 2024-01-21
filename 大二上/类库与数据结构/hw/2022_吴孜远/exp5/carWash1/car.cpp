#include "car.h"
#include <iostream>

const int Car::SERVICE_T = 10;

Car::Car()
{
	arrivalTime = 0;
	departureTime = 0;
	waitingTime = 0;
}

Car::Car(int arrivalT)
{
	arrivalTime = arrivalT;
}

int Car::getArrivalTime()
{
	return arrivalTime;
}

int Car::getDepartureTime()
{
	return departureTime;
}

int Car::getWaitingTime()
{
	return waitingTime;
}

void Car::setDepartAndWaitTime(int startServiceTime)
{
	departureTime = startServiceTime + SERVICE_T;
	waitingTime = startServiceTime - arrivalTime;
}

void Car::printCarDeparture()
{
	std::cout << "A car is washed and departs!\n";
	std::cout << "\tArrival time: " << arrivalTime << std::endl;
	std::cout << "\tDeparture time: " << departureTime << std::endl;
	std::cout << "\tWaiting time: " << waitingTime << std::endl;
}

void Car::printCarArrival()
{
	std::cout << "A car arrives!\n";
	std::cout << "\tArrival time: " << arrivalTime << std::endl;
}