/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 1 Question 2
The function gets details about employees - ID card, name, hourly wage, working hours and
the amount of money he managed to put in and finally gives me the one who managed to put in the minimum
and the one who got the most pay
*/

#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
	int id, hours,i=0;
	float amount, salaire;
	char name[21];
	Employee temp, min, max;
	cout << "enter details, to end enter 0:\n";

	do
	{
		cin >> id;   // Enter the id

		if (!id)   // if id equal to 0 exit from the loop
			break;
		cin >> name >> salaire >> hours >> amount;
		while (salaire < 0 || hours < 0 || amount < 0 || id < 0) // Input integrity check
		{
			cout << "ERROR\n";
			cin >> id;
			if (!id)                                          // if id equal to 0 exit from the loop
				break;
			cin >> name >> salaire >> hours >> amount;
		}

		if (!id)                                          // if id equal to 0 exit from the loop
			break;
		
		temp.setId(id);       // Put the variables in the class itself
		temp.setName(name);
		temp.setSalaire(salaire);
		temp.setHours(hours);
		temp.setAmount(amount);

		if (!i) // Put the temporal variable inside min and max only for the first time
		{      // so that we can compare whether it is large there will be something there and not junk value
			min = temp;
			max = temp;
			i++; // So only the first time it works
		}
		

		if (temp.getAmount() <= min.getAmount())                   { min = temp; } // Calculates the largest quantity

		if (temp.salaire_with_bonus() >= max.salaire_with_bonus()) { max = temp; } // Calculates the largest income

	} while (id);
	
	cout << "minimum sum: ";
	cout << min.getAmount() << " " <<  min.getName() << " " << min.getId() << endl;
	cout << "highest  salary: ";
	cout << max.salaire_with_bonus() << " " << max.getName() << " " << max.getId() << endl;

	return 0;
}

/*
////Running example////

enter details, to end enter 0:
11111111 jojo 35 100 8000
22222222 yossef 40 50 2000
33333333 yosi 70 2 45.78
44444444 istik 50 50 100
0
minimum sum: 45.78 yosi 33333333
highest  salary: 5650 jojo 11111111


enter details, to end enter 0:
11111111 jojo -9 4 20
ERROR
11111111 jojo 50 50 500
0
minimum sum: 500 jojo 11111111
highest  salary: 2550 jojo 11111111
*/