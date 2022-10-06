/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 6 Question 1
The project calculates the wages of part-time workers
and full-time workers with bonus additions
*/
#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;

int main()
{
	FullTime arrF[3];
	for (int i = 0; i < 3; i++) // Collects 3 full-time objects
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++) // Collects 3 part-time objects
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl; // Prints the bonus for the full time job
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl; // Prints the bonus for a part-time job
	}
	return 0;
}
/*
Enter employee details:
 aa 11 11 11
Enter employee details:
bb 22 22 22
Enter employee details:
cc 33 33 33
Enter employee details:
dd 44 44 44 44
Enter employee details:
ee 55 55 55 55
Enter employee details:
ff 66 66 66 66

Employee: aa
Employee ID: 11
Years Seniority: 11
Salary per Month: 0
After Bonus: 0

Employee: bb
Employee ID: 22
Years Seniority: 22
Salary per Month: 1
After Bonus: 1

Employee: cc
Employee ID: 33
Years Seniority: 33
Salary per Month: 2
After Bonus: 2

Employee: dd
Employee ID: 44
Years Seniority: 44
Hours: 44
Salary per Month: 1936
After Bonus: 2420

Employee: ee
Employee ID: 55
Years Seniority: 55
Hours: 55
Salary per Month: 3025
After Bonus: 3781

Employee: ff
Employee ID: 66
Years Seniority: 66
Hours: 66
Salary per Month: 4356
After Bonus: 5445
*/