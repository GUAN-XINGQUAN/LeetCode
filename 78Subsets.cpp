#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1:
class Solution
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> returnValue(1);
		sort(nums.begin(), nums.end());
		for (int i = 0; i != nums.size(); i++)
		{
			int size = returnValue.size();
			for (int j = 0; j != size; j++)
			{
				returnValue.push_back(returnValue[j]);
				returnValue.back().push_back(nums[i]);
			}
		}
		return returnValue;
	}
};

int main()
{
	vector<int> vec = { 1 };
	Solution sol;
	vector<vector<int>> ans = sol.subsets(vec);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << '\t';
		cout << endl;
	}
}