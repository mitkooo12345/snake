#include <cstdlib>
#include <ctime>
#include "Snake.h"


Snake::Snake(){
	generateHead();
	generateSegment();
}

Snake::~Snake(){
	delete[] segments;
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

	if (segments[0].getDirection() == value) {
		segments[0].setPrevDirection(value);
	} else {
		segments[0].setDirection(value);
	}	
}

void Snake::moveBody() {
	for (int i = 1; i < numberOfSegments; i++) {
		segments[i].setNewX(segments[i-1].getX());
		segments[i].setNewY(segments[i-1].getY());
		if (segments[i].getDirection() == segments[i - 1].getPrevDirection()) {
			segments[i].setPrevDirection(segments[i].getDirection());
		} else {
			segments[i].setDirection(segments[i - 1].getPrevDirection());
		}	
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
	head.setPrevDirection('d');

	segments[0] = head;

	numberOfSegments++;
}

void Snake::generateSegment() {
	Segment segment;
	segment.setX(segments[0].getX() - 1);
	segment.setY(segments[0].getY());

	segment.setNewX(segments[0].getX() - 1);
	segment.setNewY(segments[0].getY());

	segment.setDirection('d');
	segment.setPrevDirection('d');

	segments[numberOfSegments] = segment;
	
	numberOfSegments++;
}

void Snake::addSegment() {
	Segment segment;
	Segment prevSegment = segments[numberOfSegments - 1];

	segment.setDirection(prevSegment.getDirection());
	segment.setPrevDirection(prevSegment.getDirection());

	if (segment.getDirection() == 'd') {
		segment.setX(prevSegment.getX()+1);
		segment.setNewX(prevSegment.getX()+1);

		segment.setY(prevSegment.getY());
		segment.setNewY(prevSegment.getY());

	} else if (segment.getDirection() == 'a') {

		segment.setX(prevSegment.getX() - 1);
		segment.setNewX(prevSegment.getX() - 1);

		segment.setY(prevSegment.getY());
		segment.setNewY(prevSegment.getY());


	} else if (segment.getDirection() == 'w') {

		segment.setY(prevSegment.getY() - 1);
		segment.setNewY(prevSegment.getY() - 1);

		segment.setX(prevSegment.getX());
		segment.setNewX(prevSegment.getX());


	} else if (segment.getDirection() == 's') {
		segment.setY(prevSegment.getY() + 1);
		segment.setNewY(prevSegment.getY() + 1);

		segment.setX(prevSegment.getX());
		segment.setNewX(prevSegment.getX());
	}

	segments[numberOfSegments] = segment;
	numberOfSegments++;
}

Segment* Snake::getSnakeSegments() {
	return segments;
}

Segment Snake::getSnakeHead() {
	return segments[0];
}

int Snake::getNumberOfSegments() {
	return numberOfSegments;
}
