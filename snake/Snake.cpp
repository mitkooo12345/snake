#include "Snake.h"



Snake::Snake(){

}


Snake::~Snake(){

}

void Snake::moveHead() {
	//I have to set the head's x and y beforehand

	char dir = segments[0].getDirection();

	if (dir == 'd') {
		segments[0].setNewY(segments[0].getY() + 1);

	} else if (dir == 'u') {
		segments[0].setNewY(segments[0].getY() - 1);

	} else if (dir == 'l') {
		segments[0].setNewX(segments[0].getX() - 1);
	
	} else if (dir == 'r') {
		segments[0].setNewX(segments[0].getX() + 1);
	}
	
}

void Snake::moveBody() {
	for (int i = 1; i < length; i++) {
		segments[i].setNewX(segments[i-1].getX());
		segments[i].setNewY(segments[i-1].getY());
		segments[i].setDirection(segments[i - 1].getPrevDirection());
	}

}
