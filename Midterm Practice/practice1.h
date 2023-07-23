#include <iostream>

using namespace std;

class Complex
{
    private:
        double real;
        double imag;
    public:
        void setReal(double);
        void setImag(double);

        double getReal() const;
        double getImag() const;

        void input();
        void output() const;

        Complex friend operator+(Complex&, Complex&);
        Complex friend operator-(Complex&, Complex&);
        Complex friend operator*(Complex&, Complex&);
        Complex friend operator++(Complex&);
        Complex friend operator++(Complex&, int);
        Complex friend operator--(Complex&);
        Complex friend operator--(Complex&, int);

};