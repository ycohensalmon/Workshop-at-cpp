/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include <iostream>
#include "Shape.h"
#include"Point.h"
using namespace std;

void Shape::setNumOfPoint(int num)
{
	if (num < 0) // if the num of point is not correct
		throw "ERROR - There is no shape with less than 2 points\n";
	else
		numOfPoint = num;
}

int Shape::getNumOfPoint() const { return numOfPoint; }

Point* Shape::getPoint() { return point; }

Shape::Shape() // default constructor
{
	numOfPoint = 0;
	point = nullptr;
}

Shape::Shape(int num)    // constructor
{
	setNumOfPoint(num);
	point = new Point[num];

	cout << "Enter values of " << num << " points:\n";

	for (int i = 0; i < num; i++)
		cin >> point[i];
}

Shape::Shape(const Shape& shape)
{
	setNumOfPoint(shape.numOfPoint);
	point = new Point[numOfPoint];

	for (int i = 0; i < numOfPoint; i++)
	{
		point[i].setX(shape.point[i].getX()); // copy the valus
		point[i].setY(shape.point[i].getY());
	}
}

Shape::Shape(Shape&& shape) noexcept // move constractor
{
	setNumOfPoint(shape.numOfPoint);
	point = shape.point;
	shape.point = nullptr;
}

Shape::~Shape()
{
	if(point) delete[] point;
}

//getting one point from the array of the points by index
Point Shape::getPoint(int p)const
{
	return point[p];
}

ostream& operator<<(ostream& os, Shape* myShape)
{
	os << "points: ";

	for (int i = 0; i < (*myShape).getNumOfPoint(); i++)
		os << "(" << (*myShape).point[i].getX() << "," << (*myShape).point[i].getY() << ") "; // print the cordinatot - (x,y)

	return os;
}