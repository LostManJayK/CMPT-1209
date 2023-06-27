#include <iostream>

#include "NumDays.h"

using namespace std;

NumDays operator+(const NumDays& a, const NumDays& b)
{
	NumDays c;
	c.setHours(a.getHours() + b.getHours());
	return c;
}

NumDays operator-(const NumDays& a, const NumDays& b)
{
	NumDays c;
	c.setHours(a.hours - b.hours);
	return c;
}

//Prefix
NumDays operator++(NumDays &a)
{
	int num = a.getHours() + 1;

	a.setHours(num);

	return a;
}

//Postfix
NumDays operator++(NumDays &a, int)
{
	int num = a.getHours() + 1;
	a.setHours(num);

	return a;
}

int main()
{
    NumDays a;
    NumDays b(18);

	a.setHours(20);

    NumDays c;

    b--;

	c = ++a + b--;

	cout << c.getHours() << endl;
	cout << a.getHours() << endl;
	cout << b.getHours() << endl;
}

