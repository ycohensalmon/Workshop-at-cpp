/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include <iostream>
using namespace std;
#pragma once

class Point
{
protected:
	int x;
	int y;
public:
	Point();         // default constructor
	Point(int, int); // constructor
	void setX(int myX);
	void setY(int myY);
	int getX();
	int getY();
	float distance(Point p);//distance between tow points
	friend istream& operator>>(istream&, Point&);
};