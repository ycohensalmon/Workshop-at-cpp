/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 5 Question 1
The project gets 2 sorted lists and merges the two lists so that the resulting list is sorted
then it returns me another list that includes each number once
and then returns another list that reverses the order of the previous list
*/
#include <iostream>
#include "List.h"
using namespace std;

List merge(List& l1, List& l2)
{
	List result;
	int val1, val2;
	while (!l1.isEmpty() && !l2.isEmpty())
	{
		val1 = l1.firstElement();
		val2 = l2.firstElement();
		if (val1 < val2)
		{
			result.insert(val1);
			l1.removeFirst();
		}
		else
		{
			result.insert(val2);
			l2.removeFirst();
		}
	}
	while (!l1.isEmpty())
	{
		result.insert(l1.firstElement());
		l1.removeFirst();
	}
	while (!l2.isEmpty())
	{
		result.insert(l2.firstElement());
		l2.removeFirst();
	}
	return result;
}

List makeSet(List& l)
{
	int val1, val2;
	List result;
	if (!l.isEmpty())
	{
		val1 = l.firstElement();
		l.removeFirst();
		result.insert(val1);
	}

	while (!l.isEmpty())
	{
		val2 = l.firstElement();
		l.removeFirst();

		if (val2 != val1)
		{
			result.insert(val2);
		}
		val1 = val2;
	}
	l = result;
	return l;
}

List reverse(List& lst)
{
	int val;
	List temp;
	while (!lst.isEmpty())
	{
		val = lst.firstElement();
		lst.removeFirst();
		temp.add_end(val);
	}
	lst = temp;
	return lst;
}

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	try
	{
		mergedList = merge(lst1, lst2);
		cout << "the new merged list: " << mergedList << endl;

		mergedList = makeSet(mergedList);
		cout << "the new merged set: " << mergedList << endl;

		mergedList = reverse(mergedList);
		cout << "the new merged reverse: " << mergedList << endl;
	}
	catch (const char* msg) { cout << msg << endl; }

	return 0;
}
/*
 ///// exemple runing /////////

enter sorted values for the first list:
9
8
7
6
5
4
4
enter sorted values for the second list:
9
8
7
6
5
4
4
the new merged list: 9 9 8 8 7 7 6 6 5 5 4 4
the new merged set: 9 8 7 6 5 4
the new merged reverse: 4 5 6 7 8 9
*/