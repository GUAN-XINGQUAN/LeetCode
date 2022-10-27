#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        vector<int> out;
        vector<vector<int>> res;
        DFSHelper(k, n, 0, nums, out, res);
        return res;
    }
    void DFSHelper(int k, int n, int start,
        vector<int>& nums, vector<int>& out, vector<vector<int>>& res)
    {
        // base case
        if (n < 0)
            return;
        if (k == 0 && n != 0)
            return;
        if (k == 0 && n == 0)
        {
            res.push_back(out);
            return;
        }

        // recursion
        for (int i = start; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            DFSHelper(k - 1, n - nums[i], i+1, nums, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    int k = 4, n = 1;

    vector<vector<int>> res = sol.combinationSum3(k, n);
    nestedVectorIntVisualization(res);
}