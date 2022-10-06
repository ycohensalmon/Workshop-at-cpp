/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 2
The project adds numbers to a binary tree and also deletes and searches for books
*/
#pragma once
#include "Queue.h"

template <typename T>
class QueueVector : public Queue<T>
{
public:
	QueueVector(int max);
	//QueueVector(const QueueVector&);
	void clear() override;
	T dequeue() override;
	void enqueue(T value) override;
	T front() override;
	bool isEmpty() const override;
private:
	T* data;
	int capacity;
	int nextSlot;
	int firstUse;
};

//----------------------------------------------------------
//  class QueueVector implementation
//----------------------------------------------------------

template <typename T>
QueueVector<T>::QueueVector(int size) {
	capacity = size + 1;
	data = new T[capacity];
	clear();
}


template <typename T>
void QueueVector<T>::clear() {
	nextSlot = 0;
	firstUse = 0;
}


template <typename T>
T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];
}


template <typename T>
void QueueVector<T>::enqueue(T val) {
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}


template <typename T>
T QueueVector<T>::front() {
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}


template <typename T>
bool QueueVector<T>::isEmpty() const {
	return nextSlot == firstUse;
}