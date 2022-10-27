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

// DFS
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        DFSHelper(nums, 0, out, res);
        return res;
    }
    void DFSHelper(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res)
    {
        res.push_back(out);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            out.push_back(nums[i]);
            DFSHelper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1,2,2 };
    vector<vector<int>> res = sol.subsetsWithDup(nums);
    nestedVectorIntVisualization(res);
}