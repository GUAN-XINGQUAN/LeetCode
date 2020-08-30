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
    bool operator()(vector<int> v1, vector<int> v2)
    {
        return v1[1] < v2[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // corner case
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(), cmp());

        int res = 1, last = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > last)
            {
                last = points[i][1];
                res++;
            }
        }
        return res;
    }
};


int main()
{
    Solution sol;

    vector<vector<int>> points = { {1,2}, {3, 4}, {5,6}, {7,8} };
    int res = sol.findMinArrowShots(points);

    cout << res << endl;
}