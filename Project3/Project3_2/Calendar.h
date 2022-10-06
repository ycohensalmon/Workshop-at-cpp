/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 3 Question 2
*/
#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Calendar
{
private:
	int day;
	int month;
	int year;
	Calendar& check(Calendar&);    // Function to check if the date exceeds the ranges
	void setDay(int const myDay);
	void setMonth(int const myMonth);
	void setYear(int const myYear);
public:
	const int getDay()const;
	const int getMonth()const;
	const int getYear()const;
	Calendar& setDate(const int, const int, const int);
	Calendar(int, int, int);                // constractor
	Calendar(const Calendar&);              // copy-constractor
	//Calendar(Calendar&&);
	void print()const;                      // print the date
	Calendar& operator++();                 // add one day prefix
	Calendar operator++(int const);         // add one day postfix
	Calendar& operator+=(int);              // add a number of days
	const bool operator>(Calendar&)const;   // calcul if the original date is greater than the date entered
	const bool operator<(Calendar&)const;   // calcul if the original date is smaller than the date entered
	const bool operator==(Calendar&)const;  // Checks if the dates are equal
};