#include <iostream>
#include <stdexcept>

#include "Q1.h"

using std::string;

//PersonData class

//Constructors
PersonData::PersonData()
{
    this->lastName = "";
    this->firstName = "";
    this->address = "";
    this->city = "";
    this->state = "";
    this->zip = "";
    this->phone = "";
}
PersonData::PersonData(string lastName, string firstName, string address, string city, string state, string zip, string phone)
{
    this->lastName = lastName;
    this->firstName = firstName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
}

//Accessors
string PersonData::getLastName() const
{
    return this->lastName;
}

string PersonData::getFirstName() const
{
    return this->firstName;
}

string PersonData::getAddress() const
{
    return this->address;
}

string PersonData::getCity() const
{
    return this->city;
}

string PersonData::getState() const
{
    return this->state;
}

string PersonData::getZip() const
{
    return this->zip;
}
string PersonData::getPhone() const
{
    return this->phone;
}

//Mutators
void PersonData::setLastName(string lastName)
{
    this->lastName = lastName;
}
void PersonData::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void PersonData::setAddress(string address)
{
    this->address = address;
}
void PersonData::setCity(string city)
{
    this->city = city;
}
void PersonData::setState(string state)
{
    this->state = state;
}
void PersonData::setZip(string zip)
{
    this->zip = zip;
}
void PersonData::setPhone(string phone)
{
    this->phone = phone;
}


//CustomerData class

//Static Vars
int CustomerData::customerTracker = 0;

//Constructors
CustomerData::CustomerData()
{
    this->lastName = "";
    this->firstName = "";
    this->address = "";
    this->city = "";
    this->state = "";
    this->zip = "";
    this->phone = "";
    this->customerNumber = ++CustomerData::customerTracker;
    this->mailingList = false;
}
CustomerData::CustomerData(string lastName, string firstName, string address, string city, string state, string zip, string phone, bool mailingList) : PersonData(lastName, firstName, address, city, state, zip, phone)
{
    this->lastName = lastName;
    this->firstName = firstName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
    this->customerNumber = ++CustomerData::customerTracker;
    this->mailingList = mailingList;
}

//Accessors
int CustomerData::getCustomerNumber() const
{
    return this->customerNumber;
}
bool CustomerData::getMailingList() const
{
    return this->mailingList;
}

//Mutators
void CustomerData::setCustomerNumber(int customerNumber)
{
    this->customerNumber = customerNumber;
}

void CustomerData::setMailingList(bool mailingList)
{
    this->mailingList = mailingList;
}


//PreferredCustomer class

PreferredCustomer::PreferredCustomer(string lastName, string firstName, string address, string city, string state, string zip, string phone, bool mailingList, double purchasesAmount) : CustomerData(lastName, firstName, address, city, state, zip, phone, mailingList)
{
    this->purchasesAmount = purchasesAmount;
    this->setDiscountLevel();
}

void PreferredCustomer::setDiscountLevel()
{
    if(this->purchasesAmount < 500)
    {
        this->discountLevel = 0;
    }
    else if(this->purchasesAmount < 1000)
    {
        this->discountLevel = .05;
    }
    else if(this->purchasesAmount < 1500)
    {
        this->discountLevel = .06;
    }
    else if(this->purchasesAmount < 2000)
    {
        this->discountLevel = .07;
    }
    else
    {
        this->discountLevel = .10;
    }
}

double PreferredCustomer::getDiscountLevel() const
{
    return this->discountLevel;
}

double PreferredCustomer::getPurchasesAmount() const
{
    return this->purchasesAmount;
}

void PreferredCustomer::purchase(double value)
{
    try
    {
        if(value < 0)
        {
            throw std::invalid_argument("Purchase values must be positive.\n");
        }
        this->purchasesAmount += value * (1-this->discountLevel);
        this->setDiscountLevel();
    }
    catch(const std::exception e)
    {
        std::cerr << e.what() << '\n';
    }
}