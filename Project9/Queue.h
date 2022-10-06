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