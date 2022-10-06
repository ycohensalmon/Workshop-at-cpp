/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include "Private.h"
#pragma once

class Commander : public Private
{
	bool combat;
public:
	Commander(int _id, string _first, string _last, int _num); // בנאי
	bool medal()override;                                      // זכאות למדליה
	void print()override;                                      // מדפיס את הפרטים
	string soldierType()override;                              // סוג החייל
	bool getCombat();
};