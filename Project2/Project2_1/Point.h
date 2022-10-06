#pragma once
class Point
{
private:
	int x;
	int y;
public:
	void setX(int myX);
	void setY(int myY);
	int getX();
	int getY();
	float distence(Point); // distance between 2 points
};
