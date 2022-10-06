#include <iostream>
#include <iomanip>
using namespace std;
/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 4 Question 1
*/
#pragma once
class Clock
{
private:
	int hour;
	int minute;
	int seconde;

public:
	// The functions of "get"
	const int getHour()const;
	const int getSeconde()const;
	const int getMinute()const;

	// The functions of "set"
	void setHour(int const myYear);
	void setMinute(int const myMonth);
	void setSeconde(int const myDay);

	Clock(int, int, int);              // constractor/default constractor
	Clock(const Clock&);               // copy-constractor

	Clock& operator+=(int);
	friend ostream& operator<<(ostream& os, Clock p);  
	friend istream& operator>>(istream& is, Clock& p);
};

