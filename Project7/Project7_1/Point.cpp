/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include "Point.h"

Point::Point()                 // default constructor
{
	setX(0);
	setY(0);
}

Point::Point(int myX, int myY) // constructor
{
	setX(myX);
	setY(myY);
}

void Point::setX(int myX) { x = myX; }

void Point::setY(int myY) { y = myY; }

int Point::getX() { return x; }

int Point::getY() { return y; }

float Point::distance(Point p) // the distance between 2 points
{
	float distance = sqrt((float)(((p.getX() - x) * (p.getX() - x) + ((p.getY() - y) * (p.getY() - y)))));
	return distance;
}

istream& operator>>(istream& is, Point& myPoint)
{
	char tav;
	int x, y;
	is >> tav >> x >> tav >> y >> tav;

	myPoint.x = x;
	myPoint.y = y;

   	return is;
}