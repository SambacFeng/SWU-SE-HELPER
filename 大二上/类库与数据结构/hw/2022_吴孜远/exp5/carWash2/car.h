#ifndef CAR_H
#define CAR_H


class Car
{
private:
	double arrivalTime;
	double departureTime;
	double waitingTime;

public:
	Car();
	Car(double arrivalT);

	double getArrivalTime();
	double getDepartureTime();
	double getWaitingTime();

	void setDepartAndWaitTime(double currTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
