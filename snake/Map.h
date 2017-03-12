#pragma once
#include "Snake.h"

class Map {
private:
	int mapSize = 25;
	int foodX;
	int foodY;

	int score = 0;

	Snake snake;
	Segment* segments;

public:
	Map();
	void drawMap();
	void generateFood();
	Snake& getSnake();
	int getMapSize();
	void loseGame();
	void winGame();
	void growSnake();
	int getFoodX();
	int getFoodY();
	bool isCollided();

	int getScore();

};
