#pragma once

class Segment {
private:
	char direction;  /*prevDirection;*/
	int x, y;
	int newX, newY;


public:
	void setX(int);
	void setY(int);
	void setNewX(int);
	void setNewY(int);
	void setDirection(char);
	//void setPrevDirection(char);

	int getX();
	int getY();
	int getNewX();
	int getNewY();
	char getDirection();
	//char getPrevDirection();
};
