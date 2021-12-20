#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

pair<vector<vector<double>>, vector<double>> read_csv(string filename, char separator);