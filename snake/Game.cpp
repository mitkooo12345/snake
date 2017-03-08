#include "Game.h"

Game::Game() {
	//snake = map.getSnake();
	//head = snake.getSnakeHead();
}

void Game::startGame() {

	while (1) {
		map.drawMap();
		moveSnake();
		map.drawMap();
	}
}

void Game::moveSnake() {
	char c = getch();

	switch (c) {
	case 's'://down
		map.getSnake().moveSnake('s');
		break;

	case 'w'://up
		map.getSnake().moveSnake('w');
		break;

	case 'a': //left
		map.getSnake().moveSnake('a');
		break;

	case 'd'://right
		map.getSnake().moveSnake('d');
		break;

	default:
		break;
	}

}