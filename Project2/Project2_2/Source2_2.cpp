/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 2 Question 2
The project initializes 3 vectors and lets me do operations with them,
1-boot, 2-comparison, 3-doubling, 4-threading, 5-deleting everything,
6-deleting an index, 7-replacing an index, 8-adding an index, and 0 to stop The project
*/
#include "Vector.h"
#include <iostream>
using namespace std;

enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast, at, insert
};

int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);           // inisialize the v1
		v2.insert(i + 4);      // inisialize the v2
	}
	int choice, val, index;
	cout << "enter your choice 0-8:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment:                 // When you press 1, initializing a vector into one another
			            v3.assign(v1); 
			break;
		case isEqual:                    // When you press 2, check if the 2 vectors are equal
		{
			if (v1.isEqual(v2))
				cout << "v1==v2\n";
			else
				cout << "v1!=v2\n";
		}
			break;
		case mult:		                 // When pressing 3, multiply the vectors
			         cout << "v1*v2=" << v1.strcatcat(v2) << endl;
			break;
		case add:	                     //  When you press 4, you add a vector to each other
			         v3.assign(v1.strnewcat(v2));
			break;
		case clear:		                 // When you press 5, you delete a vector
			         v1.clear();
			break;
		case delLast:                    // When you press 6, you delete the last vector
			         v2.delLast();
			break;
		case at:                         // When you press 7, it changes the vector in a particular index
		{
			cout << "enter index:" << endl;
			cin >> index;
			cout << "enter value:" << endl;
			cin >> val;
			v3.at(index) = val;
		}
			break;
		case insert:                     // When you press 8, you add a vector within the class
		{
			cout << "enter value:" << endl;
			cin >> val;
			v3.insert(val);
		}
			break;
		default: cout << "ERROR";
		}

		v1.print();
		v2.print();
		v3.print();
		cout << "enter your choice 0-8:\n";
		cin >> choice;
	}
	return 0;
}
