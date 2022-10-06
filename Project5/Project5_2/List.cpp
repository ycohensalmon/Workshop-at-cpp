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

void List::add_end(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

void List::insert(int key) // Inserts an organ in a sorted place
{
	if (isEmpty())                  // If the list is empty
		head = new Link(key, NULL); // add the value to the first place
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

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is NULL
	return head == NULL;
}

//void List::add(int val)
//{
//	if (isEmpty())                  // if the list is empty
//		head = new Link(val, NULL); // add the value to the first place
//	else
//	{
//		Link* p = head;
//		while (p->next != NULL)     // As long as the list did not reach the end
//			p = p->next;            // Promotes the pointer to the next point
//
//		p->next = new Link(val, NULL); // add the value in the end of the list
//	}
//}

List& List::operator=(const List& l) // copy constractor
{
	Link* src, * trg;
	if (l.head == NULL)                                     // if the list is empty
		return *this;
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

ostream& operator<<(ostream& os,const List& lst)
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
	lst.insert(value);            // in the first plase
	List::Link* p = lst.head;  // creat a pointer to the head
	is >> value;               // enter the second value

	while (value < p->value)   // while the list goes down in order
	{
		lst.insert(value);        // add the value to the list
		p = p->next;           // Advance to the next value
		is >> value;           // enter a value
	}
	return is;
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}