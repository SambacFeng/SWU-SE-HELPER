#ifndef CAR_H
#define CAR_H

class Car
{
private:
	int arrivalTime;
	int departureTime;
	int waitingTime;
	//const static int SERVICE_T;

	double serviceTime;

public:
	Car();
	Car(int arrivalT, double mu);

	int getArrivalTime();
	int getDepartureTime();
	int getWaitingTime();

	void setDepartAndWaitTime(int currTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
