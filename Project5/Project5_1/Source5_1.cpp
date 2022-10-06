/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 5 Question 1
The function picks numbers in descending order
and puts them in a linked list and allows you to put numbers
in the list and also delete numbers from the list
*/
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;                                      // Collects numbers in descending order
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);                         // Puts a number on the list
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);                     // Deletes a number from the list
			}
			catch (const char* msg)
			{
				cout << msg << endl;                 // If the number does not exist you will get an error message
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}
/*

  ////Running example////

enter the list values
9
8
7
6
5
4
4
choose 0-2
1
enter a value to insert
8
9 8 8 7 6 5 4
choose 0-2
1
enter a value to insert
4
9 8 8 7 6 5 4 4
choose 0-2
2
enter a value to remove
7
9 8 8 6 5 4 4
choose 0-2
2
enter a value to remove
9
8 8 6 5 4 4
choose 0-2
2
enter a value to remove
4
8 8 6 5 4
choose 0-2
2
enter a value to remove
4
8 8 6 5
choose 0-2
2
enter a value to remove
4
value not found
8 8 6 5
choose 0-2
0
*/