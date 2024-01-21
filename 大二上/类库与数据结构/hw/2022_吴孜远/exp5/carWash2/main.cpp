#include "car.h"
#include "washCmp.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
using namespace std;


int main()
{
	srand((unsigned int)time(0));
	WashCmp cmp;
	cmp.simulation();
	cmp.printCmpStatistic();
	
	/*
	cout << RAND_MAX << endl; //32767
	
	double p2 = rand() / double(RAND_MAX + 1);
	double p3 = rand() / double(RAND_MAX + 1);

	for (int i = 0; i < 10; i++) {
		double p1 = rand() / double(RAND_MAX + 1);
		int t = -(log(1 - p1)) / 0.22;
		cout << p1 << " " << t << endl;
	}*/
/*
	cout << exp(1.000) << endl;
	cout << log(exp(1.0)) << endl;

	//mean waiting time is 1.5 hour
	//lambda = 1 / 1.5 = 0.667
	//1 - exp(- 0.667 * t) = p
	//log(1 - p) = - 0.667 * t
	//t = - 1.5 * log(1 - p)

	cout << "waiting time: " << -1.5 * log(1 - p1) << ", " << -1.5 * log(1 - p2) << ", " << -1.5 * log(1 - p3) << endl;
	*/
	
	return 0;
}
