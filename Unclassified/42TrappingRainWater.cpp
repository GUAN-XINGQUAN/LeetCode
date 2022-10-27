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
#include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// Dynamic programing
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;

        int n = height.size();
        vector<int> dpLeftRight(n, 0);
        vector<int> dpRightLeft(n, 0);
        vector<int> dp(n, 0);
        // from left to right
        dpLeftRight[0] = height[0];
        for (int i = 1; i < n; i++)
            dpLeftRight[i] = max(dpLeftRight[i - 1], height[i]);
        // from right to left
        dpRightLeft[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            dpRightLeft[i] = max(dpRightLeft[i + 1], height[i]);
        // select the minimum one
        for (int i = 0; i < n; i++)
            dp[i] = min(dpLeftRight[i], dpRightLeft[i]);
        // compute the rain volume
        int res = 0;
        for (int i = 0; i < n; i++)
            res += dp[i] - height[i];
        return res;
    }
};


int main()
{
    Solution sol;
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int res = sol.trap(height);

    cout << res << endl;
}