#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <iostream>
#include "Employee.h"

using namespace std;

class ProductionWorker :public Employee
{
	private:
		int  shift;
		float payRate;
	public:
		ProductionWorker();
		ProductionWorker(string, int=0, int=0, int=0, float = 0.0);
		void setShift(int);
		void setPayRate(float);
		int getShift() const;
		float getPayRate() const;

};

#endif
