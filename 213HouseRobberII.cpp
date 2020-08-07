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

// Dynamic programing
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
    int helper(vector<int>& nums, int left, int right)
    {
        int robEven = 0, robOdd = 0;
        for (int i = left; i < right; i++)
        {
            if (i % 2 == 0)
                robEven = max(robEven + nums[i], robOdd);
            else
                robOdd = max(robOdd + nums[i], robEven);
        }
        return max(robEven, robOdd);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = { 1, 2, 3, 1 };

    int res = sol.rob(nums);

    cout << res << endl;
    
}