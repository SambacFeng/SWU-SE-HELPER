
#include "company.h"

int main()
{
	Company cmp;

	cmp.inputEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();

	cmp.removeEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();

	return 0;
}