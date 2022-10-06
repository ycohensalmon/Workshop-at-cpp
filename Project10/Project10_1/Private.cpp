/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include "Private.h"

Private::Private(int id, string first, string last, int num) : Soldier(id, first, last, num)
{
	grades = new int[getNum_operation()]; // יוצר מערך של ציונים
	int _grade;
	try
	{
		
		if (getNum_operation()) cout << "enter " << getNum_operation() << " grades\n";

		for (int i = 0; i < getNum_operation(); i++)
		{
			cin >> _grade;                            // קולט את הציון

			if (_grade < 0 || _grade > 100)           // אם הציון לא בין 0 ל 100
				throw "grade not must be negative !";
			else
				grades[i] = _grade;
		}
	}
	catch (const char* msg)
	{
		cout << "ERROR - " << msg;
	}

}

Private::~Private() { delete[] grades; } // מוחק את המערך

bool Private::medal()
{
	if (getNum_operation() < 10)         // אם הוא לא זכאי למדליה
		return false;
	else
	{
		int compteur = 0;
		for (int i = 0; i < getNum_operation(); i++) // עובר על כל המערך
			compteur += grades[i];                   // סוכם את כל הציונים
		if (compteur / getNum_operation() > 95)      // אם הממוצע קטן מ95
			return true;
		else
			return false;
	}
}

void Private::print() // מדפיס את כל הפרטים
{
	cout << "private\nID: " << id << endl
		<< "first name: " << first_name << endl
		<< "last name: " << last_name << endl
		<< "num operations: " << num_operations << endl
		<< "grades: ";
	for (int i = 0; i < num_operations; i++)
		cout << grades[i] << " ";
	cout << endl;
}

string Private::soldierType() { return "Private"; }

Private::Private(Private& soldat) : Soldier(soldat) // בנאי העתקה
{
	if (grades != NULL)
	{
		for (int i = 0; i < soldat.getNum_operation(); i++) // מעתיק את המערך של הציונים
			soldat.grades[i] = grades[i];
	}
	
}
