// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums(6);

	int buffer;




	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		cout << "Enter next value: ";
		cin >> *it;
	}

	int max = *(nums.begin()), min = *(nums.begin());

	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		if (*it > max)
		{
			max = *it;
		}
		else if(*it < min)
		{
			min = *it;
		}
	}

	cout << "Max: " << max << "\t Min: " << min << endl;
}

