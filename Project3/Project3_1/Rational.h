#pragma once
class Rational
{
private:
	int numerator;
	int denominator;
	Rational reduction(Rational num); // Reduce the fraction
public:
	const int getNumerator()const;
	const int getDenominator()const;
	void setNumerator(int const myNumerator);
	void setDenominator(int const myDenominator);
	Rational(int, int);                              // constructor
	Rational(const Rational&);                       // copy-constructor
	void print()const;                               // print
	Rational operator+(const Rational& r2);          // add
	Rational operator-(const Rational& r2);          // Subtraction
	Rational operator*(const Rational& r2);          // multiplication
	Rational operator/(const Rational& r2);          // Division
	const Rational& operator++();                    // add 1 after
	const Rational operator++(int);                  // add 1 before
	const Rational& operator--();                    // Subtraction 1 after
	const Rational operator--(int);                  // Subtraction 1 before
	const bool operator>(const Rational& r2)const;   // if 1 larger from 2
	const bool operator<(const Rational& r2)const;   // if 1 smaller from 2
	const bool operator>=(const Rational& r2)const;  // if 1 larger or equal from 2
	const bool operator<=(const Rational& r2)const;  // if 1 smaller or equal from 2
	const bool operator==(const Rational& r2)const;  // if 1 equal from 2
	const bool operator!=(const Rational& r2)const;  // if 1 not equal from 2
};
