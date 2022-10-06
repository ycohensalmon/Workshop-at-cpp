/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 1 Question 1
The function connects 2 fractions and gives me the limited result,
in addition the function tells me whether the 2 fractions are equal
*/

#include"Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int numerator, denominator;
	char tav;

	cout << "enter two rational numbers:" << endl;

	cin >> numerator >> tav >> denominator;
	Rational r1;
	r1.setNumerator(numerator);      // Sends to function to check if the input  for the numerator is good
	r1.setDenominator(denominator); // Sends to function to check if the input  for the denominator is good

	cin >> numerator >> tav >> denominator;
	Rational r2;
	r2.setNumerator(numerator);       // Sends to function to check if the input  for the numerator is good
	r2.setDenominator(denominator);  // Sends to function to check if the input  for the denominator is good

	r1.print();   // Prints the first fraction
	cout << "+ ";
	r2.print();  // Prints the seconde fraction
	cout << "= ";

	Rational ans = r1.add(r2);
	ans.print();  // Prints the result
	cout << endl;

	if (r1.equal(r2))
		cout << "The two numbers are equal" << endl; // When the 2 fractions are equal
	else
	{
		cout << "The two numbers are different" << endl; // When the 2 fractions are not equal
		r1.print();
		r2.print();
		cout << endl;
	}
	return 0;
}


/*
////Running example////

enter two rational numbers:
1/10 1/2
1/10 + 1/2 = 3/5
The two numbers are different
1/10 1/2

enter two rational numbers:
5/-10 -1/2
5/-10 + -1/2 = -1/1
The two numbers are equal
*/