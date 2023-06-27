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

	Queue(int);
	Queue(Queue<T>&);

	~Queue();
	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	bool isFull() const;
	void display() const;
	Queue<T>& operator=(Queue<T>&);
};