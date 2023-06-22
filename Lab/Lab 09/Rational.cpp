#include <iostream>
#include <string>
#include <cmath>

#include "Rational.h"

using namespace std;

Rational::Rational()
{
	this->numerator = 0;
	this->denominator = 1;

}

Rational::Rational(int num, int denom)
{
	this->numerator = num;
	this->denominator = denom;
	this->reduce();
}

Rational::~Rational()
{
	cout << "Rational deleted" << endl;
}

void Rational::input()
{
	cout << "Enter the numerator: ";

	cin >> this->numerator;

	cout << "Enter the denominator: ";

	do
	{
		cin >> this->denominator;
		if (this->denominator == 0)
		{
			cout << "Denominator must not be zero, enter a non-zero value: ";
		}
	} while (this->denominator == 0);
	
}


void Rational::reduce()
{
	int min=1, max=1, sign1 =1, sign2=1;
	int gcf=1;

	sign1 = (this->numerator < 0) ? -1 : 1;
	sign2 = (this->denominator < 0) ? -1 : 1;

	int sign = sign1 * sign2;

	if (abs(this->numerator) < abs(this->denominator))
	{
		min = abs(this->numerator);
		max = abs(this->denominator);
	}
	else
	{
		max = abs(this->numerator);
		min = abs(this->denominator);
	}

	if (max % min == 0)
	{
		gcf = min;
	}
	else
	{
		for (int i = 2; i <= min / 2; i++)
		{
			if((min % i == 0) && (max % i == 0))
			{
				gcf = i;
			}
		}
	}

	this->numerator = abs(this->numerator) / (gcf * sign);
	this->denominator = abs(this->denominator / gcf);

}



//Mutators
void Rational::setNumerator(int num)
{
	this->numerator = num;
}

void Rational::setDenominator(int denom)
{
	this->denominator = denom;

	do
	{
		if (this->denominator == 0)
		{
			cout << "Denominator must not be zero, enter a non-zero value: ";
			cin >> this->denominator;
		}
	} while (this->denominator == 0);
}

//Accessors
int Rational::getNumerator()
{
	return this->numerator;
}
int Rational::getDenominator()
{
	return this->denominator;
}

void Rational::getRatio()
{
	cout << this->numerator << "/" << denominator << endl;
}
