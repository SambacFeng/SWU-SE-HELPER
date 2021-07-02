#include "car.h"
#include <iostream>
#include <time.h>
#include <math.h>

//const int Car::SERVICE_T = 10;	//服务时间
const double Car::MIU = 1.0 / 15.0;	//关于平均服务时间的参数μ

Car::Car()
{
	arrivalTime = 0.0;
	departureTime = 0.0;
	waitingTime = 0.0;
	serviceTime = 0.0;
}

Car::Car(double arrivalT)
{
	arrivalTime = arrivalT;
	departureTime = 0.0;
	waitingTime = 0.0;
	serviceTime = 0.0;
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

double Car::getserviceTime()
{
	return serviceTime;
}

void Car::setDepartAndWaitTime(double currTime)
{
	//srand((unsigned int)time(0));
	serviceTime = -1.0 / MIU * log(1.0 - rand() / double(RAND_MAX + 1));
	departureTime = currTime + serviceTime;
	waitingTime = currTime - arrivalTime;
}

void Car::printCarDeparture()
{
	std::cout << "A car is washed and departs!\n";
	std::cout << "\tArrival time: " << arrivalTime << std::endl;
	std::cout << "\tDeparture time: " << departureTime << std::endl;
	std::cout << "\tWaiting time: " << waitingTime << std::endl;
	std::cout << "\tService time time: " << serviceTime << std::endl;
}

void Car::printCarArrival()
{
	std::cout << "A car arrives!\n";
	std::cout << "\tArrival time: " << arrivalTime << std::endl;
}