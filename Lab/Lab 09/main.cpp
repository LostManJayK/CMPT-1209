#include <iostream>
#include <string>
#include "Stack.h"
#include "Rational.h"

using namespace std;


int main()
{
    int catchVar;// Define a stack object to hold 5 values.
    Stack<int> myStack(5); // Define a stack object to hold 5 values.
    Rational a(1, 2), b, c(2), d(-6,-8), e(2,3);


    // Push the values 5, 10, 15, 20, and 25 onto the stack.
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);
    myStack.push(25);
    cout << "myStack: " << endl;
    myStack.display();
    cout << endl;

    // Pop myStack
    cout << "Popping...\n";
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;

    string stringVar;
    Stack<string> stringStack(5);
    


    // Push
    stringStack.push("a");
    stringStack.push("b");
    stringStack.push("c");
    stringStack.push("d");
    stringStack.push("e");
    cout << "stringStack: " << endl;
    stringStack.display();
    cout << endl;

    // Pop stringStack
    cout << "Popping...\n";
    stringStack.pop(stringVar);
    cout << stringVar << endl;
    stringStack.pop(stringVar);
    cout << stringVar << endl;
    stringStack.pop(stringVar);
    cout << stringVar << endl;
    stringStack.pop(stringVar);
    cout << stringVar << endl;
    stringStack.pop(stringVar);
    cout << stringVar << endl;

    cout << endl;
    

    Rational rationalVar;
    Stack<Rational> rationalStack(5);

    // Push
    rationalStack.push(a);
    rationalStack.push(b);
    rationalStack.push(c);
    rationalStack.push(d);
    rationalStack.push(e);
    cout << "rationalStack: " << endl;
    /*rationalStack.display();
    cout << endl;*/

    //// Pop stringStack
    //cout << "Popping...\n";
    //rationalStack.pop(rationalVar);
    //rationalVar.output();
    //rationalStack.pop(rationalVar);
    //rationalVar.output();
    //rationalStack.pop(rationalVar);
    //rationalVar.output();
    //rationalStack.pop(rationalVar);
    //rationalVar.output();
    //rationalStack.pop(rationalVar);
    //rationalVar.output();




    return 0;
}

