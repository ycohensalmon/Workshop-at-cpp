/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include <iostream>
#include <string>
#pragma once
using namespace std;

class Soldier
{
protected:
	int id;
	string first_name;
	string last_name;
	int num_operations;
public:
	Soldier(Soldier&);                    // בנאי העתקה
	Soldier(int, string, string, int);    // בנאי רגיל
	virtual ~Soldier();                   // הורס
	virtual bool medal() = 0;             // בודק האם זכאי למדליה
	virtual void print() = 0;             // מדפיס את הפרטים
	virtual string soldierType() = 0;     // סוג החייל
	virtual int getSociometric_score();   // מחזיר את הציון הסוציומטרי
	virtual bool getCombat();             // האם הוא לוחם
	int const getNum_operation();         // מספר המלחמות שעשה
	string const getFirst_name();         // השם הפרטי
	string const getLast_name();          // השם משפחה
	void setNum_operation(int _num_operations);
};