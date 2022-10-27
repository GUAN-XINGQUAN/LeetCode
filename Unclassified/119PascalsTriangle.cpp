#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex+1, 0);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
		{
			for (int j = i; j >= 1; j--)
			{
				res[j] += res[j - 1];
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	int rowIndex0 = 0, rowIndex1 = 1, rowIndex2 = 2, rowIndex3 = 3;
	vector<int> res0 = { 1 };
	vector<int> res1 = { 1, 1 };
	vector<int> res2 = { 1, 2, 1 };
	vector<int> res3 = { 1, 3, 3, 1 };

	vector<int> solRes0 = sol.getRow(rowIndex0);
	vector<int> solRes1 = sol.getRow(rowIndex1);
	vector<int> solRes2 = sol.getRow(rowIndex2);
	vector<int> solRes3 = sol.getRow(rowIndex3);

	// Test starts ...
	for (int i = 0; i < res0.size(); i++)
		assert(res0[i] == solRes0[i]);
	for (int i = 0; i < res1.size(); i++)
		assert(res1[i] == solRes1[i]);
	for (int i = 0; i < res2.size(); i++)
		assert(res2[i] == solRes2[i]);
	for (int i = 0; i < res3.size(); i++)
		assert(res3[i] == solRes3[i]);
	cout << "All test cases passed!\n";
}