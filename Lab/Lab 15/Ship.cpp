#include <iostream>

#include "Ship.h"

using namespace std;

Ship::Ship(string name, string year)
{
	this->name = name;
	this->year = year;
}

void Ship::setName(string name)
{
	this->name = name;
}

void Ship::setYear(string year)
{
	this->year = year;
}

string Ship::getName() const
{
	return this->name;
}

string Ship::getYear() const
{
	return this->year;
}

void Ship::print() const
{
	cout << "Name: " << this->name << endl;
	cout << "Year: " << this->year << endl << endl;
}