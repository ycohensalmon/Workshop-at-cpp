/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 5 Question 1
*/
#include "List.h"

List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}                 //  class Link implementation

List::Link::Link(const Link& source) : value(source.value), next(source.next) {}

List::List() : head(NULL) {}                                                    //  class List implementation

List::List(const List& l)                                   // copy constractor
{
	Link* src, * trg;
	if (l.head == NULL)                                     // if the list is empty
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);             // copy the head of the list
		src = l.head;                                       // copy the head
		trg = head;
		while (src->next != NULL)                           // while the list is not empty
		{
			trg->next = new Link((src->next)->value, NULL); // copy the value
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List()  // destructor
{              // empty all elements from the List

	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext) // while the list is not empty
	{
		theNext = p->next;
		p->next = NULL;                          // delete the element pointed to by p
		delete p;
	}
	head = NULL;                                 // mark that the List contains no elements
}

void List::insert(int key) // Inserts an organ in a sorted place
{
	if (isEmpty())         // If the list is empty
		add(key);          // Add to first place
	else
	{
		List::Link* p = head;                                 // Creates a pointer to the head

		if (p->value < key)                                   // If the value in all the list is are smaller than key
			head = new List::Link(key, p);                    // put the key in the first place
		else
		{
			while (p->next != NULL && p->next->value >= key)  // while rhe list is not empty or the value is smaller than the key
				p = p->next;                                  // Advance the pointer

			p->next = new List::Link(key, p->next);           // insert the key in the list
		}
	}
}

void List::remove(int key)
{
	if (isEmpty())               // if the list is empty
		throw "value not found"; // there are no value to delete
	else
	{
		List::Link* p = head;    // creat a pointer to the head

		if (p->value == key)     // If the value in all the list is are smaller than key
		{
			head = p->next;      // The pointer will point to the next pointer
			return;              // end the ponction
		}
		else
		{
			while (p->next != NULL)          // while the list is not empty
			{
				if (p->next->value == key)   // if the value in the list is equal to the key
				{
					p->next = p->next->next; // The pointer will point to the next pointer
					return;                  // end the ponction
				}
				p = p->next;                 // Promotes the pointer to the next point
			}
		}
		throw "value not found"; // if the value is not found - throw exeption
	}
}

List List::operator=(const List& lst)const // copy constractor
{
	return lst;  // the fonction return 'lst' by copy constracor (is not the same value beceuse there are no '&')
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}

void List::add(int val)
{
	if (isEmpty())                  // if the list is empty
		head = new Link(val, NULL); // add the value to the first place
	else
	{
		Link* p = head;
		while (p->next != NULL)     // As long as the list did not reach the end
			p = p->next;            // Promotes the pointer to the next point

		p->next = new Link(val, NULL); // add the value in the end of the list
	}
}

ostream& operator<<(ostream& os, List& lst)
{
	for (List::Link* p = lst.head; p != NULL; p = p->next)
	{
		os << p->value << " ";
	}
	return os;
}

istream& operator>>(istream& is, List& lst)
{
	int value;
	is >> value;               // enter the first value
	lst.add(value);            // in the first plase
	List::Link* p = lst.head;  // creat a pointer to the head
	is >> value;               // enter the second value

	while (value < p->value)   // while the list goes down in order
	{
		lst.add(value);        // add the value to the list
		p = p->next;           // Advance to the next value
		is >> value;           // enter a value
	}
	return is;
}