/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 2 Question 1
The project gets 2 polygons with their coordinates and tells me if their perimetre is equal or different
and gives the perimetre itself.
*/
#include <iostream>
#include"Point.h"
#include "Polygon.h"
using namespace std;

int main()
{
	int x, f_x, side;
	char tav1, tav2, point;

	cout << "enter number of sides:\n";
	cin >> side;
	Polygon A(side);                                // constructor

	cout << "enter the point values:\n";
	for (int i = 0; i < side; i++)
	{
		cin >> tav1 >> x >> point >> f_x >> tav2;
		A.addPoint(i, x, f_x);                     // add the point in the array
	}

	cout << "enter number of sides:\n";
	cin >> side;
	Polygon B(side);                               // constructor

	cout << "enter the point values:\n";
	for (int i = 0; i < side; i++)
	{
		cin >> tav1 >> x >> point >> f_x >> tav2;
		B.addPoint(i, x, f_x);                     // add the point in the array
	}

	if (A.getSide() == B.getSide() && A.equal(B)==false)     // when the polygons are equal
	{
		cout << "perimeter:" << A.perimeter() << endl;
		cout << "perimeter:" << B.perimeter() << endl;
	}
	else                                                    // when the polygons arn't equal
		cout << "equal.perimeter:" << A.perimeter() << endl;

	return 0;
}
