#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> singleCom;
		sort(candidates.begin(), candidates.end());
		helper(res, singleCom, 0, target, candidates);
		return res;
	}
	void helper(vector<vector<int>> &res, vector<int>& singleCom, int start, int target, vector<int> candidates)
	{
		if (target < 0)
			return;
		if (target == 0)
			res.push_back(singleCom);
		for (int i = start; i < static_cast<int>(candidates.size()); i++)
		{
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			singleCom.push_back(candidates[i]);
			helper(res, singleCom, i + 1, target - candidates[i], candidates);
			singleCom.pop_back();
		}
	}
};


int main()
{
	Solution sol;
	vector<int> candidates = { 1, 2, 3 };
	int target = 2;

	vector<vector<int>> res = sol.combinationSum2(candidates, target);

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << '\t';
		cout << endl;
	}

}