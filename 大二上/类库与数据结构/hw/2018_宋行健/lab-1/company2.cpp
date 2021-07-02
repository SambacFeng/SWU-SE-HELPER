//#include "pch.h"
#include "company2.h"
#include "employee2.h"

void Company2::findBestPaid()
{
	Employee2 temp;
	temp.input();
	while (temp.getName()!="*")
	{
//		if (temp.compare(bestPaid))
//			bestPaid.copy(temp);
		if (temp > bestPaid)
			bestPaid = temp;
		temp.input();
	}
}