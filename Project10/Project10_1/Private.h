/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include "Soldier.h"
#pragma once

class Private : public Soldier
{
protected:
	int* grades = NULL; // מערך של ציונים
public:
	Private(Private&);                 // בנאי העתקה
	Private(int, string, string, int); // בנאי רגיל
	~Private();                        // הורס
	bool medal()override;              // האם זכאי למדליה
	void print()override;              // הדפסה של כל הפרטים
	string soldierType()override;      // סוג החייל
};