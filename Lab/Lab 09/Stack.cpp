#include "Stack.h"
#include <iostream>

using namespace std;

template<class T>
Stack<T>::Stack(int Size)
{
    stackArray = new T[Size];
    stackSize = Size;
    numElements = 0;
}

template<class T>
Stack<T>::Stack(const Stack<T>& a)
{
    stackSize = a.stackSize;
    stackArray = new int[stackSize];
    numElements = a.numElements;

    for (int i = 0; i < numElements; i++)
    {
        stackArray[i] = a.stackArray[i];
    }
}

template<class T>
Stack<T>::~Stack()
{
    delete[] stackArray;
}

template<class T>
void Stack<T>::push(T value)
{
    if (isFull())
        cout << "The stack is full.\n";
    else
    {
        stackArray[numElements] = value;
        numElements++;
    }
}

template<class T>
void Stack<T>::pop(T& num)
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
    {
        numElements--;
        num = stackArray[numElements];
    }
}

template<class T>
bool Stack<T>::isFull() const
{
    return numElements == stackSize;
}

template<class T>
bool Stack<T>::isEmpty() const
{
    return numElements == 0;
}

template<class T>
void Stack<T>::display() const
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
        for (int i = 0; i < numElements; i++)
            cout << stackArray[i] << "\t";
    cout << endl;
}

template<class T>
void Stack<T>::operator=(Stack<T> right)
{
    stackSize = right.stackSize;
    stackArray = new T[stackSize];
    numElements = right.numElements;

    for (int i = 0; i < numElements; i++)
    {
        stackArray[i] = right.stackArray[i];
    }
}