#pragma once
#include "Point.h"
class Polygon
{
private:
	Point* cordinates;
	int side;
public:
	int getSide();
	int perimeter();
	void addPoint(int, int, int); // the fonction add a point to the array 
	bool equal(Polygon);         // the fonction tell me if the two polygons are equal
	Polygon(const Polygon&);    // copy-constructor
	Polygon(int);              // constructor
	Polygon();                // default-constructor
	~Polygon();              // destructor
};