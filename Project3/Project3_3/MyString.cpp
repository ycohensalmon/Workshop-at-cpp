#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#pragma warning (disable:4996)
using std::cout;
using std::endl;

void MyString::setString(const char* str) // inisialize the string
{
	len = strlen(str);
	array = new char[len + 1];            // +1 for the \0 in the end of the array
	strcpy(array, str);
}

const int MyString::compare(const MyString& str)
{
	char* temp1 = new char[str.len + 1];  // creat a temperory array

	for (int i = 0; i < str.len; i++)     // len times
	{
		if (str.array[i] >= 'A' && str.array[i] <= 'Z') // if there are a lettre uppercase
			temp1[i] = str.array[i] + 32;               // turn them to lowercase lattre
		else
			temp1[i] = str.array[i];                    // if there arn't a lettre uppercase do anything
	}
	temp1[str.len] = '\0';

	char* temp2 = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		if (array[i] >= 'A' && array[i] <= 'Z')
			temp2[i] = array[i] + 32;
		else
			temp2[i] = array[i];
	}
	temp2[len] = '\0';

	return strcmp(temp1, temp2);  // the comparaison
}

MyString::MyString(const char* str) { setString(str); } // constructor

MyString::MyString() : MyString("") {}    // default constructor

MyString::MyString(const MyString& str)   // copy constructor
{
	len = str.len;
	array = new char[len + 1];
	strcpy(array, str.array);
}

MyString::MyString(MyString&& s) noexcept       // move constructor
{
	array = s.array;                   // steal (dont copy) rvalue's data
	len = s.len;
	s.array = nullptr;
}

MyString::~MyString()                  { if (len)delete[] array; }

const int MyString::getLen() const     { return len; }

const char* MyString::getArray() const { return array; }

const bool MyString::operator<(const MyString& str)
{
	if (this->compare(str) < 0)  // if the string 1 is smaller 
		return true;
	else
		return false;
}

const bool MyString::operator>(const MyString& str)
{	
	if (this->compare(str) > 0)  // if the string 1 is larger 
		return true;
	else
		return false;
}

const bool MyString::operator<=(const MyString& str)
{
	if (this->compare(str) < 0 || !this->compare(str))  // if the string 1 is smaller or equal
		return true;
	else
		return false;
}

const bool MyString::operator>=(const MyString& str)
{
	if (this->compare(str) > 0 || !this->compare(str)) // if the string 1 is larger or equal
		return true;
	else
		return false;
}

const bool MyString::operator==(const MyString& str)
{
	if (!this->compare(str))  // if the string 1 is equal to the second string
		return true;
	else
		return false;
}

const bool MyString::operator!=(const MyString& str)
{
	if (this->compare(str))  // if the string 1 is not equal to the second string
		return true;
	else
		return false;
}

char& MyString::operator[](int const index)
{
	return array[index];  // change the index
}

const MyString MyString::insert(int index, const char* str)
{
	MyString temp;                           // creat a temperory string
	temp.len = strlen(str) + strlen(array);  // inisialise the len
	temp.array = new char[temp.len + 1]{};   

	strncpy(temp.array, str, index);                        // Conveys the first part of the first word
	temp.array[len] = '\0';
	strncat(temp.array, (*this).getArray(), strlen(array)); // Conveys the seconde word
	strcat(temp.array, str + index);                        // Conveys the seconde part of the first word

	return MyString(temp); // return the new word
}

void MyString::print()const
{
	cout << array << endl;
}