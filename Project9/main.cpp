/*
itzchak walles 021996954
Workshop in C++
Exercise 9.2
library with binary search tree. adding a abook, removing a book, and print entire library(all the tree) in order.
*/


#include "Book.h"
#include "SearchTree.h"
#include<iostream>
using namespace std;

int main()
{
	SearchTree<Book> library;//binary search tree for the library

	while (1)
	{
	    //the choice of the user
		char choice;
		cout << "enter a-e\n";
		cin >> choice;
		//the book for the actions
		Book myBook;
		//ending the program
		if (choice == 'e')
			break;


		switch (choice)
		{
		//adding a book to the library
		case 'a':
		{
			cout << "enter a book\n";
			cin >> myBook;
			library.add(myBook);
			break;
		}
		//removing a book from the library
		case 'b':
		{
			cout << "enter a book\n";
			cin >> myBook;
			if (!library.search(myBook))
				cout << "not exist";
			library.remove(myBook);
			break;
		}
		//searching for a book in the library
		case 'c':
		{
			cout << "enter a book\n";
			cin >> myBook;
			if (!library.search(myBook))
				cout << "not exist\n";
			else
				cout << "exist\n";
			break;
		}
		//printing the entier library
		case 'd':
		{
			library.inOrder();
			break;
		}
		default: {cout << "error\n"; }
		}
	}
}

/*
enter a-e
a
enter a book
1 a a
enter a-e
a
enter a book
2 b b
enter a-e
a
enter a book
3 c c
enter a-e
a
enter a book
1 a b
enter a-e
a
enter a book
5 f b
enter a-e
d
1 a a
 1 a b
 2 b b
 3 c c
 5 f b
 enter a-e
a
enter a book
10 b g
enter a-e
d
1 a a
 1 a b
 2 b b
 10 b g
 3 c c
 5 f b
 enter a-e
2
error
enter a-e
b
enter a book
5 f b
enter a-e
c
enter a book
3 c c
exist
enter a-e
e

C:\Users\איציק\source\repos\Project3\Debug\targil 9.2.exe (process 13048) exited with code 0.
Press any key to close this window . . .

*/