#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>

using namespace std;

class Numbers
{
	private:
		int number;
		static string lessThan20[20];
		static string tens[10];
		static string hundred;
		static string thousand;
		

	public:
		Numbers();
		Numbers(int);

		void setNumner(int);
		int getNumber();



		string print();

};

#endif
