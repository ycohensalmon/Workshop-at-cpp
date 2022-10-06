/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 6 Question 1
*/
#include "PartTime.h"
#include "Employee.h"

PartTime::PartTime() : Employee("", 0, 0) // default constractor
{
	salary = 0;
	hours = 0;
}

PartTime::PartTime(string myName, int myId, int mySeniority, int mySalary, float myHours) : Employee(myName, myId, mySeniority) // constractor
{
	salary = mySalary;
	hours = myHours;
}

void PartTime::setSalary(const int _salary)
{
	if (_salary < 0) // They are negative wages
		throw "ERROR";
	else
		salary = _salary;
}

void PartTime::setHours(const float _hours)
{
	if (_hours < 0) // They are the negative time
		throw "ERROR";
	else
		hours = _hours;
}

const int PartTime::getSalary()
{
	return salary;
}

const float PartTime::getHours()
{
	return hours;
}

istream& operator>>(istream& is, PartTime& time)
{
	is >> (Employee&)time; // Calls the output function of the parent function
	is >> time.hours >> time.salary;

	if (time.getId() < 0)
		throw "ERROR\n";

	if (time.getSeniority() < 0)
		throw "ERROR\n";

	time.setHours(time.hours);
	time.setSalary(time.salary);
	time.setPay(time.hours * time.salary);

	return is;
}

ostream& operator<<(ostream& os, PartTime& time)
{
	os << (Employee&)time;  // Calls the input function of the parent function
	os << "Hours: " << time.getHours() << endl
	   << "Salary per Month: " << time.getPay() << endl;

	return os;
}
