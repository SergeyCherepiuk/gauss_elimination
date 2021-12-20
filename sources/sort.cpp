#include "../headers/sort.h"

int partition(vector<double>& xs, vector<double>& history, int low, int high)
{
    int pivot = history.at(high);
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (history.at(j) <= pivot)
        {
            i++;
            swap(history, i, j);
			swap(xs, i, j);
        }
    }
    
    swap(history, i + 1, high);
    swap(xs, i + 1, high);
    return (i + 1);
}
 
void sort_xs(vector<double>& xs, vector<double>& history, int low, int high)
{
    if (low < high)
    {
        int pi = partition(xs, history, low, high); // partitioning index
 		sort_xs(xs, history, low, pi - 1);
        sort_xs(xs, history, pi + 1, high);
    }
}