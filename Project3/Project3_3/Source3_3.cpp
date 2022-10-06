/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 3 Question 3
The function Compares two words in a lexicographic form and tells me what is bigger than what
and also chains the words starting from a certain index
*/
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	char word[100];  int index;  // creat an array

	cin >> word;
	MyString word1(word);

	cin >> word;
	MyString word2(word);

	cin >> index;

	if (word1 > word2)        // when the a larger than b 
		cout << "a>b\n";
	if (word1 < word2)        // when the b larger than a 
		cout << "a<b\n";
	if(word1 == word2)
		cout << "a=b\n";      // when the a equal to b
	
	if (index >= 0 && index <= word2.getLen())                 // if the index is correct
	{
		MyString word3(word1.insert(index, word2.getArray())); // creat a new string with the two words
		word3.print();

		char tav;
		cin >> tav >> index;

		int max = strlen(word3.getArray());
		if (index >= 0 && index < max)    // if the new index is correct
		{
			word3[index] = tav;                                // change the array in the index
			word3.print();
		}
		else
			cout << "ERROR\n";         // if the new index is not correct
	}
	else
	{
		cout << "ERROR\n";             // if the index is not correct

		if (word1 != word2)            // when a not equal to b and the index isn't correct
		{
			char tav;
			cin >> tav >> index;
			cout << "ERROR\n";
		}
	}

	return 0;
}

/*

////Running example////

aaaaaaaaaa
AAAAAAAAAA
7
a=b
AAAAAAAaaaaaaaaaaAAA
e
2
AAeAAAAaaaaaaaaaaAAA


eeeeee
QQQQ
1
a>b
QeeeeeeQQQ
p
10
ERROR
*/