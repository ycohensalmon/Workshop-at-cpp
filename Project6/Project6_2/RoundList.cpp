#include "list.h"
#include "roundlist.h"

RoundList::RoundList() : List(), End(NULL) {}

RoundList::~RoundList()
{
	clear();
}

void RoundList::addToEnd(int val)
{
	// Empty 
	if (isEmpty())
	{
		head = new Link(val, End);
		End = head;
	}
	else // Otherwise
	{
		End->next = new Link(val, head);
		End = End->next;
	}
}

int RoundList::search(int n)
{
	// Empty
	if (isEmpty())
		return -1;
	// Otherwise
	Link* p = head;
	for (int i = 0; i < n; i++, p = p->next);
	return p->value;
}

void RoundList::removeFirst()
{
	// List Is Not Empty
	if (!isEmpty())
		End->next = NULL;
	// Otherwise
	List::removeFirst();
	// Make The Last Point On The Head
	if (isEmpty())
		End = NULL;
	else End->next = head;
}

void RoundList::add(int value)
{
	head = new Link(value, head);
	// This Is The Only Value
	if (head->next == NULL)
	{
		head->next = head;
		End = head;
	}
	else // Otherwise
		End->next = head;
}

void RoundList::clear()
{
	// List Is Not Empty
	if (!isEmpty())
	{
		End->next = NULL;
		End = NULL;
		List::clear();
	}
}