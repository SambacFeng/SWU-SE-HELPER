#ifndef COMPANY
#define COMPANY

#include "employee1.h" // declares Employee class

class Company
{
  private:
      Employee bestPaid;
	  Employee empArray[5];
	  int empNum;

   public:
      Company(); 
	  void storeEmp();
      void findBestPaid();
      void printBestPaid() const;
}; // Company

#endif
