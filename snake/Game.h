#pragma once
#include <conio.h>
#include "Map.h"
#include <windows.h>

class Game {
private:
	Map map;
	bool hasCollision;
	//Snake snake;
	//Segment head;

	void moveSnake();
	void eatFood();
	bool isHeadOverFood();
	bool isCollided();


public:
	Game();
	void startGame();


};
