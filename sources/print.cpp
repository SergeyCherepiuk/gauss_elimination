#include "../headers/print.h"

void print_1d(vector<double> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << " ";
	}
	cout << endl;
}

void print_2d(vector<vector<double>> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			cout << arr.at(i).at(j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_xs(vector<double> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << "x" << i + 1 << " = " << arr.at(i) << endl;
	}
}