/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;
#pragma once

class Shape
{
	int numOfPoint;
	Point* point;
public:
	void setNumOfPoint(int);
	int getNumOfPoint()const;
	Point* getPoint();
	Shape();                 // default constructor
	Shape(int);              // constructor
	Shape(const Shape&);     // copy-constractor
	Shape(Shape&&) noexcept; // move-constractor
	virtual ~Shape();
	virtual float area()const = 0;        // pure virtual
	virtual bool isSpecial()const = 0;    // pure virtual
	virtual void printSpecial()const = 0; // pure virtual
	friend ostream& operator<<(ostream&, Shape*);
	Point getPoint(int)const;//getting one point from the array of the points by index
};