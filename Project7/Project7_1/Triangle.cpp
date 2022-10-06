/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include "Triangle.h"
#include "Shape.h"
using namespace std;

float Triangle::area() const
{
	float a_to_b = getPoint(0).distance(getPoint(1));                   // The distance between point A and B.
	float b_to_c = getPoint(0).distance(getPoint(2));                   // The distance between point B and C.
	float c_to_a = getPoint(1).distance(getPoint(2));                   // The distance between point C and A.
	float denominator = 2 * a_to_b * b_to_c;
	float numerator = pow(a_to_b, 2) + pow(b_to_c, 2) - pow(c_to_a, 2);
	float angle = acos(numerator / denominator);                        // the engle
	return (a_to_b * b_to_c * sin(angle)) / 2;                          // the area
}

bool Triangle::isSpecial() const
{
	float a_to_b, b_to_c, c_to_a;

	a_to_b = getPoint(0).distance(getPoint(1));
	b_to_c = getPoint(0).distance(getPoint(2));
	c_to_a = getPoint(1).distance(getPoint(2));

	if (a_to_b == b_to_c && c_to_a == b_to_c)   // If the triangle is equal to the sides
		return true;
	else
		return false;
}

void Triangle::printSpecial() const
{
	if (isSpecial() == true)
		cout << "An isosceles triangle with a side length " << getPoint(0).distance(getPoint(1)) << endl;
}