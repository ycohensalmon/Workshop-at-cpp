#include "Circle.h"
#include <cmath>
#include <iostream>

void Circle::setCenter(int x, int y)
{
	center.setX(x);  // Put the values in the point class
	center.setY(y);
}

void Circle::setRadius(int myRadius) { radius = myRadius; }

Point Circle::getCenter()            { return Point(); }

int Circle::getRadius()              { return radius; }

float Circle::area()
{
	const float PI = 3.14;

	return PI*radius*radius;   // return the area of the circle
}

float Circle::perimeter()
{
	const float PI = 3.14;

	return 2*PI*radius;    // return the perimetre of the circle
}

int Circle::onInOut(Point p)
{
	int x, y, a, b,sum;
	x = center.getX();   // The coordinate of one of the 3 circles
	a = p.getX();       // The coordinate of the inserted circle
	y = center.getY(); // The coordinate of one of the 3 circles
	b = p.getY();     // The coordinate of the inserted circle

	if (pow(x - a, 2) + pow(y - b, 2) == getRadius()* getRadius())         // If the point entered is on the circle
	{
		return 0;
	}
	else if (pow(x - a, 2) + pow(y - b, 2) < getRadius() * getRadius()) // If the point entered is inside the circle
	{
		return -1;
	}
	else                 // If the point entered is outside the circle
		return 1;
}