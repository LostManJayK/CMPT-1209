#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;

class Rational
{
	private:
		int numerator;
		int denominator;
	public:
		//Constructors
		Rational();
		Rational(int, int denom = 1);

		//Deconstructor
		~Rational();

		//IO & Validation
		void input();
		void reduce();

		//Mutators
		void setNumerator(int);
		void setDenominator(int);

		//Accessors
		int getNumerator();
		int getDenominator();
		void getRatio();


};

#endif
