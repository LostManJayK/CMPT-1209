#include <iostream>

#include "Employee.h"
#include "ProductionWorker.h"

using namespace std;

int main()
{
    ProductionWorker a("Andrew", 123456789, 2023, 1, 20.50);

    cout << a.getName() << " " << a.getEmployeeID() << " " << a.getHireYear() << " " << a.getShift() << " " << a.getPayRate() << endl;
}

