#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
	T* queueArray;
	int capacity;
	int numItems;
public:

	template <class T>
	Queue<T>(int s)
	{
		queueArray = new T[s];
		capacity = s;
		numItems = 0;
	};

	template <class T>
	Queue<T>::Queue(Queue<T>& q)
	{
		this->capacity = q.capacity;
		this->numItems = q.numItems;
		this->queueArray = new T[this->capacity];
		for (int i = 0; i < this->numItems; i++)
		{
			this->queueArray[i] = q.queueArray[i];
		}
	};

	~Queue();
	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	bool isFull() const;
	void display() const;
	Queue<T>& operator=(Queue<T>&);
};