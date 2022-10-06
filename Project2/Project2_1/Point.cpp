#include "Point.h"
#include <cmath>

void Point::setX(int myX) { x = myX; }

void Point::setY(int myY) { y = myY; }

int Point::getX() { return x; }

int Point::getY() { return y; }

float Point::distence(Point p)
{
	int x, y, a, b;
	x = getX();    // The coordinates of the first
	y = getY();
	a = p.getX(); // The coordinates of the second
	b = p.getY();

	float distence = sqrt(pow(x - a, 2) + pow(y - b, 2)); // Formula for finding a distance between 2 points

	return distence;
}

