#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Use dynamic programming
class Solution {
public:
	int climbStairs(int n)
	{
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		vector<int> dp(n + 1, 1);
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp.back();
	}
};

int main()
{
	int n = 4;
	Solution sol;

	cout << "The final answer is: " << sol.climbStairs(n);
}