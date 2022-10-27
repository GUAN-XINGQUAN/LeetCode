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

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), curInt = 0;
        while (curInt < n && intervals[curInt][1] < newInterval[0])
            res.push_back(intervals[curInt++]);
        while (curInt < n && intervals[curInt][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[curInt][0]);
            newInterval[1] = max(newInterval[1], intervals[curInt][1]);
            curInt++;
        }
        res.push_back(newInterval);
        while (curInt < n)
            res.push_back(intervals[curInt++]);
        return res;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> intervals = { {1,3},{6,9} };
    vector<int> newInterval = { 2, 5 };

    vector<vector<int>> res = sol.insert(intervals, newInterval);

    nestedVectorIntVisualization(res);
}