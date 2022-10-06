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
		int value;                          // the value
		Link* next;                         // next pointer

		Link(int linkValue, Link* nextPtr); // constructor
		Link(const Link&);                  // copy-constractor
	};
public:
	
	List();              // constructors
	List(const List&);   // copy-constructors
	~List();             // destructor

	// operations
	void add(int value);
	bool isEmpty() const;
	void insert(int);
	void remove(int);
	List operator=(const List&)const;

	friend ostream& operator<<(ostream& os, List& lst);
	friend istream& operator>>(istream& is, List& lst);
protected:
	// data field
	Link* head;
};
