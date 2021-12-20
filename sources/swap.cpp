#include "../headers/swap.h"

void swap(vector<double>& arr, int a, int b)
{
	double temp = arr.at(a);
	arr.at(a) = arr.at(b);
	arr.at(b) = temp;
}

void swap_rows(vector<vector<double>>& arr, int a, int b)
{
	for (int i = 0; i < arr.size(); i++)
	{
		double temp = arr.at(a).at(i);
		arr.at(a).at(i) = arr.at(b).at(i);
		arr.at(b).at(i) = temp; 
	}
}

void swap_columns(vector<vector<double>>& arr, int a, int b)
{
	for (int i = 0; i < arr.size(); i++)
	{
		double temp = arr.at(i).at(a);
		arr.at(i).at(a) = arr.at(i).at(b);
		arr.at(i).at(b) = temp; 
	}
}