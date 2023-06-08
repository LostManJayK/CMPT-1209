#include <iostream>
#include <cmath>

#include "Complex.h"

using namespace std;

Complex::Complex()
{
	this->real = 1;
	this -> imaginary = 1;
}

Complex::Complex(double real, double imaginary)
{
	this->real = real;
	this->imaginary = (imaginary == 0) ? 1 : imaginary;
}

void Complex::setReal(double real)
{
	this->real = real;
}

void Complex::setImaginary(double imaginary)
{
	this->imaginary = imaginary;
}

double Complex::getReal() const
{
	return this->real;
}

double Complex::getImaginary() const
{
	return this->imaginary;
}

double Complex::getMagnitude() const
{
	double mag = pow(this->real, 2) + pow(this->imaginary, 2);

	return sqrt(mag);
}

void Complex::input()
{
	cout << "Enter real part of complex number: ";
	cin >> this->real;

	cout << "Enter imaginary part of complex number: ";
	cin >> this->imaginary;
}

void Complex::output() const
{
	char sign = (this->imaginary < 0) ? '-' : '+';
	cout << this->real << " " << sign << " j" << abs(this->imaginary) << endl;
}