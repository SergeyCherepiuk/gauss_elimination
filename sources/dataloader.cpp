#include "../headers/dataloader.h"

pair<vector<vector<double>>, vector<double>> read_csv(string filename, char separator)
{
	int size;
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "The file has not been open!" << endl;
		return pair<vector<vector<double>>, vector<double>>({ }, { }); // return pair of empty vectors
	}

	file >> size;
	for (int i = 0; i < size + 1; i++)
	{
		file >> separator;
	}

	vector<vector<double>> A(size, vector<double>(size, 0));
	vector<double> B(size, 0);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> A.at(i).at(j);
			file >> separator;
		}
		file >> separator;
		file >> B.at(i);
	}
	file.close();

	return pair<vector<vector<double>>, vector<double>>(A, B);
}