/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include "Rectangle.h"
#include "Shape.h"
using namespace std;

//area calculation
float Rectangle::area()const
{
	//side a * side b
	return getPoint(0).distance(getPoint(1)) * getPoint(1).distance(getPoint(2));
}

// If the triangle is equal to the sides
bool Rectangle::isSpecial() const
{
	//side a == side b
	return getPoint(0).distance(getPoint(1)) == getPoint(1).distance(getPoint(2));
}

void Rectangle::printSpecial()const
{
	if (isSpecial())
		cout << "Square with side length " << getPoint(0).distance(getPoint(1)) << endl;
}
