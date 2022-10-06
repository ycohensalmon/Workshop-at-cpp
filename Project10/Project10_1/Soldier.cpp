#include "Soldier.h"

Soldier::Soldier(Soldier& soldat) // בנאי העתקה
{
	id = soldat.id; 
	first_name = soldat.first_name;
	last_name = soldat.last_name;
	num_operations = soldat.num_operations;
}

Soldier::Soldier(int _id, string _first_name, string _last_name, int _num_operations)
{
	try
	{
 		if (_id < 0)                       // אם התעודת זהות קטנה מ 0
			throw "id must be positive !";
		else
			id = _id;
		if (_num_operations < 0)           // אם מספק המלחמות הוא שלילי
			throw "num of war must be positive !";
		else
			num_operations = _num_operations;

		first_name = _first_name;
		last_name = _last_name;
	}
	catch (const char* msg)
	{
		cout << "ERROR - " << msg;
	}
}

Soldier::~Soldier() {}

int Soldier::getSociometric_score() // הפונקציה הזו אמורה לעבוד רק בשביל מפקד
{
	cout << "ERROR: this function is just for officer soldier" << endl;
	return 0;
}

bool Soldier::getCombat() // הפונקציה הזו אמורה לעבוד רק בשביל מפקד
{
	cout << "ERROR" << endl;
	return 0;
}

int const Soldier::getNum_operation() { return num_operations; }

string const Soldier::getFirst_name() { return first_name; }

string const Soldier::getLast_name()  { return last_name; }

void Soldier::setNum_operation(int _num_operations) { num_operations = _num_operations; }