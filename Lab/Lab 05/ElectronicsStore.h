#ifndef ELECTRONICSSTORE_H
#define ELECTRONICSSTORE_H

#include <iostream>
#include "Laptop.h"

using namespace std;


class ElectronicsStore
{
    private:
        
        string storeName;
        string city;
        int numLaptops;
        int maxLaptops;
        Laptop *laptops;

    public:
        ElectronicsStore();
        ElectronicsStore(string storeName, string city="", int numLaptops=0, int maxLaptops=0);

        string getStoreName() const;
        string getCity() const;
        int getNumLaptops() const;
        int getMaxLaptops() const;

        void setStoreName(string);
        void setCity(string);
        void displayAll() const;
        void displayBrand(string) const;
        void addLaptop(Laptop);
        void sellLaptop(Laptop*);
};

#endif