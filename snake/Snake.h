#pragma once
#include "Segment.h"

class Snake{
private:
	int length = 1;
	Segment* segments = new Segment[15];


public:
	Snake();
	~Snake();
	void moveHead();
	void moveBody();
};

