#include <iostream>

#include "CruiseShip.h"

using namespace std;

CruiseShip::CruiseShip(string name, string year, int cap)
{
	this->name = name;
	this->year = year;
	this->capacity = cap;
}

void CruiseShip::setCapacity(int cap)
{
	this->capacity = cap;
}

int  CruiseShip::getCapacity() const
{
	return this-> capacity;
}

void CruiseShip::print() const
{
	cout << "Name: " << this->name << endl;
	cout << "Capacity: " << this->capacity << endl << endl;
}

