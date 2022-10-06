/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 8 Question 2
The project that literally stacked by 2 queues
*/
#include <iostream>
#include <string>
#include <queue>
//#include " QueueStack.h"
using namespace std;
int main()
{

	queue<int>* Q = new queue<int>();
	try {
		for (int i = 0; i < 10; i++)
			Q->push(i);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first on Q is: " << Q->front() << endl;
	cout << "take out 2 elemets:" << endl;
	int first, second;
	first = Q->front();
	Q->pop();
	second = Q->front();
	Q->pop();
	cout << second << ' ' << first << endl;
	cout << "first on Q is: " << Q->front() << endl;
	Q->push(8);
	Q->push(9);
	while (!Q->empty())
	{
		int x = Q->front();
		Q->pop();
		cout << x << " ";
	}
	return 0;
}
/*
first on Q is: 0
take out 2 elemets:
1 0
first on Q is: 2
2 3 4 5 6 7 8 9 8 9
Sortie de C:\Users\ycohe\Documents\Visual Studio 2019\Semestre 2\Project8\Project8_2\Debug\Project8_2.exe (processus 2968). Code : 0.
Pour fermer automatiquement la console quand le débogage s'arrête, activez Outils->Options->Débogage->Fermer automatiquement la console à l'arrêt du débogage.
Appuyez sur une touche pour fermer cette fenêtre. . .

*/