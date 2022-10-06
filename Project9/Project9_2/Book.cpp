/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 2
The project adds numbers to a binary tree and also deletes and searches for books
*/
#include "Book.h"

Book::Book() { code = 0; name = "0"; composer = "0"; }                                // default constractor

bool Book::operator<(Book myBook) { return !((*this) >= myBook); }

bool Book::operator<=(Book myBook) { return !((*this) > myBook); }

bool Book::operator!=(Book myBook) { return !((*this) == myBook); }

bool Book::operator>=(Book myBook) { return (*this) > myBook || (*this) == myBook; }

bool Book::operator==(Book myBook) { return composer == myBook.composer && name == myBook.name && code == myBook.code; }

//checking by alphabet of the authro name and the book name and finaly by the code
bool Book::operator>(Book myBook)
{
	//firstable checking by the composers name
	if (composer > myBook.composer)
		return true;
	// if is same composer, checking by the books name
	if (composer == myBook.composer)
	{
		if (name > myBook.name)
			return true;
		//if is same name, checking by the code
		if (name == myBook.name)
		{
			if (code > myBook.code)
				return true;
		}
	}

	return false;
}

std::istream& operator>>(istream& is, Book& myBook)
{
	is >> myBook.composer >> myBook.name >> myBook.code;
	return is;
}

std::ostream& operator<<(ostream& os, Book& myBook) //print the all ditailes of the book
{
	os << myBook.code << " " << myBook.composer << " " << myBook.name << endl;
	return os;
}
