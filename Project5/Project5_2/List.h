/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 5 Question 1
*/
#include <iostream>
using namespace std;
#pragma once

class List
{
protected:

	class Link
	{
	public:
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);

		int value;
		Link* next;
	};
public:
	List();             // constructors
	List(const List&);  // copy-constractor
	~List();            // destructor

	void add_end(int value);             // add to the end of the list 
	int firstElement() const;            // return the first element in the list
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void insert(int);                    // add from the begining of the lise
	List& operator=(const List&);
	friend ostream& operator<<(ostream& os, const List& lst);
	friend istream& operator>>(istream& is, List& lst);
protected:

	Link* head;
};
