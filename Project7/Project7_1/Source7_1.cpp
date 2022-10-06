/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 7 Question 1
The project asks me to enter the number of shapes I want
and finally gives me the area of the dots
and also tells me if the shape entered is a special shape
*/
#include <iostream>
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

enum Shapes {CIRCLES = 1, TRIENGLES = 3, RECTENGLES = 4};

void cheak(int num);

int main()
{
	int numOfShape;
	cout << "How many shapes you would like to define?\n";

	cin >> numOfShape;
	cheak(numOfShape);
	Shape** forme = new Shape * [numOfShape]; // Creates a two-dimensional array of shapes
	int num;
	float radiuss;
	for (int i = 0; i < numOfShape; i++)
	{
		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4\n";
		cin >> num;

		
		switch (num)
		{
		case CIRCLES:
		{
			cout << "Enter radius:\n";
			cin >> radiuss;

			forme[i] = new Circle(radiuss); // Creates an array of circles with a radius
		}
			break;
		case TRIENGLES:
		{
			forme[i] = new Triangle();     // Forms an array of triangles
		}
			break;
		case RECTENGLES:
		{
			forme[i] = new Rectangle();    // Creates an array of rectangles
		}
			break;
		default: cout << "invalid input\n"; i--; // Update the 'for'
			break;
		}
	}

	for (int i = 0; i < numOfShape; i++)
	{
  		cout << forme[i] << " area is: " << forme[i]->area() << endl; // print the area
		if (forme[i]->isSpecial())
			forme[i]->printSpecial();                                 // If the shape is special you will print the special
		cout << endl;
		
	}
	for (int i = 0; i < numOfShape; i++)
		delete forme[i];                                              // Deletes the array

	delete[] forme;                                                   // Deletes the main array
	
}

void cheak(int num) // if the num is not correct
{
	while (num < 0)
	{
		try
		{
			throw "ERROR - num of shapes incorrect !\n";
		}
		catch (const char* msg)
		{
			cout << msg;
		}
		cin >> num;
	}
}

/*

How many shapes you would like to define?
4
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle û 4
1
Enter radius:
14
Enter values of 1 points:
(7.8)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle û 4
3
Enter values of 3 points:
.1.1.
.4.4.
.8.8.
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle û 4
4
Enter values of 4 points:
.4.4.
.9.9.
.8.8.
.6.6.
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle û 4
1
Enter radius:
4.7
Enter values of 1 points:
.0.0.
points: (7,8)  area is: 615.44

points: (1,1) (4,4) (8,8)  area is: 0

points: (4,4) (9,9) (8,8) (6,6)  area is: 10

points: (0,0)  area is: 69.3626
A canonical circle with a radius 4.7

Sortie de C:\Users\ycohe\Documents\Visual Studio 2019\Semestre 2\Project7\Project7_1\x64\Debug\Project7_1.exe (processus 24924). Code : 0.
Pour fermer automatiquement la console quand le débogage s'arrête, activez Outils->Options->Débogage->Fermer automatiquement la console à l'arrêt du débogage.
Appuyez sur une touche pour fermer cette fenêtre. . .
*/