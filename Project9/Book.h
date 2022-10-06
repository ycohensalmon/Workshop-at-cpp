#pragma once
#include "SearchTree.h"
#include <iostream>
using namespace std;

class Book
{
	string author;
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

