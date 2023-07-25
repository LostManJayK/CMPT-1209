#pragma once

#include <iostream>

using namespace std;

const double PI = 3.1415926;

class Vector2D
{
	private:
		double rho;
		double theta;
		void validate();
	public:
		Vector2D(double rho = 1, double theta = 0);

		void setRho(double);
		void setTheta(double);

		double getRho() const; //Non-negative
		double getTheta() const;
		double getX() const;
		double getY() const;

		Vector2D operator+(Vector2D&);
		Vector2D operator-(Vector2D&);

		ostream& operator<<(ostream&);
		istream& operator>>(istream&);

		friend bool operator>(Vector2D&, Vector2D&);
		friend bool operator>=(Vector2D&, Vector2D&);
		friend bool operator<(Vector2D&, Vector2D&);
		friend bool operator<=(Vector2D&, Vector2D&);
};