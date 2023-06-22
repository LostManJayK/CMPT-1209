#include "Rational.h"
#include <iostream>

using namespace std;

void Rational::reduce()
{
    int x = abs(numer);
    int y = abs(denom);
    // find minimum of x and y
    int min = x;
    if (y < x)
        min = y;
    // finding a common factor greater than 1
    int gcf = 1;
    for (int i = 2; i <= min; i++) {
        if (x % i == 0 && y % i == 0) {
            gcf = i;
        }
    }
    numer = numer / gcf;
    denom = denom / gcf;
    if (denom < 0)
    {
        numer = -numer;
        denom = -denom;
    }
}
Rational::Rational()
{
    numer = 0;
    denom = 1;
}
Rational::Rational(int x, int y)
{
    numer = x;
    if (y != 0)
        denom = y;
    else
        denom = 1;
    reduce();
}
int Rational::getNumer() const
{
    return numer;
}
int Rational::getDenom() const
{
    return denom;
}
void Rational::setNumer(int x)
{
    numer = x;
    reduce();
}
void Rational::setDenom(int x)
{
    denom = x;
    if (denom == 0)
        denom = 1;
    reduce();
}
void Rational::input()
{
    cout << "Numerator? ";
    cin >> numer;
    cout << "Denominator? ";
    cin >> denom;
    while (denom == 0)
    {
        cout << "Denominator can't be zero!\n";
        cout << "Denominator? ";
        cin >> denom;
    }
    reduce();
}
void Rational::output() const
{
    if (denom != 1)
        cout << numer << "/" << denom << endl;
    else
        cout << numer << endl;
}