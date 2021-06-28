#ifndef CAR_H
#define CAR_H

class Car
{
private:
	double arrivalTime;
	double departureTime;
	double waitingTime;
	double SERVICE_T;


public:
	Car();
	Car(double arrivalT);

	int getArrivalTime();
	int getDepartureTime();
	int getWaitingTime();


	void setDepartAndWaitTime(double currTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
