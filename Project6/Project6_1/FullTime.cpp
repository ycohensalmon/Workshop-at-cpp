/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 6 Question 1
*/
#include "FullTime.h"
#include "Employee.h"

FullTime::FullTime() : Employee("", 0, 0) // default constractor
{
	salaryYear = 0;
}

FullTime::FullTime(string myName, int myId, int mySeniority, int mySalaryYear) : Employee(myName, myId, mySeniority) // constractor
{
		salaryYear = mySalaryYear;
}

void FullTime::setSalaryYear(const int _salaryYear)
{
	if (_salaryYear < 0) // If the seniority years are negative
		throw "ERROR";
	else
		salaryYear = _salaryYear;
}

const int FullTime::getSalaryYear()
{
	return salaryYear;
}

istream& operator>>(istream& is, FullTime& time)
{
	is >> (Employee&)time; // Calls the input function of the parent function
	is >> time.salaryYear;

	if (time.getId() < 0)
		throw "ERROR\n";

	if (time.getSeniority() < 0)
		throw "ERROR\n";

	time.setSalaryYear(time.salaryYear);
	time.setPay(time.salaryYear / 12);

	return is;
}

ostream& operator<<(ostream& os, FullTime& time)
{
	os << (Employee&)time; // Calls the output function of the parent function
	os << "Salary per Month: " << time.getPay() << endl;

	return os;
}
