#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
#include "treeVisualizationinPreorder.h"
#include "listNodeVisualization.h"

using namespace std;

struct cmp 
{
    bool operator()(vector<int> vec1, vector<int> vec2)
    {
        return vec1[1] < vec2[1];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), cmp());
        int res = 1, last = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= last)
            {
                res++;
                last = intervals[i][1];
            }
        }
        int residual = intervals.size() - res;
        return residual;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> intervals = { {1,2}, {2,3} };

    int res = sol.eraseOverlapIntervals(intervals);

    cout << res << endl;
}