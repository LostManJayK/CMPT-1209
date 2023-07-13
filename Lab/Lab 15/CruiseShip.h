#pragma once

#include <iostream>

#include "Ship.h"

using namespace std;

class CruiseShip: protected Ship
{
	private:
		int capacity;
	public:

		CruiseShip(string="", string="", int=0);

		void setCapacity(int);
		int getCapacity() const;

		void print() const;
};