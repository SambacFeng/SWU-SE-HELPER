#ifndef COMPANY
#define COMPANY

#include "employee1.h" // declares Employee class

class Company
{
  private:
      Employee bestPaid;

	  Employee empArray[5]; //5 Employee objects

	  int empNum; //current number of employee

   public:
      Company(); 

	  void storeEmp();//accept use input information from keyboard, and store the information in the array empArray

      void findBestPaid();

      void printBestPaid() const;
}; // Company

#endif
