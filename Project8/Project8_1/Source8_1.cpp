/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 8 Question 1
The project computes arithmetic operations between numbers by converting from 'infix' to 'postfix' and then gives me the solution
(The teacher Meir Littman said that the STL library can be used)
*/
#include <iostream>
#include <string>
#include <stack>
using std::stack;
using namespace std;

string infixToPostfix(string&);

int calcPostfix(string&);

int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}

string infixToPostfix(string& infix)
{
	string* str = new string;
	stack <string> stk;
	string ch;

	int index = 0, i = 0;

	while (i != infix.size())
	{
		ch = infix[i++];

		if (ch == "(")                              // When there is a left bracket
			stk.push(ch);                           // Insert the bracket into the stack

		if (ch == ")")                              // If there is a right bracket
		{
			while (stk.top() != "(")                // As long as there is no left bracket
			{
				str->insert(index++, stk.top());    // Insert the values from the stack into the string
				str->insert(index++, " ");          // Insert a space between numbers
				stk.pop();                          // We will delete the number from the stack because we inserted it into the string
			}
			stk.pop();                              // Delete the left bracket
		}

		if (ch == "*" || ch == "/" )
			stk.push(ch);                           // Put the operator with the highest priority in the stack
		 
		if (ch == "+" || ch == "-")                 // Operator with low priority
		{
			while (stk.top() != "(")                // While there is a left bracket 
			{
				if (stk.top() == "*" || stk.top() == "/") // If there are operators with high priority
				{
					str->insert(index++, stk.top());      // Put them in the string
					str->insert(index++, " ");
					stk.pop();
				}
			}
			stk.push(ch);                                 // We will insert the operator with the low priority at the end
		}

		if ("0" <= ch && ch <= "9")
		{
			str->insert(index++, ch);                     // Enter the number in the string

			while ('0' <= infix[i] && infix[i] <= '9')    // If the number is double digits
			{
				ch = infix[i++];
				str->insert(index++, ch);
			}
			str->insert(index++, " ");
		}
	}

	while (!stk.empty())                                  // If there are out-of-bracket operators
	{
		str->insert(index++, stk.top());
		str->insert(index++, " ");
		stk.pop();
	}
	return *str; // Returns the new string
}

int calcPostfix(string& postfix)
{
	stack <int> stk;
	string ch;
	int first, second, temp ,mltpl = 1,i = 0;
	while (i <= postfix.size())
	{
		ch = postfix[i++];

		if ("0" <= ch && ch <= "9") 
		{
			stk.push(stoi(ch));                            // Put the number in the stack

			while ('0' <= postfix[i] && postfix[i] <= '9') // If the number is double digits
			{
				mltpl *= 10;                               // Multiplies the position of the number, for example 20 = 2 * 10 + 0
				temp = stk.top();        
				stk.pop();                                 // Brings out the existing number in the stack
				ch = postfix[i];
				stk.push(stoi(ch) + mltpl * temp);         // And connects to it the complet number
				i++;
			}
			mltpl = 1; // Resets 'mltml' to the next round
		}

		if (ch == "*")
		{
			first = stk.top();        // Takes the first value
			stk.pop();
			second = stk.top();       // Takes the second value
			stk.pop();
			stk.push(first * second); // Multiplier between the two
		}

		if (ch == "/")
		{
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			stk.push(second / first);
		}

		if (ch == "-")
		{
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			stk.push(second - first);
		}

		if (ch == "+")
		{
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			stk.push(first + second);
		}
	}
	return stk.top();
}

/*

enter an infix expression as a string
(7*10)*((7-5)+2)
7 10 * 7 5 - 2 + *
280

Sortie de C:\Users\ycohe\Documents\Visual Studio 2019\Semestre 2\Project8\Project8_1\Debug\Project8_1.exe (processus 31076). Code : 0.
Pour fermer automatiquement la console quand le débogage s'arrête, activez Outils->Options->Débogage->Fermer automatiquement la console à l'arrêt du débogage.
Appuyez sur une touche pour fermer cette fenêtre. . .
*/