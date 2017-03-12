#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Map.h"

Map::Map() {
	segments = snake.getSnakeSegments();
	generateFood();
}

void Map::drawMap() {

	system("cls");

	std::cout << "Score: " << score << "  " << "Goal: " << "20" << std::endl << std::endl;

	int counter = 0;
	int numberOfSegments = snake.getNumberOfSegments();

	//Segment* segments = snake.getSnake();


	for (int i = 0; i < mapSize; i++) {

		bool head = false;
		bool segment = false;

		//first or last row
		if (i == 0 || (i == mapSize - 1)) {
			std::cout << "#";

			for (int j = 0; j < mapSize; j++) {
				std::cout << "###";
			}

			std::cout <<  "#" << std::endl;

		} else {
			std::cout << "#";

			for (int j = 0; j < mapSize; j++) {

				//print snake
				if(counter <= numberOfSegments)
				for(int p = 0; p < numberOfSegments; p++) {
					if (segments[p].getNewX() == j && segments[p].getNewY() == i) {
						counter++;
						if (p == 0) {
							head = true;
							break;
						} else {
							segment = true;
							break;
						}
					}
					
				}

				if (i == foodY && j == foodX) {

					std::cout << " + ";
				} else if (head) {

					std::cout << " @ ";
					head = false;

				} else if(segment) {
					std::cout << " o ";
					segment = false;

				

				} else {
					std::cout << "   ";
				}
				
			}

			std::cout << "#" << std::endl;
		}
	}
}

void Map::generateFood() {

	Segment* segments = snake.getSnakeSegments();

	do {
		srand(time(0));
		foodX = rand() % 20 + 2;
		foodY = rand() % 20 + 2;

	} while ((segments[0].getNewX() == foodX) && (segments[0].getNewY() == foodY));
}

Snake& Map::getSnake() {
	return snake;
}

int Map::getMapSize() {
	return mapSize;
}

void Map::loseGame() {
	std::cout << "You lost!" << std::endl;
}

void Map::winGame() {
	std::cout << "You won!" << std::endl;
}

void Map::growSnake() {
	generateFood();
	snake.addSegment();
	score++;
}

int Map::getFoodX() {
	return foodX;
}

int Map::getFoodY() {
	return foodY;
}

bool Map::isCollided() {
	int numberOfSegments = snake.getNumberOfSegments() - 1;
	for (int i = 1; i < numberOfSegments; i++) {
		if ((snake.getSnakeHead().getX() == segments[i].getX()) && (snake.getSnakeHead().getY() == segments[i].getY())) {
			return true;
		}
	}

	return false;
}

int Map::getScore() {
	return score;
}