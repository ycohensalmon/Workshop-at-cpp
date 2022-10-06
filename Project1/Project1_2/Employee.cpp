#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
#pragma warning (disable:4996)

int Employee::getId()        { return id; }

char* Employee::getName()    { return name; }

float Employee::getSalaire() { return salaire;}

int Employee::getHours()     { return hours; }

float Employee::getAmount()  { return amount; }

void Employee::setId(int id_)            { id = id_; }

void Employee::setName(char name_[])     { strcpy_s(name, name_); }

void Employee::setSalaire(float salaire_){ salaire = salaire_; }

void Employee::setHours(int hours_)      { hours = hours_; }

void Employee::setAmount(float amount_)  { amount = amount_; }

/*** The function returns the wage which is the working hours multiplied by the wage per hour ***/
float Employee::sum_salaire(float salaire_, int hours_) { return salaire_ * hours_; }

float Employee::salaire_with_bonus()
{
/*** The function returns the final wage that includes the percentage of the amount it entered ***/

	float sum = sum_salaire(salaire, hours);
	
	if (amount <= 1000)                // When the income is less than 1000
	{
		sum += amount * 0.1;
		return sum;
	}
	if (amount <= 2000)             // When the income is less than 2000
	{
		sum += 1000 * 0.1 + (amount - 1000) * 0.15;
		return sum;
	}
	if (amount <= 4000)          // When the income is less than 4000
	{
		sum += 1000 * 0.1 + 1000*0.15 +(amount - 2000) * 0.2;
		return sum;
	}
	if (amount <= 5000)       // When the income is less than 5000
	{
		sum += 1000 * 0.1 + 1000 * 0.15 +  2000 * 0.2 + (amount - 4000)*0.3;
		return sum;
	}
	                       // When the income is above 5000 
	sum += 1000 * 0.1 + 1000 * 0.15 + 2000 * 0.2 + 1000 * 0.3 + (amount - 5000) * 0.4;
	return sum;
}

