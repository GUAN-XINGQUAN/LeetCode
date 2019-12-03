#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++)
		{
			for (int each : nums)
			{
				if (i >= each)
					dp[i] = dp[i] + dp[i - each];
			}
		}
		return dp.back();
	}
};


int main()
{
	vector<int> nums = { 1, 2, 3 };
	int target = 4;
	Solution sol;

	cout << "The final result is: " << sol.combinationSum4(nums, target) << endl;
}