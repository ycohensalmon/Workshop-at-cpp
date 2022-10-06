/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 3 Question 1
The function connects 2 fractions and does on it all the actions like addition, subtraction, division, multiplication, equality
*/
#include"Rational.h"
#include <iostream>
using namespace std;
enum { add, sub, mult, divi, addPre, addPost, subPre, subPost, big, small, bigEq, smallEq, eequal, notEqual };
int main()
{
	int numerator, denominator;
	char tav;
	int op = 1;

	while (op != 0)
	{
		cout << "enter two rational numbers:" << endl;
		cin >> numerator >> tav >> denominator;
		Rational r1(numerator, denominator);

		cin >> numerator >> tav >> denominator;
		Rational r2(numerator, denominator);

		switch (0)
		{
		case add:r1.print();  cout << " + "; r2.print(); cout << " = "; (r1 + r2).print(); cout << endl;

		case sub:r1.print();  cout << " - "; r2.print(); cout << " = "; (r1 - r2).print(); cout << endl;

		case mult:r1.print(); cout << " * "; r2.print(); cout << " = "; (r1 * r2).print(); cout << endl;

		case divi:r1.print(); cout << " / "; r2.print(); cout << " = "; (r1 / r2).print(); cout << endl;

		case addPre:  cout << "++"; cout << "("; r1.print();  cout << ") = "; (++r1).print(); cout << endl;

		case addPost: cout << "("; r1.print(); cout << ")++"; cout << " = "; (r1++).print(); cout << endl;

		case subPre:  cout << "--"; cout << "("; r1.print();  cout << ") = "; (--r1).print(); cout << endl;

		case subPost: cout << "("; r1.print(); cout << ")--"; cout << " = "; (r1--).print(); cout << endl;

		case big:r1.print();        cout << " > "; r2.print(); cout << " ? ";  (r1 > r2) ? cout << "yes" : cout << "no"; cout << endl;

		case small:r1.print();      cout << " < "; r2.print(); cout << " ? ";  (r1 < r2) ? cout << "yes" : cout << "no"; cout << endl;

		case bigEq:r1.print();    cout << " >= "; r2.print(); cout << " ? ";  (r1 >= r2) ? cout << "yes" : cout << "no"; cout << endl;

		case smallEq:r1.print();  cout << " <= "; r2.print(); cout << " ? ";  (r1 <= r2) ? cout << "yes" : cout << "no"; cout << endl;

		case eequal:r1.print();   cout << " == "; r2.print(); cout << " ? ";  (r1 == r2) ? cout << "yes" : cout << "no"; cout << endl;

		case notEqual:r1.print(); cout << " != "; r2.print(); cout << " ? ";  (r1 != r2) ? cout << "yes" : cout << "no"; cout << endl;

		}
		cout << "enter 1 to cont. 0 to exit." << endl;
		cin >> op;
	}

	return 0;
}
/*

  ////Running example////

enter two rational numbers:
-1/-2 -1/-2
1/2 + 1/2 = 1
1/2 - 1/2 = 0
1/2 * 1/2 = 1/4
1/2 / 1/2 = 1
++(1/2) = 3/2
(3/2)++ = 3/2
--(5/2) = 3/2
(3/2)-- = 3/2
1/2 > 1/2 ? no
1/2 < 1/2 ? yes
1/2 >= 1/2 ? yes
1/2 <= 1/2 ? no
1/2 == 1/2 ? yes
1/2 != 1/2 ? no
enter 1 to cont. 0 to exit.
1
enter two rational numbers:
7/8 4/7
7/8 + 4/7 = 81/56
7/8 - 4/7 = 17/56
7/8 * 4/7 = 1/2
7/8 / 4/7 = 49/32
++(7/8) = 15/8
(15/8)++ = 15/8
--(23/8) = 15/8
(15/8)-- = 15/8
7/8 > 4/7 ? yes
7/8 < 4/7 ? no
7/8 >= 4/7 ? yes
7/8 <= 4/7 ? no
7/8 == 4/7 ? no
7/8 != 4/7 ? yes
enter 1 to cont. 0 to exit.
0
*/