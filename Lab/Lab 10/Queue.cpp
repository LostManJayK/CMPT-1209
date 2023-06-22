#include <iostream>

#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue(int s)
{
	queueArray = new T[s];
	capacity = s;
	numItems = 0;
}

template <class T>
Queue<T>::~Queue()
{
	delete[] queueArray;
}


//Copy constructor
template <class T>
Queue<T>::Queue(Queue<T> &q)
{
	this->capacity = q.capacity;
	this->numItems = q.numItems;
	this->queueArray = new T[this->capacity];
	for (int i = 0; i < this->numItems; i++)
	{
		this->queueArray[i] = q.queueArray[i];
	}
}

//Overloading assignment operator
template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>& q)
{
	delete[] this->queueArray;
	this->capacity = q.capacity;
	this->numItems = q.numItems;
	this->queueArray = new T[this->capacity];
	for (int i = 0; i < this->numItems; i++)
	{
		this->queueArray[i] = q.queueArray[i];
	}
}

template <class T>
void Queue<T>::enqueue(T entry)
{
	if (isFull())
		cout << "The queue is full.\n";
	else
	{
		queueArray[numItems] = entry;
		numItems++;
	}
}

template <class T>
void Queue<T>::dequeue(T& entry)
{
	if (isEmpty())
		cout << "The queue is empty.\n";
	else
	{
		entry = queueArray[0];
		for (int i = 0; i < numItems - 1; i++)
			queueArray[i] = queueArray[i + 1];
		numItems--;
	}
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return numItems == 0;
}

template <class T>
bool Queue<T>::isFull() const
{
	return numItems == capacity;
}

template <class T>
void Queue<T>::display() const
{
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		return;
	}
	cout << "\nThese are elements of the Queue.\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << queueArray[i] << endl;
	}
}