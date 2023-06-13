#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee
{
	protected:
		string name;
		int employeeID;
		int hireYear;
	public:
		Employee();
		Employee(string, int = 0, int = 0);
		void setName(string);
		void setEmployeeID(int);
		void setHireYear(int);
		string getName() const;
		int getEmployeeID() const;
		int getHireYear() const;
};

#endif
