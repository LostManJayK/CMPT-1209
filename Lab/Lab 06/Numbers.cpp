#include <iostream>
#include <cmath>

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

void Numbers::print() const
{
	int temp = this->number;

	int digits[4] = {0, 0, 0, 0};

	//Case for numbers less than 20
	if (this->number < 20)
	{
		cout << Numbers::lessThan20[this->number] << endl;
	}
	else
	{
		//Create list of digits
		for (int i = 0; i < 4; i++)
		{
			*(digits + i) = temp / pow(10, (3-i));
			temp %= (int)pow(10, (3-i));
		}

		//Print based on digits
		for(int i = 0; i < 4; i++)
		{
			if(digits[i] != 0) //Exclude zero as it wouldn't be stated
			{

				switch(i)
				{
					case 0:
						cout << Numbers::lessThan20[digits[i]] << " ";
						cout << Numbers::thousand << " ";
						break;
					case 1:
						cout << Numbers::lessThan20[digits[i]] << " ";
						cout << Numbers::hundred << " ";
						break;
					case 2:
						cout << Numbers::tens[digits[i]] << " ";
						break;
					case 3:
						cout << Numbers::lessThan20[digits[i]] << endl;

				}
			}
		}
	}
}