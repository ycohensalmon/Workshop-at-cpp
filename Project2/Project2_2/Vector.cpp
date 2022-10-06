#include "Vector.h"
#include <iostream>

int Vector::getSize()     { return size; }

int Vector::getCapacity() { return capacity; }

Vector::~Vector()         { if (size) delete[] data; } // destructor

Vector::Vector()                                      // default-constructor
{
	size = 0;
	data = new int[size];
	capacity = 2;
} 

Vector::Vector(int _capacity)                      // constructor
{
	while (_capacity < 0)                         // when the input isn't correct
	{
		std::cout << "ERROR\n";
		std::cin >> _capacity;
	}
	size = 0;
	capacity = _capacity;
	data = new int[size];                      // creat a new vector
}

Vector::Vector(const Vector& vec)            // copy-constructor
{
	size = vec.size;                        // copy the size
	capacity = vec.capacity;               // copy the capacity

	data = new int[size];                 // creat a new vector
	for (int i = 0; i < size; i++)
		data[i] = vec.data[i];          // copy the vector
}

void Vector::assign(Vector vec)       // initializing a vector into one another
{
	size = vec.size;                 // copy the size
	capacity = vec.capacity;        // copy the capacity

	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = vec.data[i];   // copy the vector
}

bool Vector::isEqual(Vector vec)         // check if the 2 vectors are equal
{
	if (size != vec.size) return false;// if the sizes of vectors arn't equal

	for (int i = 0; i < size; i++)
	{
		if (data[i] != vec.data[i]) // When it's not equal
			return false;
	}
	return true;
}

int Vector::strcatcat(Vector vec) // multiply the vectors
{
	if (size != vec.size)        // when the sizes arn't equal
	{
		std::cout << "ERROR";
		return -1;
	}

	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += data[i] * vec.data[i]; // the sum of the multiplication

	return sum;
}

Vector Vector::strnewcat(Vector vec)          // add a vector to each othe
{
	Vector temp;                             // creat a temperary variable
	temp.capacity = capacity + vec.capacity;

	for (int i = 0; i < size; i++)         // add from the first vector
		temp.insert(data[i]);

	for (int i = 0; i < vec.size; i++)   // add from the second vector
		temp.insert(vec.data[i]);


	return temp;                      // return the new vector
}

void Vector::clear()                // delete the vector
{
	for (int i = 0; i < size; i++)
		data[i] = NULL;

	size = 0;                    // update the size
}

void Vector::delLast()         // delete the last vector
{
	if (!size)                // when the vector is empty
	{
		std::cout << "ERROR\n";
		return;
	}

	int* help = new int[--size];  // creat a temperory array
	for (int i = 0; i < size; i++)
		help[i] = data[i];       // moves the members in the temporary array

	delete[]data;              // delete the temporary array
	data = help;

}

int& Vector::at(int index)           //change the vector in a particular index
{
	if (index >= size || index < 0) // when the input is uncorrect
	{
		std::cout << "ERROR\n"; 
		return data[0];
	}

	return data[index];          // return the index's place 
}

void Vector::insert(int val)          // add a vector within the class
{
	int* help = new int[size + 1];   // creat a temperory array
	for (int i = 0; i < size; i++)
		help[i] = data[i];          // moves the members in the temporary array

	help[size] = val;             // add the new 'val' in the last index

	delete[]data; 
	data = help;
	size++;
	if (size > capacity)      // when the size is over than the capacity
		capacity *= 2;       // double the capacity
}

void Vector::print()       // print the vector
{
	std::cout << "capacity: " << capacity
		<< " size: " << size << " values: ";
	for (int i = 0; i < size; i++) // print tha array
		if (data[i] != 0)
			std::cout << data[i] << " ";

	std::cout << "\n";
}