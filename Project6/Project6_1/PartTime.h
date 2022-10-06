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
class PartTime : public Employee
{
private:
	int salary;
	float hours;
public:
	PartTime();                             // default constractor
	PartTime(string, int, int, int, float); // constractor

	// The functions of "set"
	void setSalary(const int);
	void setHours(const float);

	// The functions of "get"
	const int getSalary();
	const float getHours();

	friend istream& operator>>(istream&, PartTime&);
	friend ostream& operator<<(ostream&, PartTime&);
};