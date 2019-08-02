#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> batch;
		combinationSumHelper(candidates, target, 0, batch, res);
		return res;
	}
	void combinationSumHelper(vector<int>& candidates, int target, int startIndex, vector<int>& batch,
		vector<vector<int>>& res)
	{
		if (target < 0)
			return;
		if (target == 0)
		{
			res.push_back(batch);
			return;
		}
		for (int i = startIndex; i <= candidates.size() - 1; i++)
		{
			batch.push_back(candidates[i]);
			combinationSumHelper(candidates, target - candidates[i], i, batch, res);
			batch.pop_back();
		}
	}

};

int main()
{
	vector<int> vec = { 2, 3, 6, 7 };
	int target = 7;
	Solution sol;
	vector<vector<int>> res = sol.combinationSum(vec, target);
	for (int i = 0; i <= res.size() - 1; i++)
	{
		for (int j = 0; j <= res[i].size() - 1; j++)
		{
			cout << res[i][j];
		}
		cout << endl;
	}
}