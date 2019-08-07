#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		for (int i = 0; i < row/2; i++)
		{
			for (int j = i; j < row-1-i; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[row - 1 - j][i];
				matrix[row - 1 - j][i] = matrix[row - i - 1][row - 1 - j];
				matrix[row - i - 1][row - 1 - j] = matrix[j][row - i - 1];
				matrix[j][row - 1 - i] = temp;
			}
		}
	}
};

int main()
{
	vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	Solution sol;
	sol.rotate(matrix);
	cout << "******************************\n";
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
}