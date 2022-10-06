/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
*/
#include "Officer.h"

int Officer::getSociometric_score() {return sociometric_score; }

Officer::Officer(int _id, string _first, string _last, int num) : Soldier(_id, _first, _last, num)
{
    cout << "enter number of sociometric score\n";
    int score; cin >> score;                       // קולט את הציון
    try
    {
        if (score < 0 || score > 100)              // אם הציון לא נכון
            throw "ERROR - sociometric score must be between 0 and 100";
        else
            sociometric_score = score;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}

bool Officer::medal()
{
    if (getNum_operation() > 2 && sociometric_score > 92)
        return true;
    else
        return false;
}

void Officer::print()
{
    cout << "officer\nID: " << id << endl
        << "first name: " << first_name << endl
        << "last name: " << last_name << endl
        << "num operations: " << num_operations << endl
        << "sociometric score: " << sociometric_score << endl;
}

string Officer::soldierType()
{
    return "Officer";
}