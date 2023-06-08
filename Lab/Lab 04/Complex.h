#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
	private:
		double real;
		double imaginary;

	public:
		Complex();
		Complex(double real, double imaginary = 0);
		void setReal(double real);
		void setImaginary(double imaginary);
		double getReal() const;
		double getImaginary() const;
		double getMagnitude() const;
		void input();
		void output() const;

		friend bool operator>(const Complex&, const Complex&);
		friend bool operator<(const Complex&, const Complex&);
		friend bool operator>=(const Complex&, const Complex&);
		friend bool operator<=(const Complex&, const Complex&);
		friend bool operator==(const Complex&, const Complex&);
		friend bool operator!=(const Complex&, const Complex&);

		friend Complex operator++(Complex&);
		friend Complex operator++(Complex&, int);
		friend Complex operator--(Complex&);
		friend Complex operator--(Complex&, int);

};

#endif
