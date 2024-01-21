#include "company.h"
#include "employee.h"

int main()
{
	Company cmp;
	cmp.inputEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();
	
	return 0;
}