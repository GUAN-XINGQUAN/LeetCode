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

// sort
struct cmp {
    bool operator()(pair<int, float> p1, pair<int, float> p2)
    {
        if (p1.second > p2.second)
            return true;
        else
            return false;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        // hash table: points -> distance
        unordered_map<int, double> points2Distance;
        for (int i = 0; i < points.size(); i++)
            points2Distance[i] = computeDistance(points[i]);

        // store results in a heap
        priority_queue<pair<int, float>, vector<pair<int, float>>, cmp> pQ;

        for (auto it : points2Distance)
        {            
            pQ.push(make_pair(it.first, it.second));
        }

        for (int i = 0; i < K; i++)
        {
            auto temp = pQ.top();
            pQ.pop();
            res.push_back(points[temp.first]);
        }

        return res;
    }
    double computeDistance(vector<int> coord)
    {
        int temp = (coord[0] - 0) * (coord[0] - 0) + (coord[1] - 0) * (coord[1] - 0);
        return sqrt(temp);
    }
};

int main()
{
    vector<vector<int>> points = { {3,3}, {5, -1}, {-2, 4} };
    int K = 2;
    Solution sol;
    vector<vector<int>> res = sol.kClosest(points, K);

    nestedVectorIntVisualization(res);
}