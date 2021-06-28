
#include "company2.h"
#include "employee2.h"

void Company2::findBestPaid()
{
	Employee2 employee2;

	employee2.input();

    while (employee2.getName() != "*")
    {
        if (employee2.compare(bestPaid))
            bestPaid.copy(employee2);
        employee2.input();
    } // while
	//please implement this
}