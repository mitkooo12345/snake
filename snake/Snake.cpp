#include <cstdlib>
#include <ctime>
#include "Snake.h"


Snake::Snake(){
	generateHead();
	generateSegment();

}

Snake::~Snake(){
	segments[0].setNewY(6666);
	//delete[] segments;
}

void Snake::moveHead(char value) {

	//down
	if (value == 's') {
		segments[0].setNewY(segments[0].getY() + 1);
	//up
	} else if (value == 'w') {
		segments[0].setNewY(segments[0].getY() - 1);
	//left
	} else if (value == 'a') {
		segments[0].setNewX(segments[0].getX() - 1);
	//right
	} else if (value == 'd') {
		segments[0].setNewX(segments[0].getX() + 1);
	}

	segments[0].setDirection(value);
	
}

void Snake::moveBody() {
	for (int i = 1; i < numberOfSegments; i++) {
		segments[i].setNewX(segments[i-1].getX());
		segments[i].setNewY(segments[i-1].getY());

	}

	for (int i = 0; i < numberOfSegments; i++) {
		segments[i].setX(segments[i].getNewX());
		segments[i].setY(segments[i].getNewY());
	}

}

void Snake::moveSnake(char value) {
 	char dir = segments[0].getDirection();

	if ((dir == 's' && value != 'w') ||
		(dir == 'w' && value != 's') ||
		(dir == 'a' && value != 'd') ||
		(dir == 'd' && value != 'a')) {

		moveHead(value);
		moveBody();

	}

}

void Snake::generateHead() {
	Segment head;

	srand(time(0));
	
	int x = rand() % 20 + 2; // is the map size
	int y = rand() % 20 + 2;

	head.setX(x);
	head.setY(y);

	head.setNewX(x);
	head.setNewY(y);


	head.setDirection('d');

	segments[0] = head;

	numberOfSegments++;
}

void Snake::generateSegment() {
	Segment segment;
	segment.setX(segments[0].getX() - 1);
	segment.setY(segments[0].getY());

	segment.setNewX(segments[0].getX() - 1);
	segment.setNewY(segments[0].getY());

	//segment.setNewX(segments[numberOfSegments - 1].getX());
	//segment.setNewY(segments[numberOfSegments - 1].getY());

	segments[numberOfSegments] = segment;
	
	numberOfSegments++;

}

Segment* Snake::getSnakeSegments() {
	return segments;
}

//Segment Snake::getSnakeHead() {
//	return segments[0];
//}

int Snake::getNumberOfSegments() {
	return numberOfSegments;
}
