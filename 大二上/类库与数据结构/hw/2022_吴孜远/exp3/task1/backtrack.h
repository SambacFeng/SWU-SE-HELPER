#ifndef BACKTRACK_H
#define BACKTRACK_H

#include "application.h"
#include "position.h"

class BackTrack
{
public:
	BackTrack();
	BackTrack(const Application& thisApp);

	bool backTrack(const Position& currPos);
	int globalcount = 0;
private:
	Application app;
};

#endif
