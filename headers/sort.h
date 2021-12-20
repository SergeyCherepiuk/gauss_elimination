#pragma once
#include <vector>
#include "swap.h"

using namespace std;

int partition(vector<double>& xs, vector<double>& history, int low, int high);
void sort_xs(vector<double>& xs, vector<double>& history, int low, int high);