/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 6 Question 1
*/
#include "Employee.h"

Employee::Employee(string myName, int myId, int mySeniority) // constractor
{
	setName(myName);
	setId(myId);
	setPay(0);
	setSeniority(mySeniority);
}

const string Employee::getName() { return name; }

const int Employee::getId() { return id; }

const int Employee::getSeniority() { return seniority; }

const float Employee::getPay() { return pay; }

void Employee::setName(const string _name) { name = _name; }

void Employee::setId(const int _id) { id = _id; }

void Employee::setSeniority(const int _seniority) { seniority = _seniority; }

void Employee::setPay(const float _pay) { pay = _pay; }

float Employee::salaryAfterBonus()
{
	int bonus;

	if (getSeniority() > 5)
		bonus = 1.25 * getPay(); // If he has more than 5 years of seniority
	else
		bonus = 500 + getPay();

	return bonus;                // Returns the salary + bonus
}

ostream& operator<<(ostream& os, Employee& employe)
{
	os << "\nEmployee: " << employe.name << endl
		<< "Employee ID: " << employe.id << endl
		<< "Years Seniority: " << employe.seniority << endl;
	return os;

}

istream& operator>>(istream& is, Employee& employe)
{
	cout << "Enter employee details:\n";

	is >> employe.name >> employe.id >> employe.seniority;
	employe.setName(employe.name);
	employe.setId(employe.id);
	employe.setSeniority(employe.seniority);

	return is;
}
