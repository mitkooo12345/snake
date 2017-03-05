#pragma once

class Segment {
private:
	char direction, prevDirection;
	int x, y;
	int newX, newY;


public:
	Segment();
	~Segment();
	void setDirection(char);
	char getDirection();
	void setX(int);
	void setY(int);
	void setNewX(int);
	void setNewY(int);
	void setPrevDirection(char);

	int getX();
	int getY();
	int getNewX();
	int getNewY();
	char getDirection();
	char getPrevDirection();
};
