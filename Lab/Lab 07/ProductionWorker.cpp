#include <iostream>

#include "ProductionWorker.h"

using namespace std;

ProductionWorker::ProductionWorker()
{
	this->name = "";
	this->employeeID = 0;
	this->hireYear = 0;
	this->shift = 1;
	this->payRate = 0.0;
}

ProductionWorker::ProductionWorker(string name, int employeeID, int hireYear, int shift, float payRate)
{
	this->name = name;
	this->employeeID = employeeID;
	this->hireYear = hireYear;
	this->shift = shift;
	this->payRate = payRate;
}

void ProductionWorker::setShift(int shift)
{
	this->shift = shift;
}

void ProductionWorker::setPayRate(float payRate)
{
	this->payRate = payRate;
}

int ProductionWorker::getShift() const
{
	return this->shift;
}

float ProductionWorker::getPayRate() const
{
	return this->payRate;
}