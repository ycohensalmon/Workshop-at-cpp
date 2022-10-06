/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 2
The project adds numbers to a binary tree and also deletes and searches for books
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
		char choice;
		cout << "enter a-e\n";
		cin >> choice;
		//the book for the actions
		Book myBook;
		if (choice == 'e') // end the program
			break;

		switch (choice)
		{
		case 'a':cout << "enter a book\n"; cin >> myBook; library.add(myBook); // adding a book to the library
			break;
		case 'b':
			cout << "enter a book\n";cin >> myBook;                            // removing a book from the library
			if (!library.search(myBook))
				cout << "not exist";
			library.remove(myBook);
			break;
		                                                                       //searching for a book in the library
		case 'c':cout << "enter a book\n"; cin >> myBook; cout << (!library.search(myBook)) ? "not exist\n" : "exist\n";
			break;
		case 'd':library.inOrder(); 	                                       //printing the entier library
			break;
		default:
			cout << "error\n";
		}
	}
}

/*
* /////// running exemple ///////// *
enter a-e
a
enter a book
aa aa 11
enter a-e
d
11 aa aa
 enter a-e
3
error
enter a-e
c
enter a book
aa
aa
11
0enter a-e
e

Sortie de C:\Users\ycohe\Documents\Visual Studio 2019\Semestre 2\Project9\Project9_2\Debug\Project9_2.exe (processus 31340). Code : 0.
Pour fermer automatiquement la console quand le débogage s'arrête, activez Outils->Options->Débogage->Fermer automatiquement la console à l'arrêt du débogage.
Appuyez sur une touche pour fermer cette fenêtre. . .

*/