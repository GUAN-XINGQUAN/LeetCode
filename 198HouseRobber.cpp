#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// dynamic programing
// dp[i] = max(dp[i-2] + nums[i], dp[i-1])
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp.back();
    }
};

int main()
{
    Solution sol;

    vector<int> nums = { 1, 2, 3, 1 };

    int res = sol.rob(nums);

    cout << res << endl;
    
}