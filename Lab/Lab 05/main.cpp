#include <iostream>

#include "ElectronicsStore.h"
#include "Laptop.h"

using namespace std;

int main()
{

    ElectronicsStore a("Test Store", "Vancouver", 0, 10);

    cout << a.getMaxLaptops() << endl;

    Laptop l("Asus", "Intel i7", 15.6, "Silver", 1);

    a.addLaptop(l);

    a.displayAll();

    return 0;
}