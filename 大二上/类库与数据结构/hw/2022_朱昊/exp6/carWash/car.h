#ifndef CAR_H
#define CAR_H

class Car
{
private:
	int arrivalTime;
	int departureTime;
	int waitingTime;
	const static int SERVICE_T;

public:
	Car();
	Car(int arrivalT);

	int getArrivalTime();
	int getDepartureTime();
	int getWaitingTime();

	void setDepartAndWaitTime(int currTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
