#include <iostream>

#include "Numbers.h"

Numbers::Numbers()
{
	this->number = 0;
}

string Numbers::lessThan20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
									"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", };

string Numbers::tens[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",};

string Numbers::hundred = "hundred";

string Numbers::thousand = "thousand";



Numbers::Numbers(int num)
{
	this->number = num;
}

void Numbers::setNumner(int num)
{
	this->number = num;
}
int Numbers::getNumber()
{
	return this->number;
}

string Numbers::print()
{
	int digits[4] = { 0,0,0,0 };

	if (this->number < 20)
	{
		cout << Numbers::lessThan20[this->number];
	}

	else
	{
		for (int i = 0; i < 4; i++)
		{

		}
		digits
	}
}