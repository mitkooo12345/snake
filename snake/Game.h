#pragma once
#include <conio.h>
#include "Map.h"

class Game {
private:
	Map map;
	//Snake snake;
	//Segment head;

	void moveSnake();


public:
	Game();
	void startGame();


};
