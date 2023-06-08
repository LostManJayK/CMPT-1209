#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <string>

using namespace std;

class Laptop
{
    private:
        string manufacturer;
        string processor;
        float screenSize;
        string color;
        bool isNew;
    public:
        string getManufacturer() const;
        string getProcessor() const;
        float getScreenSize() const;
        string getColor() const;
        bool getIsNew() const;
        void setManufacturer(string);
        void setProcessor(string);
        void setScreenSize(float);
        void setColor(string);
        void setIsNew(bool);
        void input();
        void output() const;
        Laptop();
        Laptop(string, string = "AMD Ryzen", float = 17.3, string = "Silver", bool = false);
};

#endif