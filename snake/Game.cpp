#include "Game.h"

Game::Game() {
	hasCollision = false;
}

void Game::startGame() {

	while (1) {
		map.drawMap();
		moveSnake();
		if (map.getScore() == 20) {
			map.drawMap();
			map.winGame();
			break;
		} else if(!hasCollision) {
			map.drawMap();
		} else {
			map.loseGame();
			break;
		}
		
	}
}

void Game::moveSnake() {
	char c = map.getSnake().getSnakeHead().getDirection();

	int waitSecond = 2;
	while (1) {

		if (kbhit()) {
			c = getch();
		}

		Sleep(200); 
		--waitSecond;

		if (waitSecond == 0)
			break;
	}


	switch (c) {
	case 's'://down
		if ((map.getSnake().getSnakeHead().getY() + 2 == 25) || (isCollided())) {
			hasCollision = true;
		
		} else {
			map.getSnake().moveSnake('s');
			if (isHeadOverFood())
				eatFood();
		}
		break;

	case 'w'://up
		if ((map.getSnake().getSnakeHead().getY() - 1 == 0) || (isCollided())) {
			hasCollision = true;
		
		} else {
			map.getSnake().moveSnake('w');
			if (isHeadOverFood())
				eatFood();

		}
		break;

	case 'a': //left
		if ((map.getSnake().getSnakeHead().getX() == 0) || (isCollided())) {
			hasCollision = true;
		
		} else {
			map.getSnake().moveSnake('a');
			if (isHeadOverFood())
				eatFood();
		}
		break;

	case 'd'://right
		if ((map.getSnake().getSnakeHead().getX() + 1 == 25) || (isCollided())) {
			hasCollision = true;
		
		} else {
			map.getSnake().moveSnake('d');
			if (isHeadOverFood())
				eatFood();
		}
		break;

	default:
		break;
	}

}

void Game::eatFood() {
	map.growSnake();
}

bool Game::isHeadOverFood() {
	if ((map.getSnake().getSnakeHead().getX() == map.getFoodX()) && (map.getSnake().getSnakeHead().getY() == map.getFoodY())) {
		return true;
	} else {
		return false;
	}
}

bool Game::isCollided() {
	return map.isCollided();
}
