#include <iostream>

#include "NumDays.h"

using namespace std;

NumDays::NumDays()
{
	this->hours = 8;
	this->days = 1;
}

NumDays::NumDays(int hrs)
{
	this->hours = hrs;
	this->days = hrs / 8;
}

void NumDays::setHours(int hrs)
{
	this->hours = hrs;
	this->days = hrs / 8;
}

void NumDays::setDays(double d)
{
	this->days = d;
	this->hours = d * 8;
}

int NumDays::getHours() const
{
	return this->hours;
}

double NumDays::getDays() const
{
	return this->days;
}

NumDays NumDays::operator--()
{
	this->hours--;
	this->days = this->hours / 8;

	return *this;
}

NumDays NumDays::operator--(int post)
{
	this->hours--;
	this->days = this->hours / 8;

	return *this;
}
