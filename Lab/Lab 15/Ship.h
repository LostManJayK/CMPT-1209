#pragma once

#include <iostream>

using namespace std;

class Ship
{
	protected:
		string name;
		string year;
	public:
		Ship(string="", string="");

		void setName(string);
		void setYear(string);

		string getName() const;
		string getYear() const;

		void print() const;



};
