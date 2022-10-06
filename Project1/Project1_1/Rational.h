#pragma once
class Rational
{
	int numerator;
	int denominator;
	Rational reduction(Rational num);
public:
	void setNumerator(int numtemp);
	void setDenominator(int dentemp);
	void getNumerator();
	void getDenominator();
	Rational add(Rational rtemp);
	void print();
	bool equal(Rational r2);
};

