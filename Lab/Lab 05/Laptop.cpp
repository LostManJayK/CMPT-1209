#include <iostream>
#include <string>
#include <iomanip>

#include "Laptop.h"

using namespace std;

Laptop::Laptop()
{
    this->manufacturer="";
    this->processor="";
    this->screenSize=0.0;
    this->color="";
    this->isNew=false;
}

Laptop::Laptop(string manufacturer, string processor, float screenSize, string color, bool isNew)
{

    this->manufacturer=manufacturer;
    this->processor=processor;
    this->screenSize=screenSize;
    this->color=color;
    this->isNew=isNew;

}
string Laptop::getManufacturer() const
{
    return this->manufacturer;
}

string Laptop::getProcessor() const
{
    return this->processor;
}

float Laptop::getScreenSize() const
{
    return this->screenSize;
}
    
string Laptop::getColor() const
{
    return this->color;
}
bool Laptop::getIsNew() const
{
    return this->isNew;
}

void Laptop::setManufacturer(string manufactuer)
{
    this->manufacturer=manufacturer;
}
void Laptop::setProcessor(string processor)
{
    this->processor=processor;
}
void Laptop::setScreenSize(float screenSize)
{
    this->screenSize=screenSize;
}
void Laptop::setColor(string color)
{
    this->color=color;
}
void Laptop::setIsNew(bool isNew)
{
    this->isNew = isNew;
}

void Laptop::input()
{
    cout << "Enter laptop manufacturer: ";
    getline(cin, this->manufacturer);

    cout << "Enter processor: ";
    getline(cin, this->processor);

    cout << "Enter screen size: ";
    cin >> this->screenSize;
    cin.ignore();

    cout << "Enter color: ";
    getline(cin, this->color);

    cout << "Is this laptop new? (Enter 1 for yes or 0 for no); ";
    cin >> this->isNew;
}

void Laptop::output() const
{
    cout << setw(15) << left << this->manufacturer;
    cout << setw(15) << left << this->processor;
    cout << setw(5) << left << this->screenSize;
    cout << setw(10) << left << this->color;

    char new_as_char = (this->isNew)? 'Y' : 'N';
    cout << setw(5) << left << new_as_char << endl;
}





