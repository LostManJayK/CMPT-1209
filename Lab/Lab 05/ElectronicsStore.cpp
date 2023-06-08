#include <iostream>
#include <algorithm>

#include "ElectronicsStore.h"

using namespace std;
ElectronicsStore::ElectronicsStore()
{
    this->storeName="";
    this->city="";
    this->numLaptops=0;
    this->maxLaptops=0;
}
ElectronicsStore::ElectronicsStore(string storeName, string city, int numLaptops, int maxLaptops)
{
    this->storeName=storeName;
    this->city=city;
    this->numLaptops=numLaptops;
    this->maxLaptops=maxLaptops;

    this->laptops = new Laptop[this->maxLaptops];

    for(int i=0; i<this->numLaptops; i++)
    {
        Laptop l;
        l.input();
        this->addLaptop(l);
        this->numLaptops--;
    }

}

string ElectronicsStore::getStoreName() const
{
    return this->storeName;
}
string ElectronicsStore::getCity() const
{
    return this->city;
}
int ElectronicsStore::getNumLaptops() const
{
    return this->numLaptops;
}
int ElectronicsStore::getMaxLaptops() const
{
    return this->maxLaptops;
}

void ElectronicsStore::setStoreName(string storeName)
{
    this->storeName = storeName;
}
void ElectronicsStore::setCity(string city)
{
    this->city = city;
}

void ElectronicsStore::addLaptop(Laptop l)
{
    if(this->numLaptops==this->maxLaptops)
    {
        cout << "Inventory full!" << endl;
    }
    else
    {
        this->laptops[this->numLaptops] = l;
        this->numLaptops++;
    }
}
void ElectronicsStore::sellLaptop(Laptop *pl)
{
     int endIndex = this->laptops + this->numLaptops - pl - 1;
     for(int i=0; i<endIndex; i++)
     {
        *(pl+i) = *(pl+i+1);
     }

     this->numLaptops--;
}

void ElectronicsStore::displayAll() const
{
    for(int i=0; i<this->numLaptops; i++)
    {
        laptops[i].output();
    }
}
void ElectronicsStore::displayBrand(string brand) const
{
    for(int i=0; i<this->numLaptops; i++)
    {
        if(laptops[i].getManufacturer() == brand)
        {
            laptops[i].output();
        }
    }
}
