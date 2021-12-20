#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "sort.h"
#include "swap.h"

using namespace std;

bool is_zero(vector<vector<double>> A, int i);
void step(vector<vector<double>>& A, vector<double>& B, int i);
vector<double> get_xs(vector<vector<double>> A, vector<double> B);
void row_prepare(vector<vector<double>>& A, vector<double>& B, vector<double>& history, int i);
void column_prepare(vector<vector<double>>& A, vector<double>& B, int i);
void full_prepare(vector<vector<double>>& A, vector<double>& B, vector<double>& history, int i);
vector<double> gauss_without_selection(vector<vector<double>> A, vector<double> B);
vector<double> gauss_with_row_selection(vector<vector<double>> A, vector<double> B);
vector<double> gauss_with_column_selection(vector<vector<double>> A, vector<double> B);
vector<double> gauss_with_full_selection(vector<vector<double>> A, vector<double> B);