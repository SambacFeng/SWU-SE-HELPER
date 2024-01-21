#include "car.h"
#include <iostream>
#include "washCmp.h"

//const int Car::SERVICE_T = 10;

Car::Car()
{
	arrivalTime = 0;
	departureTime = 0;
	waitingTime = 0;
}

Car::Car(double arrivalT)
{
	arrivalTime = arrivalT;
}



double Car::getArrivalTime()
{
	return arrivalTime;
}

double Car::getDepartureTime()
{
	return departureTime;
}

double Car::getWaitingTime()
{
	return waitingTime;
}

void Car::setDepartAndWaitTime(double startServiceTime)
{

	double p = rand() / double(RAND_MAX + 1);
	double t = -(log(1 - p)) / mu;

	departureTime = startServiceTime + t; //离开时间=开始时间+洗车时间
	waitingTime = startServiceTime - arrivalTime; //等待时间=开始时间-到达时间
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