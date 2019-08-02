#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> visit(nums.size(), 0);
		vector<int> batch;
		vector<vector<int>> res;
		permuteHelper(nums, visit, batch, res, 0);
		return res;
	}
	void permuteHelper(vector<int>& nums, vector<int>& visit, vector<int>& batch, vector<vector<int>>& res, int len)
	{
		if (len == nums.size())
		{
			res.push_back(batch);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visit[i] != 1)
			{
				visit[i] = 1;
				batch.push_back(nums[i]);
				permuteHelper(nums, visit, batch, res, len+1);
				batch.pop_back();
				visit[i] = 0;
			}
		}

	}
};

int main()
{
	vector<int> vec = { 1, 2, 3 };
	Solution sol;
	vector<vector<int>> res = sol.permute(vec);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << '\t';
		}
		cout << endl;
	}
}