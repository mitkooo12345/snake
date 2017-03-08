#pragma once
#include "Segment.h"

class Snake{
private:
	int numberOfSegments = 0;
	Segment* segments = new Segment[10];

	void moveHead(char);
	void moveBody();

	void generateHead();
	void generateSegment();

public:
	Snake();
	~Snake();

	Segment* getSnakeSegments();
	//Segment getSnakeHead();

	void moveSnake(char);
	
	int getNumberOfSegments();
};

