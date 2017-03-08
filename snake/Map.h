#pragma once
#include "Snake.h"

class Map {
private:
	int mapSize = 25;
	int foodX;
	int foodY;

	Snake snake;
	Segment* segments;

public:
	Map();
	void drawMap();
	void generateFood();
	Snake getSnake();

};
