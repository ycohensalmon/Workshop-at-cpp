#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

Rational Rational::reduction(Rational num)
{
	/***********The function reduces a rational number to the lowest reduction**************/


	if (abs(num.numerator) < abs(num.denominator))                 // When the denominator is larger than the numerator
	{
		for (int i = num.numerator; i > 0; i--)
		{
			if (!(num.numerator % i) && !(num.denominator % i)) // When the numerator and denominator are divided by the highest number
			{
				num.numerator = num.numerator / i;            // Divides the numerator
				num.denominator = num.denominator / i;       // Divides the denominator
				return num;
			}
		}
	}
	else     // When the numerator is larger than the denominator
	{
		for (int i = abs(num.denominator); i > 0; i--)
		{
			if (!(num.numerator % i) && !(num.denominator % i)) // When the numerator and denominator are divided by the highest number
			{
				num.numerator = num.numerator / i;            // Divides the numerator
				num.denominator = num.denominator / i;       // Divides the denominator
				return num;
			}
		}
	}
}

void Rational::setNumerator(int numtemp)
{
	numerator = numtemp;
}

void Rational::setDenominator(int dentemp)
{
	if (!dentemp) // When the denominator is 0 then we set 1
		dentemp = 1;

	denominator = dentemp;
}

void Rational::getNumerator()
{
	std::cout << numerator;
}

void Rational::getDenominator()
{
	cout << denominator << " ";
}

Rational Rational::add(Rational r2)
{
	Rational temp;

	if (!(numerator +r2.numerator)) // When the numerator is equal to 0
	{
		temp.numerator = 0;
		temp.denominator = 1;
		return temp;
	}

	if (denominator==r2.denominator)                   // When the 2 denominators are equal
	{
		temp.denominator = denominator;              // The denominator remains the same
		temp.numerator = numerator + r2.numerator;  // Connection of 2 numerator
	}
	else // When the denominators are not equal
	{
		temp.denominator = denominator * r2.denominator;                           // double the denominators themselves
		temp.numerator = numerator * r2.denominator + r2.numerator * denominator; // multiply the numerators by denominators and connect
	}
	
	temp = Rational::reduction(temp); // Reduces the fracture
	return temp;
}

void Rational::print()
{
	Rational::getNumerator(); 
	std::cout << "/";
	Rational::getDenominator();
}

bool Rational::equal(Rational r2)
{

	double temp1 = (double)numerator / denominator;  //Displays the fraction as a decimal number
	double temp2 = (double)r2.numerator / r2.denominator; 
	
	if (temp1==temp2) // When the numbers are equal
	{
		return true;
	}
	return false;
}
