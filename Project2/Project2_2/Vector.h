#pragma once
class Vector
{
private:
	int* data;
	int capacity;
	int size;
public:
	int getSize();
	int getCapacity();
	Vector();                 // default-constructor
	Vector(int);              // constructor
	Vector(const Vector&);    // copy-constructor
	~Vector();                // destructor
	void print();             // print the vector
	void assign(Vector);      // initializing a vector into one another
	bool isEqual(Vector);     // check if the 2 vectors are equal
	int strcatcat(Vector);    // multiply the vectors 
	Vector strnewcat(Vector); // add a vector to each other
	void clear();             // delete the vector
	void delLast();           // delete the last vector
	int& at(int index);       //change the vector in a particular index
	void insert(int val);     // add a vector within the class
};