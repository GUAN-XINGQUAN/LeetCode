#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"

using namespace std;

struct cmp {
    bool operator() (vector<int> v1, vector<int> v2)
    {
        if (v1[0] < v2[0])
            return true;
        else
            return false;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(), cmp());
        vector<vector<int>> res({ intervals[0] });
        for (int i = 1; i < intervals.size(); i++)
        {
            // two intervals share no intervals
            if (res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            // two intervals have overlaps
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> intervals = { {1,3}, {2,6},{8,10},{15,18} };
    vector<vector<int>> res = sol.merge(intervals);

    nestedVectorIntVisualization(res);
}