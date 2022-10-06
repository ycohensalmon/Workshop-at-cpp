/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include "Soldier.h"
#pragma once

class Officer : public Soldier
{
private:
	int sociometric_score;                                  // ציון סציומטרי
public:
	int getSociometric_score()override;
	Officer(int _id, string _first, string _last, int num); // בנאי רגיל
	bool medal() override;                                  // אם זכאי למדליה
	void print()override;                                   // מדפיס את הפרטים
	string soldierType()override;                           // סוג החייל
};