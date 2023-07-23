#include <iostream>

using std::string;

class PersonData
{
    protected:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string zip;
        string phone;

    public:

        //Constructors
        PersonData();
        PersonData(string, string="", string="", string="", string="", string="", string="");

        //Accessors
        string getLastName() const;
        string getFirstName() const;
        string getAddress() const;
        string getCity() const;
        string getState() const;
        string getZip() const;
        string getPhone() const;

        //Mutators
        void setLastName(string);
        void setFirstName(string);
        void setAddress(string);
        void setCity(string);
        void setState(string);
        void setZip(string);
        void setPhone(string);
};

class CustomerData: public PersonData
{

    static int customerTracker;

    protected:
        bool mailingList;
        int customerNumber;
        
    public:



        //Constructors
        CustomerData();
        CustomerData(string, string="", string="", string="", string="", string="", string="", bool=false);

        //Accessors
        int getCustomerNumber() const;
        bool getMailingList() const;

        //Mutators
        void setCustomerNumber(int);
        void setMailingList(bool);
};

class PreferredCustomer: public CustomerData
{
    private:
        double purchasesAmount;
        double discountLevel;
        void setDiscountLevel();

    public:

        PreferredCustomer(string, string="", string="", string="", string="", string="", string="", bool=false, double=0.0);

        void purchase(double);

        double getDiscountLevel() const;
        double getPurchasesAmount() const;

        void setDiscountLevel(double);

};