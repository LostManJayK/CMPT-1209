#include <iostream>

#include "Q1.h"

using std::string, std::cout, std::cin, std::endl;

int main()
{
    PreferredCustomer a("Spence", "Andrew", "101 Royal Ave", "New Westminster", "BC", "V3L 1H1", "672-514-2253", true, 0.0);
    PreferredCustomer b("Spence", "Andrew", "101 Royal Ave", "New Westminster", "BC", "V3L 1H1", "672-514-2253", true, 0.0);
    PreferredCustomer c("Spence", "Andrew", "101 Royal Ave", "New Westminster", "BC", "V3L 1H1", "672-514-2253", true, 0.0);
    

    cout << a.getCustomerNumber() << endl;
    cout << b.getCustomerNumber() << endl;
    cout << c.getCustomerNumber() << endl;
    cout << endl;

    cout << "Discount Level: " << a.getDiscountLevel() << endl;
    cout << "Purchase Total: " << a.getPurchasesAmount() << endl;
    cout << endl;

    a.purchase(1500);

    cout << "Discount Level: " << a.getDiscountLevel() << endl;
    cout << "Purchase Total: " << a.getPurchasesAmount() << endl;
    cout << endl;

    a.purchase(500);

    cout << "Discount Level: " << a.getDiscountLevel() << endl;
    cout << "Purchase Total: " << a.getPurchasesAmount() << endl;
    cout << endl;

    a.purchase(100);
    cout << "Discount Level: " << a.getDiscountLevel() << endl;
    cout << "Purchase Total: " << a.getPurchasesAmount() << endl;
    cout << endl;
}