#pragma once
#include "list.h"

class RoundList : public List
{
private:
	Link* End;
public:
	RoundList();
	~RoundList();
	void addToEnd(int val);
	int search(int n);
	void removeFirst();
	void add(int value);
	void clear();
};