#include <iostream>
#include <cmath>
#include <exception>

#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D(double rho, double theta)
{
	this->rho = rho;
	this->theta = theta;
	this->validate();
}

void Vector2D::validate()
{
	this->theta = fmod(this->theta, 360);
	if (this->theta > 180)
	{
		this->theta = (this->theta - 360);
	}
	else if (this->theta < -180)
	{
		this->theta = (this->theta + 360);
	}

	if (this->rho < 0)
	{
		cout << "Rho vlaue may not be negative. Converting to positive." << endl;
		this->rho *= -1;
	}
}

void Vector2D::setRho(double rho)
{
	try
	{
		if (rho < 0)
		{
			throw invalid_argument("Received negative value.");
			this->rho = rho;
		}
	}
	catch (invalid_argument e)
	{
		cout << e.what() << ": Rho may not be negative, converting to positive." << endl;
		this->rho = (rho * -1);
	}
	
}

void Vector2D::setTheta(double theta)
{
	this->theta = theta;
	this->validate();
}

double Vector2D::getRho() const //Non-negative
{
	return this->rho;
}

double Vector2D::getTheta() const
{
	return this->theta;
}

double Vector2D::getX() const
{
	return this->rho * cos(this->theta * (PI / 180));
}

double Vector2D::getY() const
{
	return this->rho * sin(this->theta * (PI / 180));
}

Vector2D Vector2D::operator+(Vector2D& v)
{
	double x = this->getX() + v.getX();
	double y = this->getY() + v.getY();
	
	double newRho = sqrt(pow(x, 2) + pow(y, 2));
	double newTheta = atan(y / x);

	return Vector2D(newRho, newTheta);
}

Vector2D Vector2D::operator-(Vector2D& v)
{
	double x = this->getX() - v.getX();
	double y = this->getY() - v.getY();

	double newRho = sqrt(pow(x, 2) + pow(y, 2));
	double newTheta = atan(y / x);

	return Vector2D(newRho, newTheta);
}

ostream& Vector2D::operator<<(ostream& os)
{
	os << "Rho: " << this->rho << endl;
	os << "Theta: " << this->theta << endl;
	return os;
}

istream& Vector2D::operator>>(istream& is)
{
	cout << "Enter Rho value: ";
	is >> this->rho;
	cout << "Enter Theta value: ";
	is >> this->theta;
	return is;
}