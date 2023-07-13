#include <iostream>

#include "CargoShip.h"

using namespace std;

CargoShip::CargoShip(string name, string year, int cap)
{
	this->name = name;
	this->year = year;
	this->capacity = cap;
}

void CargoShip::setCapacity(int cap)
{
	this->capacity = cap;
}

int CargoShip::getCapacity() const
{
	return this->capacity;
}

void CargoShip::print() const
{
	cout << "Name: " << this->name << endl;
	cout << "Capacity: " << this->capacity << endl << endl;
}