/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 1 Question 3
The function gets coordinates of 3 circles and also gets the radius and gives me the circumference and their area,
in addition the program tells me to enter coordinates and tells me the number of times they are in circles
*/
#include <iostream>
#include"Point.h"
#include "Circle.h"
using namespace std;

int main()
{
	int x, f_x, radius;
	char tav1, tav2, point;
	Circle A,B,C;

	cout << "enter the center point and radius of 3 circles:\n";
	cin >> tav1 >> x >> point >> f_x >> tav2 >> radius; // Puts the coordinates in the first entry
	A.setCenter(x,f_x);                                // Put the coordinates in the class
	A.setRadius(radius);                              // Put the radius in the class
	cin >> tav1 >> x >> point >> f_x >> tav2 >> radius; // Puts the coordinates in the seconde entry
	B.setCenter(x, f_x);                               // Put the coordinates in the class
	B.setRadius(radius);                              // Put the radius in the class
	cin >> tav1 >> x >> point >> f_x >> tav2 >> radius; // Puts the coordinates in the third entry
	C.setCenter(x, f_x);                               // Put the coordinates in the class
	C.setRadius(radius);                              // Put the radius in the class

	cout << "perimeter :";
	cout << "  A: " << A.perimeter();             // Print the perimeter for circle A
	cout << "  B: " << B.perimeter();           // Print the perimeter for circle B
	cout << "  C: " << C.perimeter() << endl;  // Print the perimeter for circle C
	cout << "area   :";
	cout << "  A: " << A.area();             // Print the area for circle A
	cout << "  B: " << B.area();            // Print the area for circle B
	cout << "  C: " << C.area() << endl;   // Print the area for circle C
	cout << "enter points until (0,0):" << endl;

	Point cordinatot;
	int conteur_a, conteur_b, conteur_c;
	conteur_a = conteur_b = conteur_c = 0;
	bool flag = true;

	cin >> tav1 >> x >> point >> f_x >> tav2;

	if (!x && !f_x) flag = false;  // The condition to stop inserting coordinates

	while (flag == true) 
	{
		cordinatot.setX(x);    // Put the coordinates in the class
		cordinatot.setY(f_x); // Put the coordinates in the class

		if (A.onInOut(cordinatot) != 1) conteur_a++;   // Checks whether the coordinate is in circle A
		if (B.onInOut(cordinatot) != 1) conteur_b++;  // Checks whether the coordinate is in circle B
		if (C.onInOut(cordinatot) != 1) conteur_c++; // Checks whether the coordinate is in circle C

		cin >> tav1 >> x >> point >> f_x >> tav2;

		if (!x && !f_x) flag = false;            // The condition to stop inserting coordinates
	}
	
	cout << "num of points in circle:";
	cout << "  A:" << conteur_a;
	cout << "  B:" << conteur_b;
	cout << "  C:" << conteur_c;

	return 0;
}

///*
//////Running example////
//
//enter the center point and radius of 3 circles:
//(7.4)10
//(5.4)2
//(1.1)7
//perimeter :  A: 62.8  B: 12.56  C: 43.96
//area   :  A: 314  B: 12.56  C: 153.86
//enter points until (0,0):
//(7.1)
//(1.1)
//(0.8)
//(7.5)
//(5.4)
//(0.0)
//num of points in circle:  A:5  B:1  C:3
//*/