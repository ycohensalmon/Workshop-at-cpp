/*
* יוסף כהן סלמון ת.ז.317805588
* C++סדנא ב
* תרגיל 10
* הפרויקט מחשב לי את מספר המלחמות שהחיילים או המפקדים עשו
ונותן לי אפשרות להוסיף חייילים או למחוק חיילים שלא שהם לא קרביים
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Officer.h"
#include "Commander.h"
#include "Private.h"
#include "Soldier.h"
using namespace std;

//Soldier -> Private -> Commander
//Soldier -> Officer

int index = 0;

enum option {
	stop,	            //	סיום התוכנית
	addNewSoldier,	    //	הוספת חייל חדש
	medalList,	        //	הדפסת פרטי כל החיילים הזכאים לצל"ש
	mostSociometric,	//	הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	countMedalPrivate,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	noCombatCommander,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	overSoldier,	    //	הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	removeOfficer,	    //	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};


void add(vector<Soldier*>& arr);                        //השלם\י פרמטר- ווקטור או רשימה  
void medal(vector<Soldier*> arr);                       //השלם\י פרמטר- ווקטור או רשימה  
Soldier* mostSociometricScore(vector<Soldier*>& arr);   //השלם\י פרמטר- ווקטור או רשימה  

int main()
{
	vector<Soldier*> arr;   // הצהרה על ווקטור או רשימה של חיילים
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewSoldier:add(arr);                // הוספת חייל חדש						
			break;
		case medalList:medal(arr);                  // הדפסת פרטי הזכאים לצל"ש
			break;
		case mostSociometric:                       // הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
		{
			Soldier* s = mostSociometricScore(arr); // האנידקס במערך של הקצין עם הציון הגבוה ביותר
			cout << "Officer soldier with most sociometric score: ";
			cout << s->getFirst_name() << ' ' << s->getLast_name() << endl;
		}
			break;
		case countMedalPrivate:
		{
			//הדפסת מספר הזכאים לצל"ש בטירונים
			cout << "# private soldier for medal: "
				<< count_if(arr.begin(), arr.end(), [](Soldier* s) {return s->medal() && s->soldierType() == "Private"; })
				<< endl;
		}
			break;
		case noCombatCommander:
		{
			cout << "list of no combat commander soldier :";
			//הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			for_each(arr.begin(), arr.end(), [](Soldier* s) {if (s->soldierType() == "Commander" && !s->getCombat())cout << " " <<  s->getFirst_name() << " " << s->getLast_name(); });
			cout << endl;
		}
			break;
		case overSoldier:
		{
			if (any_of(arr.begin(), arr.end(), [](Soldier* s) {return s->getNum_operation() > 15; })) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים
				cout << "there is a soldier that takes more than 15 operations\n";
			else cout << "no soldier takes more than 15 operations\n";
		}
			break;
		case removeOfficer:
		{
			//מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			auto end = remove_if(arr.begin(), arr.end(), [](Soldier* s) {return s->soldierType() == "Officer" && !s->getNum_operation(); });
			//הדפסת כל הרשימה לאחר מחיקת האיברים
			for_each(arr.begin(), end, [](Soldier* s) {s->print(); });
		}
				break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}

void add(vector<Soldier*>& arr)
{
	cout << "enter 1 to add a private soldier\n"
		 << "enter 2 to add a commander soldier\n"
		 << "enter 3 to add a officer soldier\n";

	string First_name, Last_name;
	int num, Id, Num_operation; cin >> num;

	cout << "enter id, first name, last name and number Of operations\n";
	cin >> Id >> First_name >> Last_name >> Num_operation;

	switch (num)
	{
	case 1 :  arr.push_back(new Private(Id, First_name, Last_name, Num_operation));  // יצירת מערך עבור טירון 
		break;
	case 2:   arr.push_back(new Commander(Id, First_name, Last_name, Num_operation));// יצירת מערך עבור מפקד
		break;
	case 3:   arr.push_back(new Officer(Id, First_name, Last_name, Num_operation));  // יצירת מערך עבור קצין
		break;
	default: cout << "ERROR";
		break;
	}
}

void medal(vector<Soldier*> arr)
{
	int j = 0;
	for (auto i = arr.begin(); i < arr.end(); i++) // עובר על כל המערך
	{

 		if (arr[j]->medal() == true)               // אם הוא זכאי למדליה
 			arr[j]->print();                       // תדפיס את החייל/טירון/מפקד
		j++;
	}
}

Soldier* mostSociometricScore(vector<Soldier*>& arr) 
{
	int j = 0, max = 0;
	Soldier* p = NULL;

	for (auto i = arr.begin(); i < arr.end(); i++)    // עובר על כל המערך
	{
		if (arr[j]->soldierType() == "Officer")       // אם הוא קצין
			if (arr[j]->getSociometric_score() > max) // עם הציון הסציומטרי הכי גבוה
			{
				max = arr[j]->getSociometric_score(); // נעדכן את הציון הגבוה ביותר
				p = arr[j];                           // נעדכן את המצביע
			}
		j++;
	}
	return p;
}

/*
**********דוגמת הרצה**********

enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 10
enter 10 grades
100 100 100 100 100 98 98 98 98 98
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
222 bbb bbb 4
enter 4 grades
100 78 54 99
enter 1 if the soldier is combat and 0 if not
0
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
333 ccc ccc 0
enter number of sociometric score
99
enter 0-7
2
private
ID: 111
first name: aaa
last name: aaa
num operations: 10
grades: 100 100 100 100 100 98 98 98 98 98
enter 0-7
3
Officer soldier with most sociometric score: ccc ccc
enter 0-7
4
# private soldier for medal: 1
enter 0-7
5
list of no combat commander soldier : bbb bbb
enter 0-7
6
no soldier takes more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 10
grades: 100 100 100 100 100 98 98 98 98 98
commander
ID: 222
first name: bbb
last name: bbb
num operations: 4
grades: 100 78 54 99
combat: yes
enter 0-7
0

Sortie de C:\Users\ycohe\Documents\Visual Studio 2019\Semestre 2\Project10\Project10_1\Debug\Project10_1.exe (processus 1032). Code : 0.
Pour fermer automatiquement la console quand le débogage s'arrête, activez Outils->Options->Débogage->Fermer automatiquement la console à l'arrêt du débogage.
Appuyez sur une touche pour fermer cette fenêtre. . .
*/