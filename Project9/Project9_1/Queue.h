/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 1
The project allows me to do actions on the binary tree like add limbs
or lower and measure the height of the tree etc.
*/
//---------------------------------------------------------
//  class Queue 
//  abstract class - simply defines protocol for
//   Queue operations
//---------------------------------------------------------

template <class T>
class Queue
{
public:
    // protocol for Queue operations
    virtual void clear() = 0;
    virtual T dequeue() = 0;
    virtual void enqueue(T) = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
};