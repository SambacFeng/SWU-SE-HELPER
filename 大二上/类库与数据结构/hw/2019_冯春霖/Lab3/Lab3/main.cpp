//#include "pch.h"
#include "company.h"
#include <iostream>

int main()
{
	Company cmp;

	cmp.inputEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();
	cmp.removeEmployee();
	cmp.removeEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();

	return 0;
}