/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 6 Question 1
*/
#include <iostream>
#include <string>
using namespace std;
#pragma once

class Employee
{
private:
	string name;
	int id;
	int seniority;
	float pay;
public:
	Employee(string, int, int);

	// The functions of "get"
	const string getName();
	const int getId();
	const int getSeniority();
	const float getPay();

	// The functions of "set"
	void setName(const string);
	void setId(const int);
	void setSeniority(const int);
	void setPay(const float);
	
	float salaryAfterBonus();
	friend ostream& operator<<(ostream&, Employee&);
	friend istream& operator>>(istream&, Employee&);
};