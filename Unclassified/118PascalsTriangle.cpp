#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows, vector<int>());
		for (int i = 0; i < numRows; i++)
		{
			res[i].resize(i + 1, 1);
			for (int j = 1; j < i; j++)
			{
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	int numRows = 4;
	vector<vector<int>> res;
	res.push_back({ 1 });
	res.push_back({ 1, 1 });
	res.push_back({ 1, 2, 1 });
	res.push_back({ 1, 3, 3, 1 });

	vector<vector<int>> solRes = sol.generate(numRows);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			assert(res[i][j] == solRes[i][j]);
		}
	}
	cout << "All test cases passed!\n";
}