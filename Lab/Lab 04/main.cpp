#include <iostream>
#include "Complex.h"

using namespace std;

Complex operator+(const Complex &a, const Complex &b)
{
    Complex c;

    c.setReal(a.getReal() + b.getReal());
    c.setImaginary(a.getImaginary() + b.getImaginary());
    
    return c;
}

Complex operator-(const Complex &a, const Complex &b)
{
    Complex c;

    c.setReal(a.getReal() - b.getReal());
    c.setImaginary(a.getImaginary() - b.getImaginary());

    return c;
}

Complex operator*(const Complex &a, const Complex &b)
{
    Complex c;

    c.setReal((a.getReal() * b.getReal()) + ( - 1 * a.getImaginary() * b.getImaginary()));
    c.setImaginary((a.getImaginary() * b.getReal()) + (a.getReal() * b.getImaginary()));

    return c;
}


bool operator>(const Complex &a, const Complex &b)
{
    return a.getMagnitude() > b.getMagnitude();
}

bool operator<(const Complex &a, const Complex &b)
{
    return a.getMagnitude() < b.getMagnitude();
}

bool operator>=(const Complex &a, const Complex &b)
{
    return a.getMagnitude() >= b.getMagnitude();
}

bool operator<=(const Complex& a, const Complex& b)
{
    return a.getMagnitude() <= b.getMagnitude();
}

bool operator==(const Complex& a, const Complex& b)
{
    return a.getMagnitude() == b.getMagnitude();
}

bool operator!=(const Complex& a, const Complex& b)
{
    return a.getMagnitude() != b.getMagnitude();
}

void operator+=(Complex &a, const Complex &b)
{
    a = a + b;
}

void operator-=(Complex& a, const Complex& b)
{
    a = a - b;
}

void operator*=(Complex& a, const Complex& b)
{
    a = a * b;
}

Complex operator++(Complex& a)
{
    a.setReal(a.getReal() + 1);
    return a;
}
Complex operator++(Complex &a, int n)
{
    Complex b = a;
    a.setReal(a.getReal() + 1);
    return b;
}

Complex operator--(Complex& a)
{
    a.setReal(a.getReal() - 1);
    return a;
}

Complex operator--(Complex& a, int n)
{
    Complex b = a;
    a.setReal(a.getReal() - 1);
    return b;
}


int main()
{
    Complex a, b(2), c(3, -4);

    a = c--;
    a.output();
    c.output();
}

