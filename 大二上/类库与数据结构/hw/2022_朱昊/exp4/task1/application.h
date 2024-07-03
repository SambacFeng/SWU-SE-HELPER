#ifndef APPLICATION_H
#define APPLICATION_H

#include "position.h"

class Application
{
public:
	void initialize(); //intialization 

	Position getStartPosition(); //get the start position

	bool isValid(const Position& p); //check whether the position p is valid

	void progress(const Position& p); //extend by including position p

	bool success(const Position& p); //check whether a successful solution is obtained at p

	void goBack(const Position& p); //go back one step from p

	void print(); //print the configuration of the application

	class Iterator //inner class
	{
	public:
		Iterator(); //default constructor
		Iterator(const Position& currP); //constructor with an input position
		~Iterator();

		Position getNextPosition(); //get next possible posible position
		bool noNextPosition(); //check whether all the possible next are tried

	private:
		void *currItrPosPtr; //additional information to find next
	};
};


#endif
