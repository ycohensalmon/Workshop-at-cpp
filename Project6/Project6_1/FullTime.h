/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 6 Question 1
*/
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;
#pragma once
class FullTime : public Employee
{
private:
	int salaryYear;
public:
	FullTime();                   // default constractor
	FullTime(string,int,int,int); // constractor
	void setSalaryYear(const int);
	const int getSalaryYear();
	friend istream& operator>>(istream&, FullTime&);
	friend ostream& operator<<(ostream&, FullTime&);
};