/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 3 Question 2
The function lets me enter a date and advance days or check if one date is greater than the other date
*/
#include "Calendar.h"
#include <iostream>
using namespace std;

enum date { initialization = 1, addPre, addPost, add, big, small, if_equal };

int main()
{
	int Day, Month, Year, choice;
	char tav;

	cout << "Enter a date" << endl;
	cin >> Day >> tav >> Month >> tav >> Year;
	Calendar date(Day, Month, Year);
	date.print();

	cout << "Enter an action code:\n";
	cin >> choice;
	while (choice != -1)               // When the input is -1 you will stop the program
	{
		switch (choice)              // Selects the cases
		{
		case initialization: cout << "Enter a date\n"; cin >> Day >> tav >> Month >> tav >> Year; date.setDate(Day, Month, Year).print();
			break;
		case addPre:    (++date).print();                                                // When pressing 2, add one day prefix
			break;
		case addPost:	(date++).print();	                                             // When pressing 3, add one day postfix
			break;
		case add:	cout << "Enter # days\n"; cin >> Day; date.operator+=(Day).print();  //  When you press 4, add a number of days
			break;
		case big:                                                                        // When you press 5,calcul if the original date is greater than the date entered 
		{
			cout << "Enter a date\n";
			cin >> Day >> tav >> Month >> tav >> Year;
			Calendar temp(Day, Month, Year);

			if(date > temp)
				cout << ">:" << "true" << endl;  // when he is greater
			else
				cout << ">:" << "false" << endl; // when he is smaller
		}
			break;
		case small:                                                                     // When you press 6,calcul if the original date is smaller than the date entered
		{
			cout << "Enter a date\n";
			cin >> Day >> tav >> Month >> tav >> Year;
			Calendar temp(Day, Month, Year);

			if (date < temp)
				cout << "<:" << "true" << endl;  // when he is smaller
			else
				cout << "<:" << "false" << endl; // when he is greater
		}
			break;
		case if_equal:                                                                  // When you press 7,Checks if the dates are equal
		{
			cout << "Enter a date\n";
			cin >> Day >> tav >> Month >> tav >> Year;
			Calendar temp(Day, Month, Year);

			if (date == temp)
				cout << "==:" << "true" << endl;  // when they are equal
			else
				cout << "==:" << "false" << endl; // when they are not equal
		}
			break;
		default: cout << "ERROR\n";
		}
		cout << "Enter an action code:\n";
		cin >> choice;
	}
	return 0;
}

/*

//// runing exemple ////

Enter a date
-8/12/2020
Error day
1/12/2020
Enter an action code:
2
2/12/2020
Enter an action code:
3
2/12/2020
Enter an action code:
4
Enter # days
600
3/8/2022
Enter an action code:
1
Enter a date
50/20/3333
Error day
Error month
Error year
3/8/2022
Enter an action code:
5
Enter a date
4/8/2020
>:false
Enter an action code:
-1
*/