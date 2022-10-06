/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
*/
#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle :public Shape
{
public:
	Rectangle() :Shape(4) {};         // constractor
	float area()const override;       // area calculation
	bool isSpecial()const override;   // If the Rectangle is equal to the sides
	void printSpecial()const override;
};