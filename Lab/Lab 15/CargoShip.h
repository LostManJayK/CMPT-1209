#pragma once

#include <iostream>

#include "Ship.h"

using namespace std;

class CargoShip : protected Ship
{
private:
	int capacity;
public:
	CargoShip(string = "", string = "", int = 0);

	void setCapacity(int);
	int getCapacity() const;

	void print() const;



};
