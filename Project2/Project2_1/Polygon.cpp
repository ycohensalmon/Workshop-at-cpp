#include "Polygon.h"
#include <iostream>
#include <cmath>

void Polygon::addPoint(int index, int x, int y)
{
	cordinates[index].setX(x);  // add the x in tha array
	cordinates[index].setY(y); // add the y in the array
}

bool Polygon::equal(Polygon second)
{
	bool flag = false;

	for (int i = 0; i < side; i++)                                        // advance the first array to compare
	{
		for (int j = 0; j < side ; j++)                                 // advance the second array to compare
		{
			if (cordinates[i].getX()== second.cordinates[i].getX() && // when there are a point equal
				cordinates[i].getY() == second.cordinates[i].getY())
			{
				flag = true;                // the point was fuond
				break;                     // exit from the second 'for' because the point was found
			}
		}
		if (flag == false)return false;  // if there arn't a equal point, return false

		flag = false;                  // to check the next time
	}
	return true;
}

int Polygon::getSide() { return side; }

int Polygon::perimeter()
{
	float sum = 0;
	int i = 0;

	for (i; i < side - 1; i++)                          // the sum of the sides
		sum += cordinates[i].distence(cordinates[i+1]);
	sum += cordinates[i].distence(cordinates[0]);

	return round(sum);  // Rounded to the nearest integer
}

Polygon::~Polygon() // destructeur
{
	if (side)                 // when the array isn't empty
	{
		delete[]cordinates; // delete the array 
		std::cout << "in destructor\n";
	}	
}

Polygon::Polygon(int _side) // constructeur
{
	while (_side <= 2) // There is no polygon that has less than 2 sides
	{
		std::cout << "ERROR\nenter a new number of sides:\n";
		std::cin >> _side;
	}

	side = _side;
	cordinates = new Point[_side];  // ctreat the array
	std::cout << "in constructor\n";
}

Polygon::Polygon() // Default constructeur
{
	side = 0;
	cordinates->setX(0);
	cordinates->setY(0);
}

Polygon::Polygon(const Polygon& second) // copy-constructeur
{
	side = second.side;
	cordinates = new Point[side];     // creat a new array

	for (int i = 0; i < second.side; i++)
	{
		cordinates[i].setX(second.cordinates[i].getX()); // Copies what is in the first and transfers to the second
		cordinates[i].setY(second.cordinates[i].getY());
	}

	std::cout << "in copy-constructor\n";
}

