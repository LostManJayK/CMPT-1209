#include <iostream>

#include "Rational.h"

using namespace std;

Rational operator+(Rational a, Rational b)
{
	Rational c;
	c.setNumerator(a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator());
	c.setDenominator(a.getDenominator() * b.getDenominator());

	return c;
}


void operator+=(Rational &a, Rational b)
{
	a.setNumerator(a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator());
	a.setDenominator(a.getDenominator() * b.getDenominator());
}

int main()
{

	Rational c(-6, -8), d(9, -6);

	Rational e;
	e = c+d;
	e.getRatio();

	return 0;
}