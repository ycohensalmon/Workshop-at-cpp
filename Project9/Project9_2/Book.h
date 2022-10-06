/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 2
The project adds numbers to a binary tree and also deletes and searches for books
*/
#pragma once
#include "SearchTree.h"
#include <iostream>
using namespace std;

class Book
{
	string composer;
	string name;
	int code;

public:
	Book();
	bool operator>(Book);
	bool operator<(Book);
	bool operator>=(Book);
	bool operator<=(Book);
	bool operator==(Book);
	bool operator!=(Book);

	friend std::istream& operator>>(istream& is, Book& myBook);
	friend std::ostream& operator<<(ostream& os, Book& myBook);
};

