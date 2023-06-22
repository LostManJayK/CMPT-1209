#pragma once
#include <iostream>

template<class T>
class Stack
{
private:
    T* stackArray;
    int stackSize;
    int numElements;
public:
    Stack(int Size)
    {
        stackArray = new T[Size];
        stackSize = Size;
        numElements = 0;
    }

    Stack(const Stack<T>& a)
    {
        stackSize = a.stackSize;
        stackArray = new T[stackSize];
        numElements = a.numElements;

        for (int i = 0; i < numElements; i++)
        {
            stackArray[i] = a.stackArray[i];
        }
    }

    ~Stack()
    {
        delete[] stackArray;
    }

    void push(T value)
    {
        if (isFull())
            std::cout << "The stack is full.\n";
        else
        {
            stackArray[numElements] = value;
            numElements++;
        }
    }

    void pop(T& num)
    {
        if (isEmpty())
            std::cout << "The stack is empty.\n";
        else
        {
            numElements--;
            num = stackArray[numElements];
        }
    }

    bool isFull() const
    {
        return numElements == stackSize;
    }

    bool isEmpty() const
    {
        return numElements == 0;
    }

    void display() const
    {
        if (isEmpty())
            std::cout << "The stack is empty.\n";
        else
            for (int i = 0; i < numElements; i++)
                std::cout << stackArray[i] << "\t";
        std::cout << std::endl;
    }

    void operator=(Stack<T> right)
    {
        stackSize = right.stackSize;
        stackArray = new T[stackSize];
        numElements = right.numElements;

        for (int i = 0; i < numElements; i++)
        {
            stackArray[i] = right.stackArray[i];
        }
    }
};
