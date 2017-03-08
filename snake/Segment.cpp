#include "Segment.h"

void Segment::setDirection(char value) {
	direction = value;
}

char Segment::getDirection() {
	return direction;
}

//char Segment::getPrevDirection() {
//	return prevDirection;
//}

void Segment::setX(int value) {
	x = value;
}
void Segment::setY(int value) {
	y = value;
}

void Segment::setNewX(int value) {
	newX = value;
}

void Segment::setNewY(int value) {
	newY = value;
}

//void Segment::setPrevDirection(char value) {
//	prevDirection = value;
//}

int Segment::getX(){
	return x;
}
int Segment::getY() {
	return y;
}

int Segment::getNewX() {
	return newX;
}

int Segment::getNewY() {
	return newY;
}
