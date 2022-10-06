/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#include <iostream>
#include "Shape.h"
using namespace std;
#pragma once
class Circle : public Shape
{
private:
	float radius;
public:
	void setRadius(float);
	Circle(float);                       // constractor
	float area()const override;
	bool isSpecial()const override;      // when the circle is canonical
	void printSpecial()const override;
};