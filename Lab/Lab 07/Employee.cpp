#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
	this->name = "";
	this->employeeID = 0;
	this->hireYear = 0;
}

Employee::Employee(string name, int employeeID, int hireYear)
{
	this->name = name;
	this->employeeID = employeeID;
	this->hireYear = hireYear;
}

void Employee::setName(string name)
{
	this->name = name;
}
void Employee::setEmployeeID(int employeeID)
{
	this->employeeID = employeeID;
}
void Employee::setHireYear(int hireYear)
{
	this->hireYear = hireYear;
}
string Employee::getName() const
{
	return this->name;
}
int Employee::getEmployeeID() const
{
	return this->employeeID;
}
int Employee::getHireYear() const
{
	return this->hireYear;
}

