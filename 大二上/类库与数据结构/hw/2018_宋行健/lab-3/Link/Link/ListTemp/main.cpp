
#include "listTemp.h"
#include "company.h"
#include <iostream>
using namespace std;

int main()
{
	Company cmp;
	cmp.inputEmployee();
	cmp.printLength();
	cmp.findBestPaid();
	cmp.printBestPaid();

	return 0;
}