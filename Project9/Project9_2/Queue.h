/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 2
The project adds numbers to a binary tree and also deletes and searches for books
*/
#pragma once

template <typename T>
class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(T value) = 0;
    virtual T dequeue() = 0;
    virtual T front() = 0;
    virtual bool isEmpty() const = 0;
};