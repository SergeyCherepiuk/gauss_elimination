#include "../headers/dataloader.h"
#include "../headers/gauss.h"
#include "../headers/print.h"

using namespace std;

void example1(string filename)
{
	cout << "Gauss without selection:" << endl;
	pair<vector<vector<double>>, vector<double>> data = read_csv(filename, ';');
	vector<vector<double>> A = data.first;
	vector<double> B = data.second;
	print_xs(gauss_without_selection(A, B));
	cout << endl;
}

void example2(string filename)
{
	cout << "Gauss with row selection:" << endl;
	pair<vector<vector<double>>, vector<double>> data = read_csv(filename, ';');
	vector<vector<double>> A = data.first;
	vector<double> B = data.second;
	print_xs(gauss_with_row_selection(A, B));
	cout << endl;
}

void example3(string filename)
{
	cout << "Gauss with column selection:" << endl;
	pair<vector<vector<double>>, vector<double>> data = read_csv(filename, ';');
	vector<vector<double>> A = data.first;
	vector<double> B = data.second;
	print_xs(gauss_with_column_selection(A, B));
	cout << endl;
}

void example4(string filename)
{
	cout << "Gauss with full selection:" << endl;
	pair<vector<vector<double>>, vector<double>> data = read_csv(filename, ';');
	vector<vector<double>> A = data.first;
	vector<double> B = data.second;
	print_xs(gauss_with_full_selection(A, B));
	cout << endl;
}

int main()
{
	example1("../data/data1.csv"); // expected xs [-1, -1, 1, -1]
	example2("../data/data2.csv"); // expected xs [-1, -1, 1, 1]
	example3("../data/data3.csv"); // expected xs [0, -1, -2, 0]
	example4("../data/data4.csv"); // expected xs [2, 1, 0, -2, 2]
	example4("../data/data5.csv"); // expected xs [0.290476, 19.6905, 1.08571]

	return 0;
}