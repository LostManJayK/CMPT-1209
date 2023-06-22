#include <iostream>
#include <string>
using namespace std;
class IntStack
{
private:
    int* stackArray;
    int stackSize;
    int numElements;
public:
    IntStack(const IntStack&);
    IntStack operator=(const IntStack&);
    IntStack(int);
    ~IntStack();

    void push(int);
    void pop(int&);
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
};

IntStack::IntStack(const IntStack& stack)
{
    this->stackSize = stack.stackSize;
    this->numElements = stack.numElements;
    this->stackArray = new int[stackSize];
    for (int i = 0; i < this->numElements; i++)
    {
        *(this->stackArray + i) = *(stack.stackArray + i);
    }
}

IntStack IntStack::operator=(const IntStack& stack)
{
    delete[] this->stackArray;
    this->stackSize = stack.stackSize;
    this->numElements = stack.numElements;
    this->stackArray = new int[stackSize];
    for (int i = 0; i < this->numElements; i++)
    {
        *(this->stackArray + i) = *(stack.stackArray + i);
    }

    return *this;
}

IntStack::IntStack(int Size)
{
    stackArray = new int[Size];
    stackSize = Size;
    numElements = 0;
}
IntStack::~IntStack()
{
    delete[] stackArray;
}
void IntStack::push(int num)
{
    if (isFull())
        cout << "The stack is full.\n";
    else
    {
        stackArray[numElements] = num;
        numElements++;
    }
}
void IntStack::pop(int& num)
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
    {
        numElements--;
        num = stackArray[numElements];
    }
}
bool IntStack::isFull() const
{
    return numElements == stackSize;
}
bool IntStack::isEmpty() const
{
    return numElements == 0;
}
void IntStack::display() const
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
        for (int i = 0; i < numElements; i++)
            cout << stackArray[i] << "\t";
    cout << endl;
}
int main()
{

    int poppedVal=0;
    IntStack stack1(6);
    for (int i = 0; i < 5; i++)
    {
        stack1.push(i);
    }

    cout << "\nPopping..." << endl;
    stack1.pop(poppedVal);
    stack1.pop(poppedVal);

    IntStack stack2(6);
    stack2 = stack1;
    stack2.push(5);
    stack2.push(6);

    cout << "\nPopping..." << endl;
    stack2.pop(poppedVal);

    IntStack stack3(stack2);
    stack3.pop(poppedVal);
    stack3.pop(poppedVal);
    stack3.push(10);
    stack3.push(11);
    

    cout << "\nStack 1:" << endl;
    stack1.display();

    cout << "\nStack 2:" << endl;
    stack2.display();

    cout << "\nStack 3:" << endl;
    stack3.display();
}
