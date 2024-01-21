#ifndef COMPANY
#define COMPANY

#include "employee1.h" // declares Employee class

class Company
{
	protected:
    //private:
      Employee bestPaid;
	
	public:
      Company(); 
      void findBestPaid();
      void printBestPaid() const;
}; // Company

#endif
