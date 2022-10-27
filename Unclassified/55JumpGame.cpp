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

// greedy algorithm
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > reach || reach >= n - 1)
                break;
            reach = max(reach, i + nums[i]);
        }
        if (reach >= n - 1)
            return true;
        else
            return false;
    }
};


// dynamic programing
// dp[i]: how many capacity do I have when I reach index i.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0)
                return false;
        }
        return true;
    }
};


int main()
{
    Solution sol;

    vector<int> nums = { 2,3,1,1,4 };

    if (sol.canJump(nums))
        cout << "YES\n";
    else
        cout << "NO\n";
}