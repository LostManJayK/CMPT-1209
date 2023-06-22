#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{
	//int Queue
	Queue<int> iQueue(5);
	int catchVar;
	iQueue.enqueue(5);
	iQueue.display();
	iQueue.enqueue(12);
	iQueue.display();
	iQueue.enqueue(8);
	iQueue.display();
	iQueue.enqueue(15);
	iQueue.display();
	iQueue.enqueue(17);
	iQueue.display();
	iQueue.enqueue(5);
	iQueue.display();

	iQueue.dequeue(catchVar);
	iQueue.display();
	iQueue.dequeue(catchVar);
	iQueue.display();
	iQueue.enqueue(99);
	iQueue.display();

	//string Queue
	Queue<string> sQueue(5);
	string sCatchVar;
	sQueue.enqueue("Hello");
	sQueue.display();
	sQueue.enqueue("World");
	sQueue.display();
	sQueue.enqueue("My");
	sQueue.display();
	sQueue.enqueue("Name");
	sQueue.display();
	sQueue.enqueue("Name");
	sQueue.display();
	sQueue.enqueue("Is");
	sQueue.display();

	sQueue.dequeue(sCatchVar);
	sQueue.display();
	sQueue.dequeue(sCatchVar);
	sQueue.display();
	sQueue.enqueue("Andrew");
	sQueue.display();

	return 0;
}