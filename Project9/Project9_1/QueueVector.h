/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 1
The project allows me to do actions on the binary tree like add limbs
or lower and measure the height of the tree etc.
*/
#include"Queue.h"

//-------------------------------------------------------
//  class QueueVector
//  Queue implemented using vector operations
//-------------------------------------------------------
template <class T>
class QueueVector : public Queue<T>
{
public:
    QueueVector(int max);

    T front() const;
    T dequeue();
    void enqueue(T val);
    void clear();
    bool isEmpty() const;

private:
    T* data;
    int capacity;
    int nextSlot;
    int firstUse;
};

template <class T>
QueueVector<T>::QueueVector(int size)
{
    capacity = size + 1;
    data = new T[capacity];
    clear();
}

template <class T>
void QueueVector<T>::clear()
{
    nextSlot = 0;
    firstUse = 0;
}

template <class T>
T QueueVector<T>::dequeue()
{
    // can not dequeue from an empty queue
    if (isEmpty()) throw "Queue is empty";
    int dataloc = firstUse;
    ++firstUse %= capacity;
    return data[dataloc];
}

template <class T>
void QueueVector<T>::enqueue(T val)
{
    // make sure Queue has not overflowed
    if ((nextSlot + 1) % capacity == firstUse)
        throw "the Queue is full";
    data[nextSlot] = val;
    ++nextSlot %= capacity;
}

template <class T>
T QueueVector<T>::front() const
{
    // can not return a value from an empty Queue
    if (isEmpty()) throw "Queue is empty";
    return data[firstUse];
}

template <class T>
bool QueueVector<T>::isEmpty() const
{    // Queue is empty if next slot is
    // pointing to same location as first use
    return nextSlot == firstUse;
}