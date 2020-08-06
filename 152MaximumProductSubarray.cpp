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
// h[i]: max product for 0-i including nums[i]
// l[i]: min product for 0-i including nums[i]

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size(), res = nums[0];
        vector<int> h(n, 0);
        vector<int> l(n, 0);
        h[0] = l[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            h[i] = max(nums[i] * h[i - 1], max(nums[i] * l[i - 1], nums[i]));
            l[i] = min(nums[i] * h[i - 1], min(nums[i] * l[i - 1], nums[i]));
            res = max(res, h[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> vec = { 2, 3, -2, 4 };

    int res = sol.maxProduct(vec);

    cout << res << endl;
}