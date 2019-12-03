#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		dp[0] = 1;
		sort(nums.begin(), nums.end());
		for (int i = 1; i <= target; i++)
		{
			for (auto each : nums)
			{
				if (i < each)
					break;
				dp[i] = dp[i] + dp[i - each];
			}
		}
		return dp.back();
	}
};


int main()
{
	vector<int> nums = { 3, 33, 333 };
	int target = 10000;
	Solution sol;

	cout << "The final result is: " << sol.combinationSum4(nums, target) << endl;
}