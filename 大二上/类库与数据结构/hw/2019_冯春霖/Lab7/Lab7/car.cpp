
#include "car.h"
#include <iostream>
#include <cmath>
#include <ctime>

//const int Car::SERVICE_T = 10;

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
	departureTime = startServiceTime + serviceTime;
	waitingTime = startServiceTime - arrivalTime;
}

void Car::setDepartAndWaitTime(int startServiceTime, double mu)
{
	srand((unsigned int)time(NULL));

	departureTime = startServiceTime + (-mu * (log(1 - rand() / (double)(RAND_MAX))));

	std::cout << (-mu * (log(1 - rand() / (double)(RAND_MAX + 1)))) << std::endl;
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

double Car::generateServiceTime(double a)
{
	srand((unsigned int)time(NULL));
	return -a * (log(1 - rand() / (RAND_MAX + 1)));
}