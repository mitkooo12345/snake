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

Snake Map::getSnake() {
	return snake;
}