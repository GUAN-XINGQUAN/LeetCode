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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visit(n, false);
        vector<int> out;
        vector<vector<int>> res;
        DFS(nums, 0, visit, out, res);
        return res;
    }
    void DFS(vector<int>& nums, int level, vector<bool>& visit, vector<int>& out, vector<vector<int>>& res)
    {
        // base case
        if (level >= nums.size())
        {
            res.push_back(out);
            return;
        }
        // recursive case
        for (int i = 0; i < nums.size(); i++)
        {
            if (visit[i] == true)
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == false)
                continue;
            visit[i] = true;
            out.push_back(nums[i]);

            // Add to visualize the recursion
            //cout << "Level = " << level << '\t' << "i = " << i << endl;
            //if (out.empty())
            //    cout << "Empty\n";
            //else
            //{
            //    for (int i = 0; i < out.size(); i++)
            //        cout << out[i] << '\t';
            //}
            //cout << endl;
            // end of visualization


            DFS(nums, level + 1, visit, out, res);
            out.pop_back();
            visit[i] = false;
        }
    }
};

int main()
{
    vector<int> nums = { 3, 3, 0, 3 };
    Solution sol;

    vector<vector<int>> res = sol.permuteUnique(nums);

    nestedVectorIntVisualization(res);
}