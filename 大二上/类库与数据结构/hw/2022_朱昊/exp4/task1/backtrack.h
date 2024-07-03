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
private:
	Application app;
};

#endif
