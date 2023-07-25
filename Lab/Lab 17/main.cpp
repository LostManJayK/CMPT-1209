// Lab17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Vector2D.h"

using namespace std;

bool operator==(Vector2D& a, Vector2D& b)
{
    return (a.getRho() == b.getRho()) && (a.getTheta() == b.getTheta());
}

bool operator!=(Vector2D& a, Vector2D& b)
{
    return (a.getRho() == b.getRho()) || (a.getTheta() == b.getTheta());
}

bool operator>(Vector2D& a, Vector2D& b)
{
    return(a.rho > b.rho);
}

bool operator>=(Vector2D& a, Vector2D& b)
{
    return(a.rho >= b.rho);
}
bool operator<(Vector2D& a, Vector2D& b)
{
    return(a.rho < b.rho);
}
bool operator<=(Vector2D& a, Vector2D& b)
{
    return(a.rho <= b.rho);
}

int main()
{
    Vector2D a(2.5, 5), b(3, 6);

    a + b << cout;

    a >> cin;
}


