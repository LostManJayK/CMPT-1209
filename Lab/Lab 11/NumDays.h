#pragma once

#include <iostream>

using namespace std;

class NumDays
{

	private:
		const static int hourPerDay = 8;
		int hours;
		int days;
	public:
		NumDays();
		NumDays(int); //in hours

		void setHours(int);
		void setDays(double);

		int getHours() const;
		double getDays() const;

		NumDays friend operator-(const NumDays&, const NumDays&);
		NumDays operator--();
		NumDays operator--(int);
		


};
