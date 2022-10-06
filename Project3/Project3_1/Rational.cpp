#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

const int Rational::getNumerator()const                { return numerator; }

const int Rational::getDenominator()const              { return denominator; }

void Rational::setNumerator(int const myNumerator)     { numerator = myNumerator; }

void Rational::setDenominator(int const myDenominator) { denominator = myDenominator; }

Rational Rational::reduction(Rational num)
{
	/***********The function reduces a rational number to the lowest reduction**************/

	if (num.numerator < 0 && num.denominator < 0) // When the numerator and denominator are negative
	{
		num.numerator = abs(num.getNumerator());   // We will turn the fracture into a positive number
		num.denominator = abs(num.getDenominator());
	}

	if (!num.numerator || num.denominator == 1) // When the fraction is equal to 0 or an integer
		return num;

	if (abs(num.numerator) < abs(num.denominator))                 // When the denominator is larger than the numerator
	{
		for (int i = abs(num.numerator); i > 0; i--)
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

Rational::Rational(int _numerator = 1, int _denominator = 1) // constructor
{
	if (!_denominator) // When the denominator is equal to 0
	{
		cout << "ERROR\n";
		denominator = 1;
	}
	else
		denominator = _denominator;

	numerator = _numerator;

	*this = reduction(*this); // Reduce the fraction
}

Rational::Rational(const Rational& r)     // copy-constructor
{
	numerator = r.numerator;
	denominator = r.denominator;
}

void Rational::print()const
{
	if (!getNumerator() || getDenominator() == 1)  // When the fraction is equal to 0 or an integer
		cout << getNumerator();                   // Print only the integer
	else
		cout << getNumerator() << "/" << getDenominator();
}

Rational Rational::operator+(const Rational& r2)
{
	Rational temp;

	if (denominator == r2.denominator)                   // When the 2 denominators are equal
	{
		temp.setDenominator(getDenominator());              // The denominator remains the same
		temp.setNumerator(getNumerator() + r2.numerator);  // Connection of 2 numerator
	}
	else // When the denominators are not equal
	{
		temp.setDenominator(getDenominator() * r2.denominator);                                // double the denominators themselves
		temp.setNumerator(getNumerator() * r2.denominator + r2.numerator * getDenominator()); // multiply the numerators by denominators and connect
	}

	temp = Rational::reduction(temp); // Reduces the fracture
	return temp;
}

Rational Rational::operator-(const Rational& r2)
{
	Rational temp;
	
	if (denominator == r2.denominator)                   // When the 2 denominators are equal
	{
		temp.denominator = denominator;              // The denominator remains the same
		temp.numerator = numerator - r2.numerator;  // Connection of 2 numerator
	}
	else // When the denominators are not equal
	{
		temp.denominator = denominator * r2.denominator;                           // double the denominators themselves
		temp.numerator = numerator * r2.denominator - r2.numerator * denominator; // multiply the numerators by denominators and connect
	}
	
	temp = reduction(temp); // Reduces the fracture
	return temp;
}

Rational Rational::operator*(const Rational& r2)
{
	Rational temp;

	temp.numerator = r2.numerator * numerator;        // Multiply the numerator
	temp.denominator = r2.denominator * denominator; // Multiply the denominator

	temp = Rational::reduction(temp); // Reduces the fracture
	return temp;
}

Rational Rational::operator/(const Rational& r2)
{
	Rational temp;

	temp.numerator = numerator * r2.denominator;
	temp.denominator = denominator * r2.numerator;

	temp = Rational::reduction(temp); // Reduces the fracture
	return temp;
}

const Rational& Rational::operator++()
{
	numerator += denominator;             // Adds 1 integer to the fracture
	*this = Rational::reduction(*this);  // Reduces the fracture
	return *this;
}

const Rational Rational::operator++(int)
{
	Rational temp = *this;
	numerator += denominator;            // Adds 1 integer to the fracture
	*this = Rational::reduction(*this); // Reduces the fracture
	return temp;
}

const Rational& Rational::operator--()
{
	numerator -= denominator;             // less 1 integer to the fracture
	*this = Rational::reduction(*this);  // Reduces the fracture
	return *this;
}

const Rational Rational::operator--(int)
{
	Rational temp = *this;
	numerator -= denominator;            // less 1 integer to the fracture
	*this = Rational::reduction(*this); // Reduces the fracture
	return temp;
}

const bool Rational::operator>(const Rational& r2)const
{
	double temp1 = (double)numerator / denominator;       //Displays the fraction as a decimal number
	double temp2 = (double)r2.numerator / r2.denominator;

	if (temp1 > temp2) 
		return true;   // When the first fraction is larger than the second
	else
		return false;
}

const bool Rational::operator<(const Rational& r2)const
{
	if (operator>(r2) == false) // When the previous function is "false" then here it is "true"
		return true;
	else
		return false;
}

const bool Rational::operator>=(const Rational& r2)const
{
	double temp1 = (double)numerator / denominator;  //Displays the fraction as a decimal number
	double temp2 = (double)r2.numerator / r2.denominator;

	if (temp1 >= temp2)  // When the first fraction is larger than the second or equal
		return true;
	else
		return false;
}

const bool Rational::operator<=(const Rational& r2)const
{
	if (operator>=(r2) == false) // When the previous function is "false" then here it is "true"
		return true;
	else
		return false;
}

const bool Rational::operator==(const Rational& r2)const
{
	double temp1 = (double)numerator / denominator;  //Displays the fraction as a decimal number
	double temp2 = (double)r2.numerator / r2.denominator;

	if (temp1 == temp2) // When two fractions are equal
		return true;
	else
		return false;
}

const bool Rational::operator!=(const Rational& r2)const
{
	if (operator==(r2) == false)  // When the previous function is "false" then here it is "true"
		return true;
	else
		return false;
}