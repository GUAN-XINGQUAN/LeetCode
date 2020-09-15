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

// Approach 1: non-recursive solution
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // empty set is a subset of any set
        vector<vector<int>> res;
        res.push_back({});

        for (int i = 0; i < nums.size(); i++)
        {
            int n = res.size();
            for (int j = 0; j < n; j++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};


// Approach 2: recursive solution: DFS
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> out;
        vector<vector<int>> res;
        DFSHelper(nums, 0, out, res);
        return res;
    }
    void DFSHelper(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res)
    {
        // no base case
        res.push_back(out);

        for (int i = start; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            DFSHelper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> res = sol.subsets(nums);
    nestedVectorIntVisualization(res);
}