#include "../headers/gauss.h"

bool is_zero(vector<vector<double>> A, int i)
{
	if (abs(A.at(i).at(i)) <= 1e-7)
	{
		cout << "[ERROR]: Zero on the main diagonal!" << endl;
		return true;
	}
	return false;
}

void step(vector<vector<double>>& A, vector<double>& B, int i)
{
	for (int j = i + 1; j < A.size(); j++)
	{
		double k = A.at(j).at(i) / A.at(i).at(i);
		for (int m = 0; m < A.size(); m++)
		{
			A.at(j).at(m) -= k * A.at(i).at(m);
		}
		B.at(j) -= k * B.at(i);
	}
}

vector<double> get_xs(vector<vector<double>> A, vector<double> B)
{
	vector<double> xs;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		double temp_B = B.at(i);
		for (int j = 0; j < xs.size(); j++)
		{
			temp_B -= A.at(i).at(A.size() - 1 - j) * xs.at(j);
		}
		xs.push_back(temp_B / A.at(i).at(i));
	}

	reverse(xs.begin(), xs.end());
	return xs;
}

void row_prepare(vector<vector<double>>& A, vector<double>& history, int i)
{
	int column_index = i;
	double max = A.at(i).at(i);
	for (int j = i; j < A.size(); j++)
	{
		if (abs(A.at(i).at(j)) > abs(max))
		{
			max = A.at(i).at(j);
			column_index = j;
		}
	}

	swap_columns(A, i, column_index);
	swap(history, i, column_index);
}

void column_prepare(vector<vector<double>>& A, vector<double>& B, int i)
{
	int row_index = i;
	double max = A.at(i).at(i);
	for (int j = i; j < A.size(); j++)
	{
		if (abs(A.at(j).at(i)) > abs(max))
		{
			max = A.at(j).at(i);
			row_index = j;
		}
	}

	swap_rows(A, i, row_index);
	swap(B, i, row_index);
}

void full_prepare(vector<vector<double>>& A, vector<double>& B, vector<double>& history, int i)
{
	int row_index = i, column_index = i;
	double max = A.at(i).at(i);
	for (int j = i; j < A.size(); j++)
	{
		for (int k = i; k < A.size(); k++)
		{
			if (abs(A.at(j).at(k)) > abs(max))
			{
				max = A.at(j).at(k);
				row_index = j;
				column_index = k;
			}
		}	
	}
		
	swap_rows(A, i, row_index);
	swap(B, i, row_index);
	swap_columns(A, i, column_index);
	swap(history, i, column_index);
}

vector<double> gauss_without_selection(vector<vector<double>> A, vector<double> B)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (is_zero(A, i))
		{
			vector<double> error(A.size(), 0); 
			return error;
		}
		step(A, B, i);
	}

	if (is_zero(A, A.size() - 1))
	{
		vector<double> error(A.size(), 0); 
		return error;
	}

	return get_xs(A, B);
}

vector<double> gauss_with_row_selection(vector<vector<double>> A, vector<double> B)
{
	vector<double> history;
	for (int i = 0; i < A.size(); i++)
	{
		history.push_back(i);
	}

	for (int i = 0; i < A.size() - 1; i++)
	{
		row_prepare(A, history, i);
		step(A, B, i);
	}

	vector<double> xs = get_xs(A, B);
	sort_xs(xs, history, 0, xs.size() - 1);
	return xs;
}

vector<double> gauss_with_column_selection(vector<vector<double>> A, vector<double> B)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		column_prepare(A, B, i);
		step(A, B, i);
	}

	return get_xs(A, B);
}

vector<double> gauss_with_full_selection(vector<vector<double>> A, vector<double> B)
{
	vector<double> history;
	for (int i = 0; i < A.size(); i++)
	{
		history.push_back(i);
	}

	for (int i = 0; i < A.size() - 1; i++)
	{
		full_prepare(A, B, history, i);
		step(A, B, i);
	}

	vector<double> xs = get_xs(A, B);
	sort_xs(xs, history, 0, xs.size() - 1);
	return xs;
}