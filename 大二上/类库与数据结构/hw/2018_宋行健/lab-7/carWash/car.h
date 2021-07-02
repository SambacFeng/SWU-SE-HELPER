#ifndef CAR_H
#define CAR_H

class Car
{
private:
	double arrivalTime;	//到达时间
	double departureTime;	//离开时间
	double waitingTime;	//等待时间
	double  serviceTime;	//服务时间
	//const static int SERVICE_T;	//服务时间


public:
	Car();
	Car(double arrivalT);
	const static double MIU;	//关于服务时间的参数μ

	double getArrivalTime();
	double getDepartureTime();
	double getWaitingTime();
	double getserviceTime();

	void setDepartAndWaitTime(double currTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
