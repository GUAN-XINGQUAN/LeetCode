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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> res;
        DFS(candidates, target, 0, out, res);
        return res;

    }
    void DFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res)
    {
        // base case
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(out);
            return;
        }
        // recursive case
        for (int i = start; i < candidates.size(); i++)
        {
            out.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = { 2,3,5 };
    int target = 8;
    Solution sol;

    vector<vector<int>> res = sol.combinationSum(candidates, target);

    nestedVectorIntVisualization(res);
}