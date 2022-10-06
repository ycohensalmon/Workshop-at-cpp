/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include <iostream>
#include "Shape.h"
using namespace std;

#pragma once
class Triangle : public Shape
{
public:
	Triangle() : Shape(3) {};          // constructor
	float area()const override;        // Calculate the area of the triangle
	bool isSpecial()const override;    // Checks whether the triangle is equilateral
	void printSpecial()const override; // Prints the special feature
};