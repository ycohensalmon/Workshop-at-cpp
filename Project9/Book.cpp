/*
itzchak walles 021996954
Workshop in C++
Exercise 9.2
library with binary search tree. adding a abook, removing a book, and print entire library(all the tree) in order.
*/


#include "Book.h"

//defult cstr
Book::Book()
{
	code = 0;
	name = "0";
	author = "0";
}


//checking by alphabet of the authro name and the book name and finaly by the code
bool Book::operator>(Book myBook)
{
    //firstable checking by the authors name
	if (author > myBook.author)
		return true;
    // if is same author, checking by the books name
	if (author == myBook.author)
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


bool Book::operator<(Book myBook)
{
	return !((*this) >= myBook);
}


bool Book::operator>=(Book myBook)
{
	return (*this) > myBook || (*this) == myBook;
}



bool Book::operator<=(Book myBook)
{
	return !((*this) > myBook);
}


bool Book::operator==(Book myBook)
{
	return author == myBook.author && name == myBook.name && code == myBook.code;
}


bool Book::operator!=(Book myBook)
{
	return !((*this) == myBook);
}


std::istream& operator>>(istream& is, Book& myBook)
{
	int tmpCode;
	string tmpAuthor, tmpName;
	
	is >> tmpCode >> tmpAuthor >> tmpName;

	myBook.author = tmpAuthor;
	myBook.name = tmpName;
	myBook.code = tmpCode;

	return is;
}

//print the all ditailes of the book
std::ostream& operator<<(ostream& os, Book& myBook)
{
	os << myBook.code << " " << myBook.author << " " << myBook.name << endl;
	return os;
}
