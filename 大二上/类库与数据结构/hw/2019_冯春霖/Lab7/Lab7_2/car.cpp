
#include "car.h"
#include <iostream>
extern double u;
Car::Car()
{
	arrivalTime = 0;
	departureTime = 0;
	waitingTime = 0;
}

Car::Car(double arrivalT)
{
	arrivalTime = arrivalT;
	departureTime = 0;
	waitingTime = 0;
	SERVICE_T = -1.0/u * log(1 - rand() / double(RAND_MAX + 1));//随机生成洗车所需时间
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


void Car::setDepartAndWaitTime(double startServiceTime)
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