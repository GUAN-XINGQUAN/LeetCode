#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

// DFS
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n, false);
        vector<int> out;
        vector<vector<int>> res;
        DFS(nums, 0, visit, out, res);
        return res;
    }
    void DFS(vector<int>& nums, int count, vector<bool>& visit, vector<int>& out, vector<vector<int>>& res)
    {
        // base case
        if (count == nums.size())
        {
            res.push_back(out);
            return;
        }
        // recursive case
        for (int i = 0; i < nums.size(); i++)
        {
            if (visit[i] == true)
                continue;
            visit[i] = true;
            out.push_back(nums[i]);
            DFS(nums, count + 1, visit, out, res);
            out.pop_back();
            visit[i] = false;
        }
    }
};

int main()
{
    vector<int> nums = { 1,2,3 };
    Solution sol;

    vector<vector<int>> res = sol.permute(nums);
    
    nestedVectorIntVisualization(res);
}