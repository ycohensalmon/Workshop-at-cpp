/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include "Commander.h"

Commander::Commander(int _id, string _first, string _last, int _num) : Private(_id, _first, _last, _num)
{
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	bool cheak; cin >> cheak;
	combat = (cheak) ? true : false;
}

bool Commander::medal()
{
	if (getNum_operation() < 7)
		return false;
	else
	{
		int compteur = 0;
		for (int i = 0; i < getNum_operation(); i++)
			compteur += grades[i];
		if (compteur / getNum_operation() > 90)
			return true;
		else
			return false;
	}
}

void Commander::print()
{
	cout << "commander\nID: " << id << endl
		<< "first name: " << first_name << endl
		<< "last name: " << last_name << endl
		<< "num operations: " << num_operations << endl
		<< "grades: ";
	for (int i = 0; i < num_operations; i++)
		cout << grades[i] << " ";
	cout << endl << "combat: ";
	if (combat == true)
		cout << "yes\n";
	else
		cout << "no\n";
}

string Commander::soldierType() { return "Commander"; }

bool Commander::getCombat()     { return combat; }
