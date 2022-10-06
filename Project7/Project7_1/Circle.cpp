/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include "Circle.h"
#include "Shape.h"
using namespace std;

void Circle::setRadius(float _radius)
{
	while (_radius < 0) // while the radius is not correct
	{
		try
		{
			throw "ERROR - radius cannot be less than 0 \nEnter radius:\n";
		}
		catch (const char* msg)
		{
			cout << msg;        // print the messqge error
			cin >> _radius;
		}
	}
	radius = _radius;
}

Circle::Circle(float _radius) : Shape(1) { radius = _radius; }       // constractor

float Circle::area() const { return (float)radius * radius * 3.14; } // the area

bool Circle::isSpecial() const
{
	if (getPoint(0).getX() == 0 && getPoint(0).getY() == 0) // If the circle is canonical
		return true;
	else
		return false;
}

void Circle::printSpecial() const
{
	if (isSpecial() == true)
		cout << "A canonical circle with a radius " << radius << endl;
}